#include <iostream>
#include <string>
#include <vector>

using namespace std;


class LCS {
public:
    int LongestCommonSubsequence(const string &text1, const string &text2) {
        if (text1.empty() || text2.empty()) return 0;

        auto M = text1.size();
        auto N = text2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = max({dp[i - 1][j],
                                dp[i][j - 1],
                                dp[i - 1][j - 1] + (text1[i] == text2[j])
                               });
            }
        }
        return dp[M][N];
    }
};


class WIS {
private:
    struct Interval {
        int startTime;
        int endTime;
        int profit;
    };
public:
    int WeightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<Interval> intervals(startTime.size());
        for (int i = 0; i < startTime.size(); ++i) {
            intervals[i] = Interval{startTime[i], endTime[i], profit[i]};
        }
        sort(intervals.begin(), intervals.end(),
             [](const Interval &lhs, const Interval &rhs) { return lhs.endTime < rhs.endTime; });

        vector<int> rightMost(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) { // TODO: optimize using binary search
            rightMost[i] = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[j].endTime <= intervals[i].startTime) {
                    rightMost[i] = j;
                    break;
                }
            }
        }

        vector<int> dp(intervals.size(), 0);
        auto getDp = [&dp](int p) { return (p == -1) ? 0 : dp[p]; };
        for (int i = 0; i < intervals.size(); ++i) {
            dp[i] = max(intervals[i].profit + getDp(rightMost[i]), getDp(i - 1));
        }

        return dp[intervals.size() - 1];
    }
};


class KP {
public:
    int KnapsackProblem(vector<int> &weight, vector<int> &value, int W) {
        vector<int> dp(W + 1);
        int N = weight.size();
        for (int i = 0; i < N; ++i) {
            for (int w = W; w >= 0; --w) {
                if (w >= weight[i]) {
                    dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
                    // like dp[i-1][w], dp[i-1][w - weight[i]]
                }
            }
        }
        return dp[W];
    }
};


// For testing
int main(int argc, const char *argv[]) {

    //*********** Test Longest Common Subsequence ***********//
    string text1 = "springtime";
    string text2 = "printing";
    LCS lcs = LCS();
    cout << "Test Longest Common Subsequence..." << endl;
    cout << lcs.LongestCommonSubsequence(text1, text2) << endl;
    cout << "The expected output: 6" << endl;
    cout << endl;

    //********** Test Weighted Interval Scheduling **********//
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 9, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};
    WIS wis = WIS();
    cout << "Test Weighted Interval Scheduling..." << endl;
    cout << wis.WeightedIntervalScheduling(startTime, endTime, profit) << endl;
    cout << "The expected output: 150" << endl;
    cout << endl;

    //*************** Test Knapsack Problem ****************//
    vector<int> weight = {1, 2, 5, 6, 7};
    vector<int> value = {1, 6, 18, 22, 28};
    int W = 11;
    KP kp = KP();
    cout << "Test Knapsack Problem..." << endl;
    cout << kp.KnapsackProblem(weight, value, W) << endl;
    cout << "The expected output: 40" << endl;
    cout << endl;

    return 0;
}
