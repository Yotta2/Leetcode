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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *fastRunner = head;
        ListNode *slowRunner0 = head;
        ListNode *slowRunner1 = head;
        while (true) {
            for (int i = 0; i < 2; i++) {
                fastRunner = fastRunner->next;
                if (fastRunner == NULL)
                    return NULL;
            }
            slowRunner0 = slowRunner0->next;
            if (fastRunner == slowRunner0)
                break;
        }
        while (true) {
            if (slowRunner0 == slowRunner1)
                return slowRunner0;
            slowRunner0 = slowRunner0->next;
            slowRunner1 = slowRunner1->next;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
