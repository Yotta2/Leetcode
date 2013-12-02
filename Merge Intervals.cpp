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

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        vector<Interval> ans;
        while (i < intervals.size()) {
            Interval mergedInterval(intervals[i].start, intervals[i].end);
            i++;
            while (i < intervals.size()) {
                if (intervals[i].start <= mergedInterval.end)
                    mergedInterval.end = max(intervals[i].end, mergedInterval.end);
                else
                    break;
                i++;
            }
            ans.push_back(mergedInterval);
        }
        return ans;
    }
private:
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start <= b.start;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
