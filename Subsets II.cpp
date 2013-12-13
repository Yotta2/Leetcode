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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> soFar;
        recGen(S, 0, soFar, ans);
        return ans;
    }
private:
    void recGen(vector<int> &S, int index, vector<int> &soFar, vector<vector<int> > &ans) {
        if (index == S.size()) {
            ans.push_back(soFar);
            return;
        }
        int tmp = S[index];
        int count = 1;
        index++;
        for (; index < S.size(); index++)
            if (S[index] != S[index - 1])
                break;
            else
                count++;
        for (int i = 0; i <= count; i++) {
            for (int j = 0; j < i; j++)
                soFar.push_back(tmp);
            recGen(S, index, soFar, ans);
            for (int j = 0; j < i; j++)
                soFar.pop_back();
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
