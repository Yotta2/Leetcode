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
    string intToRoman(int num) {
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int vals[] = {      1000, 900,  500, 400,  100,  90,  50,   40,  10,   9,    5,    4,   1};
        int i = 0;
        string romanStr;
        while (num != 0) {
            int count = num / vals[i];
            if (count != 0)
                num %= count * vals[i];
            for (int j = 0; j < count; j++)
                romanStr += numerals[i];
            i++;
        }
        return romanStr;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.intToRoman(3099) << endl;
    return 0;
}
