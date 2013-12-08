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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (true) {
            int minIndexTmp = -1;
            int minValTmp = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL && lists[i]->val < minValTmp) {
                    minIndexTmp = i;
                    minValTmp = lists[i]->val;
                }
            }
            if (minIndexTmp == -1)
                break;
            curr->next = lists[minIndexTmp];
            curr = curr->next;
            lists[minIndexTmp] = lists[minIndexTmp]->next;
        }
        ListNode *mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
