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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(0, "", s, ans);
        return ans;
    }
private:
    void dfs(int count, string soFar, string rest, vector<string> &ans) {
        if (count == 3) {
            if (isValid(rest)) {
                soFar += rest;
                ans.push_back(soFar);
            }
            return;
        }
        for (int i = 1; i <= 3; i++)
            if (rest.size() > i) {
                string s = rest.substr(0, i);
                if (isValid(s))
                    dfs(count + 1, soFar + s + ".", rest.substr(i), ans);
            }
    }
    bool isValid(string str) {
        if (str.size() >= 2 && str[0] == '0')
            return false;
        int num;
        sscanf(str.c_str(), "%d", &num);
        if (num >= 0 && num <= 255)
            return true;
        else
            return false;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

