#include <iostream>
#include <iomanip>
using namespace std;

double ctok(double);

int main()
{
    double c = 0.0;
    cout << "Celsius: ";
    cin >> c;
    try
    {
        double k = ctok(c);
        cout << "Kelvin: " << k << '\n';
    }
    catch (exception e)
    {
        cerr << "Error reporting!\n";
        return -1;
    }
    return 0;
}

double ctok(double c)
{
    if (c < -273.15)
        throw out_of_range("");
    double k = c + 273.15;
    return k;
}
