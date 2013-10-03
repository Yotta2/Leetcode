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
        vector<Interval> ans;
        bool leftInside = false; //the left end side of the newInterval is in side an interval
        int nextIndex;
        Interval mergedInterval;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                leftInside = true;
                nextIndex = i;
                break;
            }
            if (newInterval.start < intervals[i].start) {
                nextIndex = i;
                break;
            }
            ans.push_back(intervals[i]);
        }

        if (leftInside)
            mergedInterval.start = intervals[nextIndex].start;
        else
            mergedInterval.start = newInterval.start;
        bool foundRightPos = false;
        for (int i = nextIndex; i < intervals.size(); i++) {
            if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
                nextIndex = i + 1;
                mergedInterval.end = intervals[i].end;
                foundRightPos = true;
                break;
            }
            if (newInterval.end < intervals[i].start) {
                nextIndex = i;
                mergedInterval.end = newInterval.end;
                foundRightPos = true;
                break;
            }
        }
        if (foundRightPos) {
            ans.push_back(mergedInterval);
            for (int i = nextIndex; i < intervals.size(); i++)
                ans.push_back(intervals[i]);
        } else {
            mergedInterval.end = newInterval.end;
            ans.push_back(mergedInterval);
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
