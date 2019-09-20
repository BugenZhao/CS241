#include <iostream>
#include <iomanip>
using namespace std;

double ctok(double);

int main()
{
    double c = 0.0;
    cout << "Celsius: ";
    cin >> c;
    if (c < -273.15)
    {
        cerr << "Error reporting!\n";
        return -1;
    }
    double k = ctok(c);
    cout << "Kelvin: " << k << '\n';
    return 0;
}

double ctok(double c)
{
    double k = c + 273.15;
    return k;
}
