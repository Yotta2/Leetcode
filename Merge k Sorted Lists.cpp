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
        ListNode *head = new ListNode(0);
        ListNode *curr = head;

        while (true) {
            int emptyCount = 0;
            ListNode **least = NULL;
            for (int i = 0; i < lists.size(); i++)
                if (lists[i] == NULL)
                    emptyCount++;
                else {
                    if (least == NULL)
                        least = &lists[i];
                    else if ((*least)->val > lists[i]->val)
                        least = &lists[i];
                }
            if (emptyCount == lists.size())
                break;
            curr->next = *least;
            curr = curr->next;
            *least = (*least)->next;
        }
        curr = head; // delete dummy
        head = head->next;
        delete curr;
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
