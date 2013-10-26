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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        sort(S.begin(), S.end());
        vector<int> subset;
        dfs(S, 0, subset, ans);
        return ans;
    }
private:
    void dfs(vector<int> &S, int index, vector<int> &subset, vector<vector<int> > &ans) {
        if (index == S.size()) {
            ans.push_back(subset);
            return;
        }
        int count = 1;
        int tmp = S[index];
        index++;
        while (true) {
            if (index >= S.size())
                break;
            if (S[index] != S[index - 1])
                break;
            count++;
            index++;
        }
        for (int i = 0; i <= count; i++) {
            for (int j = 1; j <= i; j++)
                subset.push_back(tmp);
            dfs(S, index, subset, ans);
            for (int j = 1; j <= i; j++)
                subset.pop_back();
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
