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

//my solution, TLE...
class Solution0 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ans;
        int minLen = INT_MAX;
        queue<State> q;
        State currState;
        currState.word = start;
        q.push(currState);
        while (!q.empty()) {
            currState = q.front();
            q.pop();
            if (currState.changes.size() >= minLen)
                continue;
            bool found = false;
            for (int i = 0; i < currState.word.size(); i++) {
                if (found)
                    break;
                for (int j = 0; j < 26; j++)
                    if (currState.word[i] != 'a' + j) {
                        State nextState = currState;
                        nextState.word[i] = 'a' + j;
                        if (dict.find(nextState.word) == dict.end())
                            continue;
                        nextState.changes.push_back(Change(i, 'a' + j));
                        if (nextState.word == end) {
                            found = true;
                            minLen = nextState.changes.size();
                            ans.push_back(getPath(start, nextState.changes));
                            break;
                        }
                        if (visisted.find(nextState) == visisted.end()) {
                            q.push(nextState);
                            visisted.insert(nextState);
                        }
                    }
            }

        }
        return ans;
    }
private:
    struct Change{
        int index;
        char ch;
        Change(int _index, char _ch) : index(_index), ch(_ch) {}
    };
    struct State {
        string word;
        vector<Change> changes;
        bool operator<(const State &rhs) const {
            return word < rhs.word;
        }
    };
    class StateKeyHash {
    public:
        size_t operator () (const State &state) const {
            return hash<string>()(state.word);
        }
    };

    class StateKeyEqual {
    public:
        bool operator () (const State &state1, const State &state2) const {
            return state1.word == state2.word;
        }
    };
    unordered_set<State, StateKeyHash, StateKeyEqual> visisted;
    vector<string> getPath(string &start, vector<Change> &changes) {
        vector<string> path;
        path.push_back(start);
        string word = start;
        for (int i = 0; i < changes.size(); i++) {
            word[changes[i].index] = changes[i].ch;
            path.push_back(word);
        }
        return path;
    }
};

// found in the internet, tricky one
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pathes.clear();
        dict.insert(start);
        dict.insert(end);
        vector<string> prev;
        unordered_map<string, vector<string> > traces;
        for (unordered_set<string>::const_iterator citr = dict.begin();
                citr != dict.end(); citr++) {
            traces[*citr] = prev;
        }

        vector<unordered_set<string> > layers(2);
        int cur = 0;
        int pre = 1;
        layers[cur].insert(start);
        while (true) {
            cur = !cur;
            pre = !pre;
            for (unordered_set<string>::const_iterator citr = layers[pre].begin();
                    citr != layers[pre].end(); citr++)
                dict.erase(*citr);
            layers[cur].clear();
            for (unordered_set<string>::const_iterator citr = layers[pre].begin();
                    citr != layers[pre].end(); citr++) {
                for (int n=0; n<(*citr).size(); n++) {
                    string word = *citr;
                    int stop = word[n] - 'a';
                    for (int i=(stop+1)%26; i!=stop; i=(i+1)%26) {
                        word[n] = 'a' + i;
                        if (dict.find(word) != dict.end()) {
                            traces[word].push_back(*citr);
                            layers[cur].insert(word);
                        }
                    }
                }
            }
            if (layers[cur].size() == 0)
                return pathes;
            if (layers[cur].count(end))
                break;
        }
        vector<string> path;
        buildPath(traces, path, end);

        return pathes;
    }

    private:
        void buildPath(unordered_map<string, vector<string> > &traces,
                vector<string> &path, const string &word) {
            if (traces[word].size() == 0) {
                path.push_back(word);
                vector<string> curPath = path;
                reverse(curPath.begin(), curPath.end());
                pathes.push_back(curPath);
                path.pop_back();
                return;
            }

            const vector<string> &prevs = traces[word];
            path.push_back(word);
            for (vector<string>::const_iterator citr = prevs.begin();
                    citr != prevs.end(); citr++) {
                buildPath(traces, path, *citr);
            }
            path.pop_back();
        }

        vector<vector<string> > pathes;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
