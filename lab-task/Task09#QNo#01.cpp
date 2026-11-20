#include <iostream>
#include <string>
using namespace std;
class PatientRecord{
protected:
    double *vitalsHistory;
    int logCount;

public:
    PatientRecord(double vitals[], int count){
        logCount = count;
        vitalsHistory = new double[logCount];
        for (int i = 0; i < logCount; i++)
        {
            vitalsHistory[i] = vitals[i];
        }
    }
    PatientRecord(const PatientRecord &other){
        logCount = other.logCount;
        vitalsHistory = new double[logCount];
        for (int i = 0; i < logCount; i++)
        {
            vitalsHistory[i] = other.vitalsHistory[i];
        }
    }
    PatientRecord &operator=(const PatientRecord &other){
        if (this == &other){
            return *this;
        }
        delete[] vitalsHistory;
        logCount = other.logCount;
        vitalsHistory = new double[logCount];
        for (int i = 0; i < logCount; i++)
        {
            vitalsHistory[i] = other.vitalsHistory[i];
        }
        return *this;
    }
    virtual ~PatientRecord(){
        delete[] vitalsHistory;
        cout << "PatientRecord destructor called" << endl;
    }
    double *getVitalsAddress() { return vitalsHistory; }
};
class ICUPatientRecord : public PatientRecord{
private:
    string *alertMessages;
    int alertCount;
    int severityLevel;

public:
    ICUPatientRecord(double vitals[], int count) : PatientRecord(vitals, count){
        alertMessages = NULL;
        alertCount = 0;
        severityLevel = 0;
    }
    ICUPatientRecord(const ICUPatientRecord &other) : PatientRecord(other){
        alertCount = other.alertCount;
        severityLevel = other.severityLevel;
        alertMessages = new string[alertCount];
        for (int i = 0; i < alertCount; i++)
        {
            alertMessages[i] = other.alertMessages[i];
        }
    }
    ICUPatientRecord &operator=(const ICUPatientRecord &other){
        if (this == &other)
        {
            return *this;
        }
        PatientRecord::operator=(other);
        delete[] alertMessages;
        alertCount = other.alertCount;
        severityLevel = other.severityLevel;
        alertMessages = new string[alertCount];
        for (int i = 0; i < alertCount; i++)
        {
            alertMessages[i] = other.alertMessages[i];
        }
        return *this;
    }
    ~ICUPatientRecord(){
        delete[] alertMessages;
        cout << "ICUPatientRecord destructor called" << endl;
    }
    void addAlert(string msg){
        string *newArray = new string[alertCount + 1];
        for (int i = 0; i < alertCount; i++)
        {
            newArray[i] = alertMessages[i];
        }
        newArray[alertCount] = msg;
        delete[] alertMessages;
        alertMessages = newArray;
        alertCount++;
    }
    void evaluateEmergencyStatus(){
        for (int i = 0; i < logCount; i++)
        {
            if (vitalsHistory[i] < 60 || vitalsHistory[i] > 100)
            {
                addAlert("Abnormal heart rate " + to_string((int)vitalsHistory[i]) + " at log " + to_string(i));
                severityLevel++;
            }
        }
    }
    void display(){
        cout << "Severity level: " << severityLevel << endl;
        for (int i = 0; i < alertCount; i++)
        {
            cout << "  Alert: " << alertMessages[i] << endl;
        }
    }
    string *getAlertsAddress() { return alertMessages; }
};
int main(){
    double hr[] = {72, 55, 88, 110, 95, 40};
    ICUPatientRecord p1(hr, 6);
    p1.evaluateEmergencyStatus();
    cout << "Original patient:" << endl;
    p1.display();
    ICUPatientRecord p2(p1);
    cout << "\nCopied patient:" << endl;
    p2.display();
    if (p1.getVitalsAddress() != p2.getVitalsAddress() && p1.getAlertsAddress() != p2.getAlertsAddress())
    {
        cout << "\nDeep copy works: arrays are at different addresses" << endl;
    }
    p2.addAlert("Extra alert only in copy");
    cout << "\nOriginal after changing the copy:" << endl;
    p1.display();
    cout << "\nCopy after change:" << endl;
    p2.display();
    cout << endl;
    return 0;
}
