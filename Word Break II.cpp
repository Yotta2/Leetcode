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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        hm.clear();
        return dfs(s, dict);
    }
private:
    vector<string> dfs(string s, unordered_set<string> &dict) {
        if (hm.find(s) != hm.end())
            return hm[s];
        vector<string> sol;
        if (s.empty()) {
            sol.push_back("");
            hm[s] = sol;
            return sol;
        }
        for (int i = 0; i < s.size(); i++) {
            string first = s.substr(0, i + 1);
            if (dict.find(first) == dict.end())
                continue;
            vector<string> subSol = dfs(s.substr(i + 1), dict);
            conbine(sol, first, subSol);
        }
        hm[s] = sol;
        return sol;
    }
    void conbine(vector<string> &sol, string first, vector<string> &subSol) {
        for (int i = 0; i < subSol.size(); i++)
            if (subSol[i] != "")
                sol.push_back(first + " " + subSol[i]);
            else
                sol.push_back(first);
    }
    typedef unordered_map<string, vector<string> > StringToSolMap;
    StringToSolMap hm;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "123";
    cout << str.substr(3) << endl;
    Solution sol;
    return 0;
}
