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

#define EPS 1e-6
#define SIZE 110

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int lastPos = n - 1;
        int index = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
            if (A[i] == elem)
                count++;
        while (lastPos >= 0 && A[lastPos] == elem)
            lastPos--;
        if (lastPos == -1)
            return 0;
        while (index < n - count) {
            if (A[index] == elem) {
                swap(A[index], A[lastPos]);
                lastPos--;
                while (A[lastPos] == elem)
                    lastPos--;
            }
            index++;
        }
        return index;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    int A[] = {4, 5};
    int n = 2;
    cout << sol.removeElement(A, n, 4) << endl;
    return 0;
}
