#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <time.h>
#include <functional>
#include <queue>
#include <cctype>
#include <sstream>

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() == 1)
            return 0;
        vector<int> changes;
        for (int i = 1; i < prices.size(); i++) {
            int change = prices[i] - prices[i - 1];
            changes.push_back(change);
        }
        findMaxSubarray(changes);
        int max1 = f[changes.size() - 1];
        int max2 = 0;
        for (int i = 0; i + 1 < changes.size(); i++) {
            int tmp = f[i] + g[i + 1];
            if (max2 < tmp)
                max2 = tmp;
        }
        return max(0, max(max1, max2));
    }
private:
    void findMaxSubarray(vector<int> &nums) {
        f.resize(nums.size());
        g.resize(nums.size());

        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (currSum > maxSum)
                maxSum = currSum;
            if (currSum < 0)
                currSum = 0;
            f[i] = maxSum;
        }

        maxSum = INT_MIN;
        currSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            currSum += nums[i];
            if (currSum > maxSum)
                maxSum = currSum;
            if (currSum < 0)
                currSum = 0;
            g[i] = maxSum;
        }
    }
    vector<int> f;
    vector<int> g;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<int> prices({1, 2, 4, 7});
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
