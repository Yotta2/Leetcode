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

//recursion solution + DP
class Solution0 {
public:
    bool isMatch(const char *s, const char *p) {
        hs.clear();
        string pattern = removeRedundantStar(string(p));
        return recMatch(string(s), pattern);
    }
private:
    string removeRedundantStar(string p) {
        string pattern;
        int i = 0;
        while (true) {
            if (i >= p.size())
                break;
            if (p[i] != '*') {
                pattern += p[i];
                i++;
            }
            else {
                pattern += p[i];
                while (i < p.size()) {
                    if (p[i] != '*')
                        break;
                    i++;
                }
            }
        }
        return pattern;
    }
    bool recMatch(string s, string p) {
        //cout << "s = " << s << " p = " << p << endl;
        if (hs.find(s + "***" + p) != hs.end())
            return false;
        if (s == p)
            return true;
        if (p.empty()) {
            hs.insert(s + "***" + p);
            return false;
        }
        if (s.empty()) {
            for (int i = 0; i < p.size(); i++)
                if (p[i] != '*') {
                    hs.insert(s + "***" + p);
                    return false;
                }
            return true;
        }
        if (p[0] == '*') {
            string sRest = s;
            sRest = sRest.substr(1);
            string pRest = p;
            pRest = pRest.substr(1);
            if (recMatch(s, pRest) || recMatch(sRest, p)) {
                return true;
            } else {
                hs.insert(s + "***" + p);
                return false;
            }
        } else {
            if (s[0] == p[0] || p[0] == '?') {
                string sRest = s;
                sRest = sRest.substr(1);
                string pRest = p;
                pRest = pRest.substr(1);
                if (recMatch(sRest, pRest)) {
                    return true;
                } else {
                    hs.insert(s + "***" + p);
                    return false;
                }
            } else {
                hs.insert(s + "***" + p);
                return false;
            }
        }
    }
    typedef unordered_set<string> UnmatchedSToPSet;
    UnmatchedSToPSet hs;
};

//greedy solution
//Analysis:
//
//For each element in s
//If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
//If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
//If not match, then we check if there is a * previously showed up,
//       if there is no *,  return false;
//       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.
//
//e.g.
//
//abed
//?b*d**
//
//a=?, go on, b=b, go on,
//e=*, save * position star=3, save s position ss = 3, p++
//e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
//d=d, go on, meet the end.
//check the rest element in p, if all are *, true, else false;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Solution sol;
    cout << sol.isMatch("bbbbaababbbbaabaaabbbbbbabbabbaaabaabbbaaaaaababababbbbbaabbaababbbbbabbababbaabaaabbbababaabbabbbaabbbabbbaabbabbbabbbbabbaabbbbbbaabababbaaaababbbaaabbbbaaabbbbabaabaaababbabbbabaaabbbbbbbbaabaabbabb", "b*ab*b****b*a**b**b****abbba**a*baa****b*ab****bbabaaaab***ab****aba***a******aa*ba*bba****aa******b*b**") << endl;
    return 0;
}
