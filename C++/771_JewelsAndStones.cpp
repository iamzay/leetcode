#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewelTypes(J.begin(), J.end());
        int res = 0;
        for (char c: S) {
            if (jewelTypes.count(c)) {
                ++res;
            }
        }
        return res;
    }
};