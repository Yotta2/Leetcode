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
    /* Greedy solution: O(n)
    int maxSubArray(int A[], int n) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            currSum += A[i];
            if (currSum > maxSum)
                maxSum = currSum;
            if (currSum < 0)
                currSum = 0;

        }
        return maxSum;
    }*/
    /* Divide and Conquer
     */
    int maxSubArray(int A[], int n) {
        return dac(A, 0, n - 1);
    }
private:
    int dac(int A[], int low, int high) {
        if (low > high)
            return INT_MIN;
        int mid = (low + high) / 2;
        int leftMax = dac(A, low, mid - 1);
        int rightMax = dac(A, mid + 1, high);
        int midMax = A[mid];
        int maxTmp = 0;
        int sum = 0;
        for (int i = mid - 1; i >= low; i--) {
            sum += A[i];
            if (sum > maxTmp)
                maxTmp = sum;
        }
        midMax += maxTmp;
        maxTmp = sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += A[i];
            if (sum > maxTmp)
                maxTmp = sum;
        }
        midMax += maxTmp;
        return max(midMax, max(leftMax, rightMax));
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}

