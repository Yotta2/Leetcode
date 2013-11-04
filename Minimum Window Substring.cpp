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
    string minWindow(string S, string T) {
        hm.clear();
        hm0.clear();
        hm1.clear();
        for (int i = 0; i < T.size(); i++) {
            hm0[T[i]]++;
            hm1[T[i]]++;
        }
        int i = 0;
        int j = 0;
        string minWin = S;
        bool found = false;
        while (true) {
            if (j >= S.size())
                break;
            while (true) {
                if (j >= S.size())
                    break;
                hm[S[j]]++;
                if (hm1.find(S[j]) != hm1.end()) {
                    hm1[S[j]]--;
                    if (hm1[S[j]] == 0)
                        hm1.erase(S[j]);
                }
                if (hm1.empty()) {
                    found = true;
                    break;
                }
                j++;
            }
            if (j >= S.size())
                break;
            //shrink
            while (true) {
                if (hm0.find(S[i]) != hm0.end()) {
                    if (hm[S[i]] > hm0[S[i]])
                        hm[S[i]]--;
                    else
                        break;
                } else {
                    hm[S[i]]--;
                    if (hm[S[i]] == 0)
                        hm.erase(S[i]);
                }
                i++;
            }
            string win = S.substr(i, j - i + 1);
            if (minWin.size() > win.size())
                minWin = win;
            hm[S[i]]--;
            if (hm[S[i]] == 0)
                hm.erase(S[i]);
            hm1[S[i]]++;
            i++;
            j++;
        }
        if (found)
            return minWin;
        else
            return string("");
    }
private:
    typedef unordered_map<char, int> CharToCountMap;
    CharToCountMap hm;
    unordered_map<char, int> hm0;
    unordered_map<char, int> hm1;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isInterleave("aa", "ab", "abaa") << endl;
    return 0;
}
