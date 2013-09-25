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
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    st.push(s[i]);
            else {
                if (!st.empty() && match(st.top(), s[i]))
                    st.pop();
                else
                    return false;
            }
        if (st.empty())
            return true;
        else
            return false;
    }

private:
    bool match(char left, char right) {
        if (left == '[' && right == ']')
            return true;
        if (left == '{' && right == '}')
            return true;
        if (left == '(' && right == ')')
            return true;
        return false;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    //string str = "()[]}{}";
    string str = "{";
    cout << sol.isValid(str) << endl;
    return 0;
}
