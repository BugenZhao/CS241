#include <iostream>
#include <limits>
// #include <vector>
#include "myArray.h"
#include "myData.h"
#include "mySort.h"

using namespace std;
typedef float T; // Change the type here


int main() {
    ///////////////////////////
    // Test "myArray.h"      //
    ///////////////////////////
    cout << "*****Test default constructor*****" << endl;
    myArray<T> A;
    cout << "A.size(): " << A.size() << " " << "A.capacity(): " << A.capacity() << endl;
    cout << endl;

    cout << "*****Test push_back() and pop_back()*****" << endl;
    T x;
    cout << "Randomly input some values and stop with any non-numerical inputs:" << endl;
    while (cin >> x) A.push_back(x);
    cout << "A.size(): " << A.size() << " " << "A.capacity(): " << A.capacity() << endl;
    A.pop_back();
    cout << "After pop_back(): " << endl;
    cout << "A.size(): " << A.size() << " " << "A.capacity(): " << A.capacity() << endl;
    cout << endl;

    cout << "*****Test begin() and end()*****" << endl;
    // TODO: bug here.
    // cout << "*A.begin(): " << *A.begin() << " "<< "*A.end(): " << *A.end() << endl;
    cout << "*A.begin(): " << *A.begin() << endl;
    cout << endl;

    cout << "*****Test operator=, operation[]*****" << endl;
    myArray<T> Acopy = A;
    for (int i = 0; i < Acopy.size(); i++)
        cout << Acopy[i] << " ";
    cout << endl;
    cout << endl;

    cout << "*****Test iterator*****" << endl;
    auto it = A.begin();
    for (; it != A.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << endl;

    ///////////////////////////
    // Test "myData.h"       //
    ///////////////////////////
    cout << "*****Test myData*****" << endl;
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // First, create an myArray object of type myData and randomly input values.
    myArray<myData<T>> obj;
    // Note: This part can be modified to fit your code. It is just an example.
    while (cin >> x) obj.push_back(myData<T>(x));
    for (int i = 0; i < obj.size(); i++)
        obj[i].addr = &obj[i];

    // Secondly, iterate through the myArray object and print myData.val and myData.addr
    for (int i = 0; i < obj.size(); i++)
        cout << "obj[i].val: " << obj[i].val << " " << "obj[i].addr: " << obj[i].addr << endl;
    cout << endl;
    cout << endl;

    /////////////////////////
    // Test "mySort.h"     //
    /////////////////////////
    cout << "*****Test mySort*****" << endl;
    // First, sort the elements in the range [begin, end) into ascending order in terms of myData.val
    mySort(obj.begin(), obj.end(), Cmp_by_val<T>());
    for (int i = 0; i < obj.size(); i++)
        cout << "obj[i].val: " << obj[i].val << " " << "obj[i].addr: " << obj[i].addr << endl;
    cout << endl;

    // Secondly, sort the elements into ascending order in terms of myData.addr to restore the original array
    mySort(obj.begin(), obj.end(), Cmp_by_addr<T>());
    for (int i = 0; i < obj.size(); i++)
        cout << "obj[i].val: " << obj[i].val << " " << "obj[i].addr: " << obj[i].addr << endl;

    return 0;
}
