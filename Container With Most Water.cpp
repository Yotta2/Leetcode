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
    int maxArea(vector<int> &height) {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            if (area > ans)
                ans = area;
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
