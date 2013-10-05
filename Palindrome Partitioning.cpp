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

class Solution {
public:
    vector<vector<string> > partition(string s) {
        return recPartition(s);
    }
private:
    vector<vector<string> > recPartition(string s) { //can use dp to speed up
        if (s.empty())
            return vector<vector<string> >(1, vector<string>());
        vector<vector<string> > ans;
        for (int i = 0; i < s.size(); i++) {
            string head = s.substr(0, i + 1);
            if (isPalindrome(head)) {
                string rest = s.substr(i + 1);
                vector<vector<string> > tmp = recPartition(rest);
                insertHead(head, tmp);
                merge(ans, tmp);
            }
        }
        return ans;
    }
    void merge(vector<vector<string> > &ans, vector<vector<string> > &tmp) {
        for (int i = 0; i < tmp.size(); i++)
            ans.push_back(tmp[i]);
    }
    bool isPalindrome(string str) {
        int p = 0;
        int q = str.size() - 1;
        while (p <= q) {
            if (str[p] != str[q])
                return false;
            p++;
            q--;
        }
        return true;
    }
    void insertHead(string head, vector<vector<string> > &tmp) {
        for (int i = 0; i < tmp.size(); i++)
            tmp[i].insert(tmp[i].begin(), head);
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    sol.partition("a");
    return 0;
}

