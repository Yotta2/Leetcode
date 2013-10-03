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
    string addBinary(string a, string b) {
        string reversedA = _reverse(a);
        string reversedB = _reverse(b);
        string ans;
        int carry = 0;
        int i = 0;
        while (true) {
            if (i >= reversedA.size() && i >= reversedB.size())
                break;
            int num1 = 0;
            int num2 = 0;
            if (i < reversedA.size())
                num1 = reversedA[i] - '0';
            if (i < reversedB.size())
                num2 = reversedB[i] - '0';
            int sum = num1 + num2 + carry;
            carry = sum / 2;
            ans += '0' + sum % 2;
            i++;
        }
        if (carry == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string _reverse(string str) {
        string res;
        for (int i = str.size() - 1; i >= 0; i--)
            res += str[i];
        return res;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
