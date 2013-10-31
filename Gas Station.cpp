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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int start = 0;
        while (true) {
            if (start >= N)
                break;
            int curr = start;
            int oil = 0;
            bool triedAll = false;
            while (true) {
                oil += gas[curr];
                if (oil >= cost[curr]) {
                    oil -= cost[curr];
                    curr = (curr + 1) % N;
                    if (curr == 0)
                        triedAll = true;
                    if (curr == start)
                        return start;
                } else {
                    start = curr + 1;
                    break;
                }
            }
            if (triedAll)
                break;
        }
        return -1;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<int> gas({2, 4});
    vector<int> cost({3, 4});
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
