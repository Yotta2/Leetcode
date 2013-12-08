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
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > sortedToAnagramsMap;
        for (int i = 0 ; i < strs.size(); i++) {
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            sortedToAnagramsMap[sortedWord].push_back(strs[i]);
        }
        vector<string> ans;
        for (unordered_map<string, vector<string> >::iterator itr = sortedToAnagramsMap.begin();
            itr != sortedToAnagramsMap.end(); itr++) {
            vector<string> words = itr->second;
            if (words.size() >= 2)
                for (int i = 0; i < words.size(); i++)
                    ans.push_back(words[i]);
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
