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

/* O(n2)
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            int minHeight = height[i];
            for (int j = i; j < height.size(); j++) {
                minHeight = min(minHeight, height[j]);
                int area = minHeight * (j - i + 1);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};*/

// O(n) too tricky for an interview...
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> s;
        int maxArea = 0;
        for(int i = 0; i < height.size(); i++) {
            if(s.empty() || height[i] > height[s.top()])
                s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                maxArea = max(maxArea, height[tmp] * (s.empty() ? i : i - s.top() - 1));
                i--;
            }
        }
        return maxArea;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<int> height({2,1,5,6,2,3});
    cout << sol.largestRectangleArea(height) << endl;
    return 0;
}
