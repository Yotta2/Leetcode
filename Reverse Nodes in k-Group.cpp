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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len = getLen(head);
        if (len == 0)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int count = 1;
        ListNode *curr = dummy->next;
        ListNode *prev = dummy;
        ListNode *tmp0 = dummy;
        ListNode *tmp1 = dummy->next;
        while (count + k - 1 <= len) {
            while (true) {
                if (count % k == 0)
                    break;
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            ListNode *next = curr->next;
            curr->next = prev;
            tmp0->next = curr;
            tmp1->next = next;
            prev = tmp1;
            curr = next;
            count++;
            tmp0 = prev;
            tmp1 = curr;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
private:
    int getLen(ListNode *head) {
        ListNode *curr = head;
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
