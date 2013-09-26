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
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        int i = 0;
        int a, b, c;
        while (i < num.size()) {
            unordered_map<int, int> valueToIndexHm;
            unordered_set<int> cSet;
            a = num[i];
            int sum = -a;
            for (int j = i + 1; j < num.size(); j++)
                if (valueToIndexHm.find(num[j]) != valueToIndexHm.end())
                    cSet.insert(num[j]);
                else
                    valueToIndexHm[sum - num[j]] = j;
            addSolutions(ans, a, cSet);
            i++;
            i = findNextAIndex(i, num);
        }
        return ans;
    }

    void addSolutions(vector<vector<int> > &ans, int a, unordered_set<int> &cSet) {
        for (unordered_set<int>::iterator itr = cSet.begin(); itr != cSet.end(); itr++) {
            int c = *itr;
            int b = 0 - a - c;
            vector<int> sol;
            sol.push_back(a);
            sol.push_back(b);
            sol.push_back(c);
            ans.push_back(sol);
        }
    }

    int findNextAIndex(int i, vector<int> &num) {
        while (i < num.size()) {
            if (num[i] == num[i - 1])
                i++;
            else
                break;
        }
        return i;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
