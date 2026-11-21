#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
class Matrix {
    double** grid;
    int rows, cols;
    void create() {
        grid = new double*[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new double[cols];
            for (int j = 0; j < cols; j++) grid[i][j] = 0.0;
        }
    }
    void destroy() {
        for (int i = 0; i < rows; i++) delete[] grid[i];
        delete[] grid;
    }
public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        create();
    }
    Matrix(const Matrix& m) {
        rows = m.rows;
        cols = m.cols;
        create();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) grid[i][j] = m.grid[i][j];
    }
    ~Matrix() { destroy(); }
    Matrix& operator=(const Matrix& rhs) {
        if (this == &rhs) return *this;
        destroy();
        rows = rhs.rows;
        cols = rhs.cols;
        create();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) grid[i][j] = rhs.grid[i][j];
        return *this;
    }
    double& operator()(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) throw out_of_range("Invalid index");
        return grid[r][c];
    }
    Matrix operator+(const Matrix& rhs) const {
        Matrix res(rows, cols);
        if (rows != rhs.rows || cols != rhs.cols) {
            cout << "Error: sizes must be same for addition" << endl;
            return res;
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) res.grid[i][j] = grid[i][j] + rhs.grid[i][j];
        return res;
    }
    Matrix operator*(const Matrix& rhs) const {
        if (this->cols != rhs.rows) {
            cout << "Error: cols of first must equal rows of second" << endl;
            return Matrix(1, 1);
        }
        Matrix res(rows, rhs.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.cols; j++)
                for (int k = 0; k < cols; k++) res.grid[i][j] += grid[i][k] * rhs.grid[k][j];
        return res;
    }
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) out << setw(8) << m.grid[i][j];
            out << endl;
        }
        return out;
    }
};
int main() {
    int r1, c1, r2, c2;
    cout << "Rows and cols of A: ";
    cin >> r1 >> c1;
    cout << "Rows and cols of B: ";
    cin >> r2 >> c2;
    Matrix A(r1, c1), B(r2, c2);
    try {
        cout << "Enter A:" << endl;
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++) cin >> A(i, j);
        cout << "Enter B:" << endl;
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++) cin >> B(i, j);
        Matrix C = A * B;
        cout << "A * B:" << endl << C;
        cout << "A + B:" << endl << A + B;
        Matrix D(1, 1);
        D = C;
        D(0, 0) = 999;
        cout << "C after changing D:" << endl << C;
        cout << "D:" << endl << D;
        A(r1, 0) = 1;
    }
    catch (out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
