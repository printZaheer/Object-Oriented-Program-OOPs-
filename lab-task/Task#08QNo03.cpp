#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}
    Time& setHour(int h) {
        hour = h;
        return *this;
    }
    Time& setMinute(int m) {
        minute = m;
        return *this;
    }
    Time& setSecond(int s) {
        second = s;
        return *this;
    }
    void print() const {
        cout << setfill('0')
             << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << endl;
    }
};
int main() {
    Time t;
    t.setHour(10).setMinute(30).setSecond(0);
    cout << "Time: ";
    t.print();
    return 0;
}
