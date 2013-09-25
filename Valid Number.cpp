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
    bool isNumber(const char *s) {
        string str(s);
        removeLeadingSpace(str);
        removeTailingSpace(str);
        //cout << str << endl;
        if (hasSpaceInTheMiddle(str))
            return false;
        int index = findELocation(str);
        if (index == -2)  //more than one 'e'
            return false;
        if (index != -1) { // has one 'e'
            string left = str.substr(0, index);
            string right = str.substr(index + 1, str.size() - index - 1);
            return (isNumber(left.c_str()) && isInteger(right));
        } else {    // no 'e'
            for (int i = 0; i < str.size(); i++)
                if (str[i] == '.') {
                    string left = str.substr(0, i);
                    string right = str.substr(i + 1, str.size() - i - 1);
                    if (isInteger(left) && isInteger(right) && right[0] != '-' && right[0] != '+')
                        return true;
                    if (isInteger(left) && right.empty())
                        return true;
                    if (left.empty() && isInteger(right) && right[0] != '-' && right[0] != '+')
                        return true;
                    if (left == string("+") && isInteger(right))
                        return true;
                    if (left == string("-") && isInteger(right))
                        return true;
                    return false;
                }
            return isInteger(str);
        }
    }

    bool hasSpaceInTheMiddle(string str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] == ' ')
                return true;
        return false;
    }

    //return the 'e' location in str
    //-1 if 'e' does not exist
    //-2 more the one 'e'
    //otherwise, index
    int findELocation(string str) {
        int count = 0;
        int index;
        for (int i = 0; i < str.size(); i++)
            if (str[i] == 'e' || str[i] == 'E') {
                count++;
                index = i;
            }
        if (count > 1)
            return -2;
        if (count == 0)
            return -1;
        return index;
    }

    bool isInteger(string str) {
        if (str.empty())
            return false;
        if (str[0] == '+' || str[0] == '-')
            str = str.substr(1);
        if (str.empty())  // only has sign
            return false;
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= '0' && str[i] <= '9')
                continue;
            else
                return false;
        return true;
    }

    void removeLeadingSpace(string &str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] != ' ') {
                str = str.substr(i);
                return;
            }
        str.clear();
    }

    void removeTailingSpace(string &str) {
        for (int i = str.size() - 1; i >= 0; i--)
            if (str[i] != ' ') {
                if (i != str.size() - 1)
                    str.erase(i + 1);
                return;
            }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isNumber("    1.2    0") << endl;
    cout << sol.isNumber(" 0.1") << endl;
    cout << sol.isNumber("abc") << endl;
    cout << sol.isNumber("1 a") << endl;
    cout << sol.isNumber("2e10") << endl;
    cout << sol.isNumber("1e") << endl;
    return 0;
}
