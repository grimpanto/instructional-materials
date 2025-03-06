
#include <iostream>
#include <limits>

using namespace std;

using nl_float = numeric_limits<float>;
using nl_double = numeric_limits<double>;
using nl_ldouble = numeric_limits<long double>;

int main() {
    cout << "type\t\t" << "min" << "\t\tmax" << endl;
    cout << "float\t\t" << nl_float::min() << "\t" << nl_float::max() << endl;
    cout << "double\t\t" << nl_double::min() << "\t" << nl_double::max() << endl;
    cout << "long double\t" << nl_ldouble::min() << "\t" << nl_ldouble::max() << endl;

    cout << endl;
    cout << "double" << endl;
    cout << "======" << endl;
    cout << "is IEEE 754:\t" << nl_double::is_iec559 << endl;
    cout << "radix:\t\t" << nl_double::radix << endl;  // Basis
    cout << "digits:\t\t" << nl_double::digits << endl;  // binary digits
    cout << "decimal digits:\t" << nl_double::digits10 << endl;  // decimal digits
    cout << "max exponent:\t" << nl_double::max_exponent << endl;
    cout << "min exponent:\t" << nl_double::min_exponent << endl;

    cout << endl;
    cout << "long double" << endl;
    cout << "===========" << endl;
    cout << "is IEEE 754:\t" << nl_ldouble::is_iec559 << endl;
    cout << "radix:\t\t" << nl_ldouble::radix << endl;  // Basis
    cout << "digits:\t\t" << nl_ldouble::digits << endl;  // binary digits
    cout << "decimal digits:\t" << nl_ldouble::digits10 << endl;  // decimal digits
    cout << "max exponent:\t" << nl_ldouble::max_exponent << endl;
    cout << "min exponent:\t" << nl_ldouble::min_exponent << endl;

}
