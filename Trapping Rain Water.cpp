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
    int trap(int A[], int n) {
        int left = 0;
        while (A[left] == 0 && left < n)
            left++;
        if (left == n)
            return 0;
        int rightEnd = n - 1;
        while (A[rightEnd] == 0)
            rightEnd--;
        int sum = 0;
        while (left < rightEnd) {
            int right = left;
            for (int i = left + 1; i < rightEnd; i++)
                if (A[i] >= A[left]) {
                    right = i;
                    break;
                }
            if (right == left)
                right = findMaxFromIndex(left + 1, A, rightEnd);
            sum += computeTrappedWater(left, right, A);
            left = right;
        }
        return sum;
    }
private:
    int findMaxFromIndex(int index, int A[], int rightEnd) {
        int max = 0;
        int right = index;
        for (int i = index; i <= rightEnd; i++)
            if (A[i] > max) {
                max = A[i];
                right = i;
            }
        return right;
    }
    int computeTrappedWater(int left, int right, int A[]) {
        int lowBar = min(A[left], A[right]);
        int waterCount = 0;
        for (int i = left + 1; i < right; i++)
            waterCount += lowBar - A[i];
        return waterCount;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
