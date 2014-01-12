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
#include <utility>

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> nums;
        for (int i = 0; i < num.size(); i++)
            nums.insert(num[i]);
        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            if (nums.find(num[i]) != nums.end()) {
                nums.erase(num[i]);
                int start = num[i];
                int end = num[i];
                while (true) {
                    if (nums.find(start - 1) == nums.end())
                        break;
                    start--;
                    nums.erase(start);
                }
                while (true) {
                    if (nums.find(end + 1) == nums.end())
                        break;
                    end++;
                    nums.erase(end);
                }
                ans = max(ans, end - start + 1);
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

