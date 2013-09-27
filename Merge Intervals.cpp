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
 * Definition for an interval. */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.size() == 0)
            return ans;
        Interval tmp(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); i++)
            if (tmp.end >= intervals[i].start) {
                tmp.end = max(tmp.end, intervals[i].end);
            } else {
                ans.push_back(tmp);
                tmp = intervals[i];
            }
        ans.push_back(tmp);
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    Interval interval(3, 3);
    vector<Interval> intervals;
    intervals.push_back(interval);
    interval.start = 3;
    interval.end = 4;
    intervals.push_back(interval);
    intervals.push_back(interval);
    vector<Interval> ans = sol.merge(intervals);
    return 0;
}
