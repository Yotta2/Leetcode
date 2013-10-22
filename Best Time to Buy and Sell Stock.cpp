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
        vector<int> changes;
        for (int i = 1; i < prices.size(); i++) {
            int change = prices[i] - prices[i - 1];
            changes.push_back(change);
        }
        return findMaxSubarray(changes);
    }
private:
    int findMaxSubarray(vector<int> &nums) {
        return dac(nums, 0, nums.size() - 1);
    }
    int dac(vector<int> &nums, int low, int high) {
        if (low > high)
            return 0;
        int mid = (low + high) / 2;
        int leftMax = dac(nums, low, mid - 1);
        int rightMax = dac(nums, mid + 1, high);
        int midMax = nums[mid];
        int sum = 0;
        int maxTmp = 0;
        for (int i = mid - 1; i >= low; i--) {
            sum += nums[i];
            if (sum > maxTmp)
                maxTmp = sum;
        }
        midMax += maxTmp;
        maxTmp = 0;
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += nums[i];
            if (sum > maxTmp)
                maxTmp = sum;
        }
        midMax += maxTmp;
        return max(leftMax, max(midMax, rightMax));
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<int> prices({1, 2, 4});
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
