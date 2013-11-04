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

//O(n3), can do better
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty())
            return s2 == s3;
        if (s2.empty())
            return s1 == s3;
        vector<vector<vector<bool> > > f(s1.size() + 1,
                                         vector<vector<bool> >(s2.size() + 1, vector<bool>(s3.size() + 1, false)));
        init(f, s1, s2, s3);
        for (int k = s3.size() - 1; k >= 0; k--)
            for (int j = s2.size() - 1; j >= 0; j--)
                for (int i = s1.size() - 1; i >= 0; i--) {
                    f[i][j][k] = (s1[i] == s3[k] && f[i + 1][j][k + 1])
                                    || (s2[j] == s3[k] && f[i][j + 1][k + 1]);
                }
        return f[0][0][0];
    }
private:
    void init(vector<vector<vector<bool> > > &f,
              string s1,
              string s2,
              string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();
        for (int i = 0; i <= s1Len; i++)
            for (int k = 0; k <= s3Len; k++)
                f[i][s2Len][k] = (s1.substr(i) == s3.substr(k));
        for (int j = 0; j <= s2Len; j++)
            for (int k = 0; k <= s3Len; k++)
                f[s1Len][j][k] = (s2.substr(j) == s3.substr(k));
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isInterleave("aa", "ab", "abaa") << endl;
    return 0;
}
