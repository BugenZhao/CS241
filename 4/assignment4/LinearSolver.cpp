//
// Created by Bugen Zhao on 2019/10/7.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
constexpr bool DEBUG = false;
constexpr int JACOBI = 0;
constexpr int GAUSS = 1;

void debug_print(const vector<vector<double>> &v) {
    if (DEBUG) {
        for (const auto &row : v) {
            for (double a : row) {
                cout << setw(10) << a;
            }
            cout << endl;
        }
        cout << endl;
    }
}

inline double clear_residual(const double &d) {
    return (d > -1e-6 && d < 1e-6) ? 0.0 : d;
}

void convert_to_upper_triangular(vector<vector<double>> &v) {
    int n = v.size();
    debug_print(v);
    for (int c = 0, r = 0; c < n && r + 1 < n; ++c) {
        int rr = r;
        while (rr < n && v[rr][c] == 0) ++rr;
        if (rr == n) {
            continue;
        } else {
            swap(v[r], v[rr]);
            for (int i = r + 1; i < n; ++i) {
                double d = v[i][c] / v[r][c];
                for (int j = r; j < n + 1; ++j) {
                    v[i][j] = clear_residual(v[i][j] - d * v[r][j]);
                }
            }
            ++r;
            debug_print(v);
        }
    }
}

bool has_unique_solution(vector<vector<double>> v) {
    int n = v.size();
    convert_to_upper_triangular(v);
    for (int i = 0; i < n; ++i) {
        if (v[n - 1][i] != 0.0) return true;
    }
    return false;
}

vector<double> solve(vector<vector<double>> v, int choice, vector<double> initial = {}) {
    switch (choice) {
        case JACOBI: {
            int times = 10000;
            bool ok = false;
            double D = 0.001;

            int n = v.size();
            vector<double> ans = std::move(initial);
            vector<double> ans_new((n));

            for (int t = 0; t < times; ++t) {
                for (int i = 0; i < n; ++i) {
                    double tmp = v[i][n];
                    for (int j = 0; j < n; ++j) {
                        if (j == i) continue;
                        tmp -= v[i][j] * ans[j];
                    }
                    ans_new[i] = clear_residual(tmp / v[i][i]);
                }

                if (t != 0) {
                    double d = 0;
                    for (int i = 0; i < n; ++i) {
                        d += pow((ans[i] - ans_new[i]), 2);
                    }
                    d = sqrt(d);
                    if (d < D) {
                        ok = true;
                        break;
                    }
                }
                ans = ans_new;
            }

            if (!ok) {
                cerr << "Maximum number of iterations exceeded!" << endl;
                throw runtime_error("");
            }
            return ans;
        }
        case GAUSS: {
            int n = v.size();
            vector<double> ans((n));
            convert_to_upper_triangular(v);
            for (int i = n - 1; i >= 0; --i) {
                ans[i] = v[i][n];
                for (int k = i + 1; k < n; ++k) {
                    ans[i] -= v[i][k] * ans[k];
                }
                ans[i] /= v[i][i];
            }
            return ans;
        }
        default:
            throw runtime_error("");
    }
}

int main() {
    cout << "Input the number of equations and unknowns n: ";
    int n = 0;
    cin >> n;
    if (cin.fail()) {
        cerr << "Invalid input!" << endl;
        return -1;
    }
    vector<vector<double>> v((n));

    cout << "\nInput the augmented matrix of Ax=b as [A b]:\n";
    double tmp = 0.0;
    for (int i = 0; i < n; ++i) {
        v[i] = vector<double>(n + 1);
        for (int j = 0; j < n + 1; ++j) {
            cin >> tmp;
            v[i][j] = tmp;
        }
    }
    if (cin.fail()) {
        cerr << "Invalid input!" << endl;
        return -1;
    }
    if (!has_unique_solution(v)) {
        cerr << "No unique solution exists!" << endl;
        return 0;
    }

    cout << "\n[0] Jacobi Iteration [1] Gaussian Elimination\nChoose a method: ";
    int choice = 0;
    cin >> choice;
    if (cin.fail()) {
        cerr << "Invalid input!" << endl;
        return -1;
    }

    vector<double> initial(n);
    if (choice == JACOBI) {
        cout << "\nInput the initial approximation x(0):\n";
        for (int i = 0; i < n; ++i) {
            cin >> initial[i];
        }
    }

    try {
        auto ans = solve(v, choice, initial);
        cout << "\nResult is:\n";
        for (auto a:ans) cout << a << ' ';
        cout << endl;
    } catch (const exception &ignore) {
        return 1;
    }
    return 0;
}