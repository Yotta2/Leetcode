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
    void init(unordered_map<string, string> &numToRomanMap) {
        numToRomanMap["1"] = "I";
        numToRomanMap["5"] = "V";
        numToRomanMap["10"] = "X";
        numToRomanMap["50"] = "L";
        numToRomanMap["100"] = "C";
        numToRomanMap["500"] = "D";
        numToRomanMap["1000"] = "M";
        numToRomanMap["4"] = "IV";
        numToRomanMap["9"] = "IX";
        numToRomanMap["40"] = "XL";
        numToRomanMap["90"] = "XC";
        numToRomanMap["400"] = "CD";
        numToRomanMap["900"] = "CM";
        numToRomanMap["2"] = "II";
        numToRomanMap["3"] = "III";
        numToRomanMap["20"] = "XX";
        numToRomanMap["30"] = "XXX";
        numToRomanMap["200"] = "CC";
        numToRomanMap["300"] = "CCC";
        numToRomanMap["2000"] = "MM";
        numToRomanMap["3000"] = "MMM";
        numToRomanMap["6"] = "VI";
        numToRomanMap["7"] = "VII";
        numToRomanMap["8"] = "VIII";
        numToRomanMap["60"] = "LX";
        numToRomanMap["70"] = "LXX";
        numToRomanMap["80"] = "LXXX";
        numToRomanMap["600"] = "DC";
        numToRomanMap["700"] = "DCC";
        numToRomanMap["800"] = "DCCC";
    }

    string intToRoman(int num) {
        unordered_map<string, string> numToRomanMap;
        init(numToRomanMap);
        char strTmp[10];
        string ans;
        sprintf(strTmp, "%d", num);
        string str(strTmp);
        for (int i = 0; i < str.size(); i++) {
            int tmp = str[i] - '0';
            tmp = tmp * pow(10, str.size() - i - 1);
            sprintf(strTmp, "%d", tmp);
            string numStr(strTmp);
            ans += numToRomanMap[numStr];
        }
        return ans;
    }
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    stringstream ss;
    int num;
    ss << "323";
    ss >> num;
    cout << num << endl;
    Solution sol;
    cout << sol.intToRoman(1) << endl;
    return 0;
}
