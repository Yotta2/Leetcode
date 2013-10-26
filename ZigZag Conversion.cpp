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
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        vector<string> tmp(nRows, string(s.size(), ' '));
        int i = 0;
        int j = 0;
        int count = 0;
        while (true) {
            if (count == s.size())
                break;
            while (i < nRows) {
                tmp[i][j] = s[count];
                count++;
                if (count == s.size())
                    break;
                i++;
            }
            i -= 2;
            j++;
            if (count == s.size())
                break;
            while (i >= 0) {
                tmp[i][j] = s[count];
                count++;
                if (count == s.size())
                    break;
                i--;
                j++;
            }
            i += 2;
            j--;
        }
        string ans;
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < s.size(); j++)
                if (tmp[i][j] != ' ')
                    ans += tmp[i][j];
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.convert("AB", 1) << endl;
    return 0;
}
