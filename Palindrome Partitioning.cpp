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

class Solution {
public:
    vector<vector<string>> partition(string s) {
        return recPartition(s);
    }
private:
    vector<vector<string> > recPartition(string s) {
        vector<vector<string> > allPartition;
        if (s.empty())
            return allPartition;
        for (int i = 0; i < s.size(); i++) {
            string head = s.substr(0, i + 1);
            if (!isPalindrome(head))
                continue;
            vector<vector<string> > subAllPart = recPartition(s.substr(i + 1));
            merge(allPartition, head, subAllPart);
        }
        return allPartition;
    }
    void merge(vector<vector<string> > &allPartition,
               string head,
               vector<vector<string> > &subAllPart) {
        if (subAllPart.empty()) {
            allPartition.push_back(vector<string>(1, head));
            return;
        }
        for (int i = 0; i < subAllPart.size(); i++) {
            subAllPart[i].insert(subAllPart[i].begin(), head);
            allPartition.push_back(subAllPart[i]);
        }
    }
    bool isPalindrome(string head) {
        int p = 0;
        int q = head.size() - 1;
        while (p <= q) {
            if (head[p] != head[q])
                return false;
            p++;
            q--;
        }
        return true;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    sol.partition("a");
    return 0;
}
