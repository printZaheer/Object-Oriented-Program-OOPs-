#include <iostream>
#include <iomanip>
using namespace std;
class Timestamp {
    int hours, minutes, seconds;
    int total() const {
	return hours * 3600 + minutes * 60 + seconds;
	}
public:
    Timestamp(int h = 0, int m = 0, int s = 0) {
        if (h < 0) h = 0;
        if (m < 0) m = 0;
        if (s < 0) s = 0;
        m += s / 60;
        s = s % 60;
        h += m / 60;
        m = m % 60;
        hours = h % 24;
        minutes = m;
        seconds = s;
    }
    bool operator<(const Timestamp& rhs) const {
	return total() < rhs.total();
	}
    bool operator>(const Timestamp& rhs) const {
	return total() > rhs.total();
	}
    bool operator==(const Timestamp& rhs) const {
	return total() == rhs.total();
	}
    long operator-(const Timestamp& rhs) const {
	return total() - rhs.total();
	}
    friend istream& operator>>(istream& in, Timestamp& t) {
        int h, m, s;
        in >> h >> m >> s;
        t = Timestamp(h, m, s);
        return in;
    }
    friend ostream& operator<<(ostream& out, const Timestamp& t) {
        out << setfill('0') << setw(2) << t.hours << ":" << setw(2) << t.minutes << ":" << setw(2) << t.seconds << setfill(' ');
        return out;
    }
};
int main() {
    Timestamp t1, t2;
    cout << "Enter two times (HH MM SS HH MM SS): ";
    cin >> t1 >> t2;
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
    if (t1 < t2) cout << "t1 is earlier" << endl;
    else if (t1 > t2) cout << "t2 is earlier" << endl;
    else cout << "Both are same" << endl;
    cout << "Seconds between (t2 - t1): " << t2 - t1 << endl;
    return 0;
}
