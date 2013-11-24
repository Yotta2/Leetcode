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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<State> q;
        unordered_set<string> visitedWords;
        visitedWords.insert(start);
        q.push(State(start, 1));
        while (!q.empty()) {
            State currState = q.front();
            q.pop();
            for (int i = 0; i < currState.word.size(); i++) {
                string nextWord = currState.word;
                for (char j = 'a'; j <= 'z'; j++) {
                    nextWord[i] = j;
                    if (nextWord == end)
                        return currState.len + 1;
                    if (dict.find(nextWord) != dict.end()
                        && visitedWords.find(nextWord) == visitedWords.end()) {
                        State nextState(nextWord, currState.len + 1);
                        q.push(nextState);
                        visitedWords.insert(nextState.word);
                    }
                }
            }
        }
        return 0;
    }
private:
    struct State {
        string word;
        int len;
        State(string _word, int _len) : word(_word), len(_len) {}
    };
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    return 0;
}
