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
    vector<vector<int> > combine(int n, int k) {
        vector<int> soFar;
        vector<vector<int> > ans;
        recGenerate(1, n, k, soFar, ans);
        return ans;
    }
private:
    void recGenerate(int start, int end, int k, vector<int> &soFar, vector<vector<int> > &ans) {
        if (k == 0) {
            ans.push_back(soFar);
            return;
        }
        for (int i = start; i <= end; i++) {
            soFar.push_back(i);
            recGenerate(i + 1, end, k - 1, soFar, ans);
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
