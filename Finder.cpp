#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    const size_t n = s2.size(), m = s1.size();
    vector<int> result(n, -1);
    if (n == 0) return result;

    // prefix function (failure table) of s2
    vector<size_t> fail(n, 0);
    for (size_t i = 1; i < n; ++i) {
        size_t k = fail[i - 1];
        while (k > 0 && s2[i] != s2[k]) k = fail[k - 1];
        if (s2[i] == s2[k]) ++k;
        fail[i] = k;
    }

    size_t k = 0, best = 0;
    for (size_t j = 0; j < m; ++j) {
        while (k > 0 && s1[j] != s2[k]) k = fail[k - 1];
        if (s1[j] == s2[k]) ++k;

        if (k > best) {                              // new longest prefix seen
            best = k;
            result[k - 1] = static_cast<int>(j - k + 1);
            if (best == n) break;                    // nothing longer to find
        }
        if (k == n) k = fail[k - 1];
    }
    return result;
}