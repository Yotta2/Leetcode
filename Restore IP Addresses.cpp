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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s, 0, "", ans);
        return ans;
    }
private:
    bool isValid(string str) {
        if (str.size() != 1 && str[0] == '0')
            return false;
        int num;
        sscanf(str.c_str(), "%d", &num);
        return (num >= 0 && num <= 255);
    }

    void dfs(string s, int count, string soFar, vector<string> &ans) {
        if (count == 3) {
            if (isValid(s))
                ans.push_back(soFar + "." + s);
            return;
        }
        for (int i = 1; i <= 3; i++) {
            string head = s.substr(0, i);
            string rest = s.substr(head.length());
            if (isValid(head)) {
                if (count != 0)
                    dfs(rest, count + 1, soFar + "." + head, ans);
                else
                    dfs(rest, count + 1, soFar + head, ans);
            }
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
