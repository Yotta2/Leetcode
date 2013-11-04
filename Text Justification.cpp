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
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> text;
        int i = 0;
        while (true) {
            if (i >= words.size())
                break;
            int wordCount = 0;
            int wordLenSum = 0;
            vector<string> wordsTmp;
            while (true) {
                if (i >= words.size())
                    break;
                if (wordLenSum + words[i].size() + wordCount > L)
                    break;
                wordLenSum += words[i].size();
                wordCount++;
                wordsTmp.push_back(words[i]);
                i++;
            }
            if (i >= words.size())
                text.push_back(packALine(wordsTmp, wordLenSum, L, true));
            else
                text.push_back(packALine(wordsTmp, wordLenSum, L, false));
        }
        return text;
    }
private:
    string packALine(vector<string> words, int wordLenSum, int L, bool isLastLine) {
        string line;
        if (words.size() == 1) {
            line += words[0];
            while (line.size() < L)
                line += " ";
            return line;
        }
        if (isLastLine) {
            line += words[0];
            for (int i = 1; i < words.size(); i++)
                line += " " + words[i];
            while (line.size() < L)
                line += " ";
            return line;
        } else {
            int wordCount = words.size();
            int spacesNeeded = L - wordLenSum;
            int spacesBase = spacesNeeded / (wordCount - 1);
            int spacesLeft = spacesNeeded - spacesBase * (wordCount - 1);
            line += words[0];
            for (int i = 1; i < words.size(); i++) {
                for (int j = 0; j < spacesBase; j++)
                    line += " ";
                if (spacesLeft != 0) {
                    line += " ";
                    spacesLeft--;
                }
                line += words[i];
            }
            return line;
        }
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "";
    cout << str.size() << endl;
    Solution sol;
    vector<string> words({""});
    sol.fullJustify(words, 2);
    return 0;
}
