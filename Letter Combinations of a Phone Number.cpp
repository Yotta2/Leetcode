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
    vector<string> letterCombinations(string digits) {
        digitToLettersMap dlm;
        init(dlm);
        vector<string> ans;
        dfs("", 0, digits, dlm, ans);
        return ans;
    }
private:
    typedef unordered_map<char, unordered_set<char> > digitToLettersMap;
    void init(digitToLettersMap &dlm) {
        char ch = 'a';
        for (int i = 2; i <= 9; i++)
            if (i == 7 || i == 9) {
                for (int j = 0; j < 4; j++) {
                    dlm[char(i + '0')].insert(ch);
                    ch++;
                }
            } else {
                for (int j = 0; j < 3; j++) {
                    dlm[char(i + '0')].insert(ch);
                    ch++;
                }
            }
    }
    void dfs(string soFar, int index, string digits, digitToLettersMap &dlm, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(soFar);
            return;
        }
        unordered_set<char> letters = dlm[digits[index]];
        for (unordered_set<char>::iterator itr = letters.begin(); itr != letters.end(); itr++)
            dfs(soFar + (*itr), index + 1, digits, dlm, ans);

    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    sol.letterCombinations("2");
    return 0;
}

