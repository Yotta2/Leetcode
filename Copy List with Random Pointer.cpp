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
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        PointerToNoMap hm0;
        NoToPointerMap hm1;
        RandomListNode *clonedHead = new RandomListNode(head->label);
        RandomListNode *curr = head;
        RandomListNode *clonedCurr = clonedHead;
        hm0[head] = 0;
        hm1[0] = clonedHead;
        int count = 1;
        while (true) {
            if (curr->next == NULL)
                break;
            clonedCurr->next = new RandomListNode(curr->next->label);
            hm0[curr->next] = count;
            hm1[count] = clonedCurr->next;
            count++;
            curr = curr->next;
            clonedCurr = clonedCurr->next;
        }
        curr = head;
        clonedCurr = clonedHead;
        while (true) {
            if (curr == NULL)
                break;
            if (curr->random == NULL)
                clonedCurr->random = NULL;
            else
                clonedCurr->random = hm1[hm0[curr->random]];
            curr = curr->next;
            clonedCurr = clonedCurr->next;
        }
        return clonedHead;
    }
private:
    typedef unordered_map<RandomListNode *, int> PointerToNoMap;
    typedef unordered_map<int, RandomListNode *> NoToPointerMap;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
