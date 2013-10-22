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
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            int change = prices[i] - prices[i - 1];
            if (change > 0)
                max += change;
        }
        return max;
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
