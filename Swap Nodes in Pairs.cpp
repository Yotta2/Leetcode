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
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode **curr = &head;
        while (true) {
            if ((*curr)->next == NULL)
                break;
            ListNode *first = *curr;
            ListNode *second = (*curr)->next;
            *curr = second;
            first->next = second->next;
            second->next = first;
            if ((*curr)->next->next == NULL)
                break;
            curr = &((*curr)->next->next);
        }
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
