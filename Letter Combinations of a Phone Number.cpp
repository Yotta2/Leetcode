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
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digitToLettersHM;
        init(digitToLettersHM);
        string soFar = digits;
        vector<string> ans;
        recGen(soFar, digits, 0, digitToLettersHM, ans);
        return ans;
    }
private:
    void recGen(string &soFar, string &digits, int i,
             unordered_map<char, string> &digitToLettersHM, vector<string> &ans) {
        if (i == digits.size()) {
            ans.push_back(soFar);
            return;
        }
        string letters = digitToLettersHM[digits[i]];
        for (int j = 0; j < letters.size(); j++) {
            soFar[i] = letters[j];
            recGen(soFar, digits, i + 1, digitToLettersHM, ans);
        }
    }

    void init(unordered_map<char, string> &digitToLettersHM) {
        digitToLettersHM['2'] = "abc";
        digitToLettersHM['3'] = "def";
        digitToLettersHM['4'] = "ghi";
        digitToLettersHM['5'] = "jkl";
        digitToLettersHM['6'] = "mno";
        digitToLettersHM['7'] = "pqrs";
        digitToLettersHM['8'] = "tuv";
        digitToLettersHM['9'] = "wxyz";
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
