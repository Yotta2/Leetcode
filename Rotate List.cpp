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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        int listLen = getLen(head);
        k %= listLen;
        ListNode *curr = head;
        ListNode *runner = head;
        for (int i = 0; i < k; i++)
            runner = runner->next;
        while (true) {
            if (runner->next == NULL)
                break;
            curr = curr->next;
            runner = runner->next;
        }
        runner->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
private:
    int getLen(ListNode *head) {
        ListNode *curr = head;
        int len = 0;
        while (curr != NULL) {
            curr = curr->next;
            len++;
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
