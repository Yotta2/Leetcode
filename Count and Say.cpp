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
    string countAndSay(int n) {
        string curr = "1";
        for (int i = 0; i < n - 1; i++)
            curr = genNext(curr);
        return curr;
    }
private:
    string genNext(string str) {
        int i = 0;
        string next;
        while (i < str.size()) {
            int count = 1;
            char digit = str[i];
            while (true) {
                if (i + 1 >= str.size() || str[i] != str[i + 1])
                    break;
                i++;
                count++;
            }
            string str;
            stringstream ss;
            ss << count;
            ss >> str;
            next += str;
            next += digit;
            i++;
        }
        return next;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.countAndSay(100) << endl;
    return 0;
}
