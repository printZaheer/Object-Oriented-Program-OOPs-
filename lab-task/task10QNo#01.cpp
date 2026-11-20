#include <iostream>
#include <cmath>
using namespace std;
class SmartDevice
{
protected:
    string name;
    double hours;

public:
    SmartDevice(string n, double h)
    {
        name = n;
        hours = h;
    }
    virtual double computePower() = 0;
    virtual void display()
    {
        cout << name << " uses " << computePower() << " W, energy = " << computePower() * hours / 1000 << " kWh" << endl;
    }
    virtual ~SmartDevice() {}
};
class SmartThermostat : public SmartDevice
{
    double currentTemp;
    double targetTemp;

public:
    SmartThermostat(string n, double c, double t, double h) : SmartDevice(n, h)
    {
        currentTemp = c;
        targetTemp = t;
    }
    double computePower()
    {
        return 50 + 40 * fabs(targetTemp - currentTemp);
    }
};
class SmartLight : public SmartDevice
{
    double watts;
    int brightness;

public:
    SmartLight(string n, double w, int b, double h) : SmartDevice(n, h)
    {
        watts = w;
        brightness = b;
    }
    double computePower()
    {
        return watts * brightness / 100;
    }
};
int main()
{
    SmartDevice *devices[3];
    devices[0] = new SmartThermostat("Thermostat", 18, 24, 8);
    devices[1] = new SmartLight("Kitchen Light", 60, 80, 5);
    devices[2] = new SmartLight("Bedroom Light", 40, 30, 6);
    for (int i = 0; i < 3; i++)
    {
        devices[i]->display();
    }
    for (int i = 0; i < 3; i++)
    {
        delete devices[i];
    }
    return 0;
}