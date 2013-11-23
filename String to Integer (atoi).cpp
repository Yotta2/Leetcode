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
    int atoi(const char *str) {
        string s(str);
        discardLeadingZero(s);
        return convertToInt(s);
    }
private:
    void discardLeadingZero(string &str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] != ' ') {
                str = str.substr(i);
                return;
            }
        str = "";
    }
    int convertToInt(string &str) {
        if (str.empty())
            return 0;
        int sign;
        if (str[0] == '-') {
            sign = -1;
            str = str.substr(1);
        } else if (str[0] == '+') {
            sign = 1;
            str = str.substr(1);
        } else {
            sign = 1;
        }
        if (str.empty())
            return 0;
        long long num = 0;
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + str[i] - '0';
                if (sign == 1 && num > INT_MAX)
                    return INT_MAX;
                if (sign == -1 && num > INT_MAX)
                    return INT_MIN;
            } else {    // discard tailing non-digit characters
                break;
            }
        return sign * num;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << INT_MIN << endl;
    return 0;
}
