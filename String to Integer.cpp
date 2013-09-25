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

#define EPS 1e-6
#define SIZE 110

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        string str1 = discardLeadingWhitespace(str);
        discardTailingChar(str1);
        return convertToNum(str1);
    }

private:
    string discardLeadingWhitespace(const char *str) {
        string res;
        int i = 0;
        while (true) {
            if (str[i] != ' ' || str[i] == '\0')
                break;
            i++;
        }
        while (true) {
            if (str[i] == '\0')
                break;
            res += str[i];
            i++;
        }
        return res;
    }

    void discardTailingChar(string &str) {
        int i = 0;
        if (str[i] == '+' || str[i] == '-')
            i++;
        while (str[i] >= '0' && str[i] <= '9')
            i++;
        str = str.substr(0, i);
    }

    int convertToNum(string &str) {
        if (str.empty())
            return 0;
        int sign;
        if (str[0] == '-')
            sign = -1;
        else
            sign = 1;
        if (str[0] == '+' || str[0] == '-')
            str = str.substr(1);
        long long num = 0;
        for (int i = 0; i < str.size(); i++) {
            num *= 10;
            num += str[i] - '0';
            if (num > INT_MAX)
                break;
        }
        if (num > INT_MAX) {
            if (sign == -1)
                return sign * INT_MIN;
            else
                return sign * INT_MAX;
        }
        else
            return sign * num;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    //char str[] = "      +23423423    afsdfs";
    char str[] = "-2147483648";
    cout << sol.atoi(str) << endl;
    return 0;
}
