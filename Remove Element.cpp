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

#define EPS 1e-6
#define SIZE 11000

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int last = n - 1;
        moveToNonElem(A, last, elem);
        while (i <= last) {
            if (A[i] == elem) {
                swap(A[i], A[last]);
                moveToNonElem(A, last, elem);
            }
            i++;
        }
        return i;
    }
    void moveToNonElem(int A[], int &last, int elem) {
        while (last >= 0) {
            if (A[last] != elem)
                break;
            last--;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
