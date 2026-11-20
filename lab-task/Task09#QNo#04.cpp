#include <iostream>
#include <string>
using namespace std;
class VehicleNode {
protected:
    string vehicleVIN;
    double operationalHours;
public:
    VehicleNode(string vin, double hours) {
        vehicleVIN = vin;
        operationalHours = hours;
        cout << "VehicleNode constructor called" << endl;
    }
};
class ElectricVehicle : virtual public VehicleNode {
protected:
    double batteryLevelCapacity;
public:
    ElectricVehicle(string vin, double hours, double battery) : VehicleNode(vin, hours) {
        batteryLevelCapacity = battery;
        cout << "ElectricVehicle constructor called" << endl;
    }
};
class AutonomousVehicle : virtual public VehicleNode {
protected:
    string sensorSuiteVersion;
public:
    AutonomousVehicle(string vin, double hours, string sensor) : VehicleNode(vin, hours) {
        sensorSuiteVersion = sensor;
        cout << "AutonomousVehicle constructor called" << endl;
    }
};
class AutonomousElectricTruck : public ElectricVehicle, public AutonomousVehicle {
public:
    AutonomousElectricTruck(string vin, double hours, double battery, string sensor)
        : VehicleNode(vin, hours), ElectricVehicle(vin, hours, battery), AutonomousVehicle(vin, hours, sensor) {
        cout << "AutonomousElectricTruck constructor called" << endl;
    }
    void generateFleetReport() {
        cout << "\n--- Fleet Report ---" << endl;
        cout << "VIN: " << vehicleVIN << endl;
        cout << "Operational hours: " << operationalHours << endl;
        cout << "Battery capacity: " << batteryLevelCapacity << endl;
        cout << "Sensor version: " << sensorSuiteVersion << endl;
    }
};
int main() {
    AutonomousElectricTruck truck("1HGCM82633A004352", 1250.5, 300, "LiDAR-v4.2");
    truck.generateFleetReport();
    cout << "\nsizeof(VehicleNode) = " << sizeof(VehicleNode) << endl;
    cout << "sizeof(ElectricVehicle) = " << sizeof(ElectricVehicle) << endl;
    cout << "sizeof(AutonomousVehicle) = " << sizeof(AutonomousVehicle) << endl;
    cout << "sizeof(AutonomousElectricTruck) = " << sizeof(AutonomousElectricTruck) << endl;
    cout << "The truck contains only one VehicleNode, not two." << endl;
    return 0;
}
