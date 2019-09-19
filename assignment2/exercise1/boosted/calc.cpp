//
// Created by Bugen Zhao on 2019/9/19.
//

#include <vector>
#include <iostream>


using namespace std;

int main() {
    boost::rational<int> r;
    r.assign(1, 2);
    cout << r;
}
