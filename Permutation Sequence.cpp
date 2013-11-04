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
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i++)
            str += ('0' + i);
        k--;
        string perm;
        for (int i = 0; i < n; i++) {
            int tmp = fact(n - i - 1);
            int index = k / tmp;
            perm += str[index];
            str.erase(str.begin() + index);
            k -= k / tmp * tmp;
        }
        return perm;
    }
private:
    int fact(int n) {
        int f = 1;
        for (int i = 1; i <= n; i++)
            f *= i;
        return f;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.getPermutation(3, 6) << endl;
    return 0;
}
