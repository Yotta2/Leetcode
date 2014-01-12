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
    int minDistance(string word1, string word2) {
        word1.insert(word1.begin(), '/');
        word2.insert(word2.begin(), '/');
        vector<vector<int> > f(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word1.size(); i++)
            for (int j = 0; j < word2.size(); j++) {
                if (i == 0)
                    f[i][j] = j;
                else if (j == 0)
                    f[i][j] = i;
                else if (word1[i] == word2[j])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1])) + 1;
            }
        return f[word1.size() - 1][word2.size() - 1];
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

