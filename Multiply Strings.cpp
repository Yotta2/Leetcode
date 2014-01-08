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
    string multiply(string num1, string num2) {
        string ans;
        ans.resize(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); i++)
            for (int j = 0; j < num2.size(); j++) {
                int tmp0 = ans[i + j] - '0' + (num1[i] - '0') * (num2[j] - '0');
                int tmp1 = ans[i + j + 1] - '0' + tmp0 / 10;
                tmp0 %= 10;
                ans[i + j] = tmp0 + '0';
                ans[i + j + 1] = tmp1 + '0';
            }
        removeTailingZero(ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void removeTailingZero(string &ans) {
        int i = ans.size() - 1;
        while (i > 0 && ans[i] == '0')
            i--;
        ans.resize(i + 1);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
