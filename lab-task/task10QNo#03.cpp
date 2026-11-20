#include <iostream>
using namespace std;
class VehicleSensor {
protected:
    double x, y, z;
public:
    VehicleSensor(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
        cout << "VehicleSensor constructor" << endl;
    }
    void setCalibration(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
    void showCalibration() {
        cout << "Calibration: " << x << " " << y << " " << z << endl;
    }
    virtual ~VehicleSensor() {}
};
class LidarSensor : virtual public VehicleSensor {
public:
    LidarSensor(double a, double b, double c) : VehicleSensor(a, b, c) {
        cout << "LidarSensor constructor" << endl;
    }
    void scan() {
        cout << "Lidar scanning" << endl;
    }
};
class CameraSensor : virtual public VehicleSensor {
public:
    CameraSensor(double a, double b, double c) : VehicleSensor(a, b, c) {
        cout << "CameraSensor constructor" << endl;
    }
    void capture() {
        cout << "Camera capturing" << endl;
    }
};
class FusionModule : public LidarSensor, public CameraSensor {
public:
    FusionModule(double a, double b, double c) : VehicleSensor(a, b, c), LidarSensor(a, b, c), CameraSensor(a, b, c) {
        cout << "FusionModule constructor" << endl;
    }
    void fuse() {
        scan();
        capture();
        cout << "Data fused" << endl;
    }
};
int main() {
    FusionModule f(1.5, 2, 0.8);
    f.fuse();
    f.showCalibration();
    VehicleSensor* v1 = (LidarSensor*)&f;
    VehicleSensor* v2 = (CameraSensor*)&f;
    cout << v1 << endl;
    cout << v2 << endl;
    if (v1 == v2) {
        cout << "Only one VehicleSensor object" << endl;
    }
    f.setCalibration(9, 9, 9);
    f.showCalibration();
    return 0;
}
