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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = preprocess(s);
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

    string preprocess(string s) {
        string res;
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= '0' && s[i] <= '9')
                res += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
                res += tolower(s[i]);
        return res;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;
    cout << sol.isPalindrome("") << endl;
    return 0;
}
