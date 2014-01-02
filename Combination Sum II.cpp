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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<pair<int, int> > numToOccurrenceMap;
        countOccurrence(num, numToOccurrenceMap);
        vector<vector<int> > ans;
        vector<int> soFar;
        dfs(soFar, numToOccurrenceMap, 0, target, ans);
        return ans;
    }
private:
    void countOccurrence(vector<int> &num, vector<pair<int, int> > &numToOccurrenceMap) {
        map<int, int> hm;
        for (int i = 0; i < num.size(); i++)
            hm[num[i]]++;
        for (map<int, int>::iterator itr = hm.begin(); itr != hm.end(); itr++)
            numToOccurrenceMap.push_back(make_pair(itr->first, itr->second));
    }
    void dfs(vector<int> &soFar, vector<pair<int, int> > &numToOccurrenceMap,
             int i, int remaining, vector<vector<int> > &ans) {
        if (remaining == 0)
            ans.push_back(soFar);
        if (i == numToOccurrenceMap.size() || remaining <= 0
            || remaining < numToOccurrenceMap[i].first)
            return;
        for (int j = 0; j <= numToOccurrenceMap[i].second; j++) {
            for (int k = 0; k < j; k++)
                soFar.push_back(numToOccurrenceMap[i].first);
            dfs(soFar, numToOccurrenceMap, i + 1, remaining - numToOccurrenceMap[i].first * j, ans);
            for (int k = 0; k < j; k++)
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
