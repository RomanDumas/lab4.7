#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double x_p, x_k, dx, eps, S, a, R, n = 0, atanX, Pi;
    Pi = 4.0 * atan(1.0);
	
    cout << "x_p must be higher 1" << endl;
	cout << "x_p =";cin >> x_p;
	cout << "x_k =";cin >> x_k;
	cout << "dx =";cin >> dx;
	cout << "eps =";cin >> eps;
	
    cout << "----------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "  |"
        << setw(14) << "atan x" << "  |"
        << setw(9) << "S" << "   |"
        << setw(6) << "n" << "|"
        << endl;
    cout << "----------------------------------------------" << endl;

	double x = x_p;
    if (x > 1) {
        while (x <= x_k) {
            n = 0;
            a = -1.0 / x;
            S = a;
            do {
                n++;
                R = -1.0 * (2 * n - 1) / ((2 * n + 1) * x);
                a *= R;
                S += a;

            } while (abs(a) > eps);
            atanX = Pi / x + S;
            cout << "|" << setw(7) << setprecision(2) << x << "|"
                << setw(15) << setprecision(5) << atanX << " |"
                << setw(12) << setprecision(5) << S << "|"
                << setw(5) << n << " |"
                << endl;
            x += dx;
        }
    }
    else
        cout << "ERROR" << endl;

	return 0;
}