#include <iostream>
using namespace std;
class RadarSystem {
protected:
    double targetDistance;
    double targetAzimuth;
public:
    RadarSystem(double d, double a) {
        targetDistance = d;
        targetAzimuth = a;
    }
    void renderDisplay() {
        cout << "Radar sweep -> distance: " << targetDistance << ", azimuth: " << targetAzimuth << endl;
    }
};
class NavigationSystem {
protected:
    double gpsLatitude;
    double gpsLongitude;
public:
    NavigationSystem(double lat, double lon) {
        gpsLatitude = lat;
        gpsLongitude = lon;
    }
    void renderDisplay() {
        cout << "Terrain map grid -> latitude: " << gpsLatitude << ", longitude: " << gpsLongitude << endl;
    }
};
class HeadsUpDisplay : public RadarSystem, public NavigationSystem {
private:
    bool nightVisionActive;
public:
    HeadsUpDisplay(double d, double a, double lat, double lon, bool nv)
        : RadarSystem(d, a), NavigationSystem(lat, lon) {
        nightVisionActive = nv;
    }
    void renderDisplay() {
        cout << "--- HUD Display ---" << endl;
        if (nightVisionActive) {
            cout << "Night vision is ON" << endl;
        }
        RadarSystem::renderDisplay();
        NavigationSystem::renderDisplay();
    }
    void renderTacticalOverlay(bool radarMode, bool navMode) {
        if (radarMode) {
            RadarSystem::renderDisplay();
        }
        if (navMode) {
            NavigationSystem::renderDisplay();
        }
        if (!radarMode && !navMode) {
            cout << "No mode selected" << endl;
        }
    }
};
int main() {
    HeadsUpDisplay hud(42.5, 135.0, 34.01, 71.52, true);
    hud.renderDisplay();
    cout << "\nCalling base versions directly:" << endl;
    hud.RadarSystem::renderDisplay();
    hud.NavigationSystem::renderDisplay();
    cout << "\nOverlay (radar only):" << endl;
    hud.renderTacticalOverlay(true, false);
    cout << "\nOverlay (navigation only):" << endl;
    hud.renderTacticalOverlay(false, true);
    cout << "\nOverlay (both):" << endl;
    hud.renderTacticalOverlay(true, true);
    return 0;
}
