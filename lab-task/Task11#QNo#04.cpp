#include <iostream>
using namespace std;
class Polynomial {
    double* coeffs;
    int degree;
public:
    Polynomial(int deg, const double* initCoeffs) {
        degree = deg;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; i++) coeffs[i] = initCoeffs[i];
    }
    Polynomial(const Polynomial& p) {
        degree = p.degree;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; i++) coeffs[i] = p.coeffs[i];
    }
    ~Polynomial() { delete[] coeffs; }
    Polynomial& operator=(const Polynomial& rhs) {
        if (this == &rhs) return *this;
        delete[] coeffs;
        degree = rhs.degree;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; i++) coeffs[i] = rhs.coeffs[i];
        return *this;
    }
    Polynomial operator+(const Polynomial& rhs) const {
        int d = degree > rhs.degree ? degree : rhs.degree;
        double* t = new double[d + 1];
        for (int i = 0; i <= d; i++) {
            t[i] = 0;
            if (i <= degree) t[i] += coeffs[i];
            if (i <= rhs.degree) t[i] += rhs.coeffs[i];
        }
        Polynomial res(d, t);
        delete[] t;
        return res;
    }
    Polynomial operator-(const Polynomial& rhs) const {
        int d = degree > rhs.degree ? degree : rhs.degree;
        double* t = new double[d + 1];
        for (int i = 0; i <= d; i++) {
            t[i] = 0;
            if (i <= degree) t[i] += coeffs[i];
            if (i <= rhs.degree) t[i] -= rhs.coeffs[i];
        }
        Polynomial res(d, t);
        delete[] t;
        return res;
    }
    Polynomial operator*(double k) const {
        double* t = new double[degree + 1];
        for (int i = 0; i <= degree; i++) t[i] = coeffs[i] * k;
        Polynomial res(degree, t);
        delete[] t;
        return res;
    }
    friend Polynomial operator*(double k, const Polynomial& p) { return p * k; }
    double operator()(double x) const {
        double result = 0, power = 1;
        for (int i = 0; i <= degree; i++) {
            result += coeffs[i] * power;
            power *= x;
        }
        return result;
    }
    friend ostream& operator<<(ostream& out, const Polynomial& p) {
        bool first = true;
        for (int i = p.degree; i >= 0; i--) {
            double c = p.coeffs[i];
            if (c == 0) continue;
            if (c < 0) out << (first ? "-" : " - ");
            else if (!first) out << " + ";
            if (c < 0) c = -c;
            if (c != 1 || i == 0) out << c;
            if (i >= 1) out << "x";
            if (i >= 2) out << "^" << i;
            first = false;
        }
        if (first) out << "0";
        return out;
    }
};
int main() {
    int d1, d2;
    double k, x;
    cout << "Degree of P1: ";
    cin >> d1;
    double* c1 = new double[d1 + 1];
    cout << "Coefficients of P1 (x^0 first): ";
    for (int i = 0; i <= d1; i++) cin >> c1[i];
    cout << "Degree of P2: ";
    cin >> d2;
    double* c2 = new double[d2 + 1];
    cout << "Coefficients of P2 (x^0 first): ";
    for (int i = 0; i <= d2; i++) cin >> c2[i];
    cout << "Scalar: ";
    cin >> k;
    Polynomial P1(d1, c1), P2(d2, c2);
    cout << "P1 = " << P1 << endl;
    cout << "P2 = " << P2 << endl;
    cout << "P1 + P2 = " << P1 + P2 << endl;
    cout << "P1 - P2 = " << P1 - P2 << endl;
    cout << "P1 * scalar = " << P1 * k << endl;
    cout << "scalar * P1 = " << k * P1 << endl;
    Polynomial P3 = (k * P1) + P2;
    cout << "P3 = " << P3 << endl;
    cout << "Value of x: ";
    cin >> x;
    cout << "P3(" << x << ") = " << P3(x) << endl;
    delete[] c1;
    delete[] c2;
    return 0;
}
