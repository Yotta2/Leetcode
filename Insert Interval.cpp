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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        bool inserted = false;
        Interval mergedInterval(newInterval.start, newInterval.end);
        vector<Interval> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start)
                ans.push_back(intervals[i]);
            if (intervals[i].start <= newInterval.start
                && newInterval.start <= intervals[i].end)
                mergedInterval.start = min(intervals[i].start, newInterval.start);
            if (intervals[i].start <= newInterval.end
                && newInterval.end <= intervals[i].end) {
                mergedInterval.end = max(intervals[i].end, newInterval.end);
                ans.push_back(mergedInterval);
                inserted = true;
            }
            if (intervals[i].start > newInterval.end) {
                if (!inserted) {
                    ans.push_back(mergedInterval);
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            }
        }
        if (!inserted)
            ans.push_back(mergedInterval);
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 5));
    intervals.push_back(Interval(6, 8));
    Interval newInterval(5, 6);
    sol.insert(intervals, newInterval);
    return 0;
}
