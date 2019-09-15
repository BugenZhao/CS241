#include <iostream>
#include <iomanip>
using namespace std;

double ctok(double);

int main()
{
    double c = 0.0;
    cout << "Celsius: ";
    cin >> c;
    double k = ctok(c);
    cout << "Kelvin: " << k << '\n';
    return 0;
}

double ctok(double c)
{
    double k = c + 273.15;
    return k;
}
