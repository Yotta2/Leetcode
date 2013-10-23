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
    string longestPalindrome(string S) {
        if (isPalindrome(S))
            return S;
        string maxSubstr = "";
        for (int mid = 0; mid < S.size(); mid++) {
            int i, j;
            string str;
            //slot is the middle point
            for (i = mid, j = mid + 1, str = string() + ""; i >= 0 && j < S.size(); i--, j++)
                if (S[i] != S[j])
                    break;
                else
                    str = S[i] + str + S[j];
            if (maxSubstr.size() < str.size())
                maxSubstr = str;
            //mid is the middle point
            for (i = mid - 1, j = mid + 1, str = string() + S[mid]; i >= 0 && j < S.size(); i--, j++)
                if (S[i] != S[j])
                    break;
                else
                    str = S[i] + str + S[j];
            if (maxSubstr.size() < str.size())
                maxSubstr = str;
        }
        return maxSubstr;
    }
private:
    bool isPalindrome(string &str) {
        int p = 0;
        int q = str.size() - 1;
        while (p <= q) {
            if (str[p] != str[q])
                return false;
            p++;
            q--;
        }
        return true;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.longestPalindrome("ccd") << endl;
    return 0;
}
