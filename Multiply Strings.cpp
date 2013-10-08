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
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size() + 2, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.size(); i++)
            for (int j = 0; j < num1.size(); j++) {
                int tmp0 = (num1[j] - '0') * (num2[i] - '0') + ans[i + j] - '0';  // ans[i + j]
                int tmp1 = ans[i + j + 1] - '0'; // ans[i + j + 1]
                tmp1 += tmp0 / 10;
                tmp0 %= 10;
                ans[i + j] = tmp0 + '0';
                ans[i + j + 1] = tmp1 + '0';
            }
        for (int i = ans.size() - 1; i >= 0; i--)
            if (ans[i] != '0' || i == 0) {
                ans.resize(i + 1);
                break;
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.multiply("9999", "9999") << endl;
    return 0;
}

