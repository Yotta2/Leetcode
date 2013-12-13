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

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (keyToItrHM.find(key) == keyToItrHM.end())
            return -1;
        int value = keyToItrHM[key]->value;
        cacheList.erase(keyToItrHM[key]);
        cacheList.push_front(CacheNode(key, value));
        keyToItrHM[key] = cacheList.begin();
        return value;
    }

    void set(int key, int value) {
        if (keyToItrHM.find(key) != keyToItrHM.end()) { // update node
            cacheList.erase(keyToItrHM[key]);
            cacheList.push_front(CacheNode(key, value));
            keyToItrHM[key] = cacheList.begin();
        } else { // insert node
            if (capacity == cacheList.size()) { // cache is full, need to invalidate
                keyToItrHM.erase(cacheList.back().key);
                cacheList.pop_back();
                cacheList.push_front(CacheNode(key, value));
                keyToItrHM[key] = cacheList.begin();
            } else { // cache is not full, insert new node
                cacheList.push_front(CacheNode(key, value));
                keyToItrHM[key] = cacheList.begin();
            }
        }
    }
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {}
    };
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> keyToItrHM;
    int capacity;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //Solution sol;
    return 0;
}
