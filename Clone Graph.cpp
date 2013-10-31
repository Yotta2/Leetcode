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

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        unordered_set<UndirectedGraphNode *> visited;
        LabelToNodeMap hm;
        UndirectedGraphNode *clonedNode = new UndirectedGraphNode(node->label);
        hm[clonedNode->label] = clonedNode;
        dfs(node, clonedNode, visited, hm);
        return clonedNode;
    }
private:
    typedef unordered_map<int, UndirectedGraphNode*> LabelToNodeMap;
    void dfs(UndirectedGraphNode *node,
             UndirectedGraphNode *clonedNode,
             unordered_set<UndirectedGraphNode *> &visited,
             LabelToNodeMap &hm) {
        visited.insert(node);
        for (int i = 0; i < node->neighbors.size(); i++) {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            UndirectedGraphNode *clonedNeighbor = NULL;
            if (hm.find(neighbor->label) == hm.end()) {
                clonedNeighbor = new UndirectedGraphNode(neighbor->label);
                hm[clonedNeighbor->label] = clonedNeighbor;
            } else {
                clonedNeighbor = hm[neighbor->label];
            }
            clonedNode->neighbors.push_back(clonedNeighbor);
            if (visited.find(neighbor) == visited.end())
                dfs(neighbor, clonedNeighbor, visited, hm);
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
