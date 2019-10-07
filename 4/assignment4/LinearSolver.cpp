//
// Created by Bugen Zhao on 2019/10/7.
//

// TODO: a lot of problems
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using value_type=double;

int n;

vector<value_type> solve(int choice) {
    switch (choice) {
        case 0: {
            int times = 10000;
            double d = 0.001;

        }
        case 1:
        default:
            throw runtime_error("");
    }
}

int main() {
    cout << "Input the number of equations and unknowns n: ";
    cin >> n;
    vector<vector<value_type>> v = vector<vector<value_type>>(n);

    cout << "\nInput the augmented matrix of Ax=b as [A b]:\n";
    value_type tmp;
    for (int i = 0; i < n; ++i) {
        v[i] = vector<value_type>(n + 1);
        for (int j = 0; j < n + 1; ++j) {
            cin >> tmp;
            v[i][j] = tmp;
        }
    }

    cout << "\n[0] Jacobi Iteration [1] Gaussian Elimination\nChoose a method: ";
    int choice;
    cin >> choice;
    auto ans = solve(choice);

    cout << "\nResult is:\n";
    for (auto a:ans) cout << a << ' ';
    cout << endl;
    return 0;
}