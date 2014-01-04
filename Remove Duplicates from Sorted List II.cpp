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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = dummy;
        while (true) {
            if (curr->next == NULL || curr->next->next == NULL)
                break;
            if (curr->next->val == curr->next->next->val) {
                int val = curr->next->val;
                while (curr->next != NULL && curr->next->val == val) {
                    ListNode *tmp = curr->next;
                    curr->next = curr->next->next;
                    delete tmp;
                }
            } else {
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
