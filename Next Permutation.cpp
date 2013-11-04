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

/*  O(n2) solution
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (isMax(num)) {
            sort(num.begin(), num.end());
            return;
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            int j = i + 1;
            bool found = false;
            int smallest;
            int index;
            while (j < num.size()) {
                if (num[j] > num[i]) {
                    if (found == false) {
                        smallest = num[j];
                        index = j;
                    } else if (smallest > num[j]) {
                        smallest = num[j];
                        index = j;
                    }
                    found = true;
                }
                j++;
            }
            if (found) {
                swap(num[index], num[i]);
                sort(num.begin() + i + 1, num.end());
                break;
            }
        }
    }
private:
    bool isMax(vector<int> &num) {
        for (int i = 0; i + 1 < num.size(); i++)
            if (num[i] < num[i + 1])
                return false;
        return true;
    }
};
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (isMax(num)) {
            reverse(num.begin(), num.end());
            return;
        }
        for (int i = num.size() - 2; i >= 0; i--)
            if (num[i] < num[i + 1]) {
                for (int j = num.size() - 1; j > i; j--)
                    if (num[j] > num[i]) {
                        swap(num[j], num[i]);
                        reverse(num.begin() + i + 1, num.end());
                        return;
                    }
            }
    }
private:
    bool isMax(vector<int> &num) {
        for (int i = 0; i + 1 < num.size(); i++)
            if (num[i] < num[i + 1])
                return false;
        return true;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
