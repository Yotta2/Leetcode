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
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > sortedToAnagramsMap;
        vector<string> ans;
        for (int i = 0; i < strs.size(); i++) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            if (sortedToAnagramsMap.find(sortedStr) != sortedToAnagramsMap.end()) {
                sortedToAnagramsMap[sortedStr].push_back(strs[i]);
            } else {
                vector<string> strsTmp;
                strsTmp.push_back(strs[i]);
                sortedToAnagramsMap[sortedStr] = strsTmp;
            }
        }
        for (unordered_map<string, vector<string> >::iterator itr = sortedToAnagramsMap.begin();
            itr != sortedToAnagramsMap.end(); itr++) {
            vector<string> strsTmp = itr->second;
            if (strsTmp.size() >= 2) {
                for (int i = 0; i < strsTmp.size(); i++)
                    ans.push_back(strsTmp[i]);
            }
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
