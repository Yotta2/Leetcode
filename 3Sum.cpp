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
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        int i = 0;
        while (i < num.size()) {
            int a = num[i];
            int target = -a;
            int p = i + 1;
            int q = num.size() - 1;
            while (p < q) {
                if (num[p] + num[q] == target) {
                    vector<int> triplet;
                    triplet.push_back(a);
                    triplet.push_back(num[p]);
                    triplet.push_back(num[q]);
                    ans.push_back(triplet);
                    p++;
                    while (p < num.size() && num[p] == num[p - 1])
                        p++;
                    q--;
                    while (q < num.size() && num[q] == num[q + 1])
                        q--;
                } else if (num[p] + num[q] > target) {
                    q--;
                } else {
                    p++;
                }
            }
            i++;
            while (i < num.size() && num[i] == num[i - 1])
                i++;
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<int> num({-2,0,1,1,2});
    vector<vector<int> > ans = sol.threeSum(num);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    return 0;
}
