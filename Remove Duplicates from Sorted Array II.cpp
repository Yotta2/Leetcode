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
    int removeDuplicates(int A[], int n) {
        int i = 0;
        int j = 0;
        while (j < n) {
            int count = 1;
            while (j + 1 < n && A[j] == A[j + 1]) {
                j++;
                count++;
            }
            if (count >= 2) {
                A[i] = A[j];
                A[i + 1] = A[j];
                i += 2;
            } else {
                A[i] = A[j];
                i++;
            }
            j++;
        }
        return i;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}