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
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ans = INT_MAX;
        for (int i = 0; i < num.size(); i++) {
            int tmp = num[i];
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = tmp + num[j] + num[k];
                if (fabs(target - sum) < fabs(target - ans))
                    ans = sum;
                if (sum == target)
                    return sum;
                if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
