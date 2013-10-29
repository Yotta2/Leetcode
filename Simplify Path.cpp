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
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir = "/";
        dirs.push_back(dir);
        int i = 1;
        if (path[path.size() - 1] != '/')
            path += '/';
        while (i < path.size()) {
            int start = i;
            while (path[i] != '/')
                i++;
            dir = path.substr(start, i - start);
            if (dir == "..") {
                if (dirs.size() != 1)
                    dirs.pop_back();
            } else if (!dir.empty() && dir != ".") {
                dir += "/";
                dirs.push_back(dir);
            }
            i++;
        }
        string simplifiedPath;
        for (int j = 0; j < dirs.size(); j++) {
            simplifiedPath += dirs[j];
        }
        if (simplifiedPath.size() != 1)
            simplifiedPath.resize(simplifiedPath.size() - 1);
        return simplifiedPath;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.simplifyPath("/.hidden") << endl;
    return 0;
}
