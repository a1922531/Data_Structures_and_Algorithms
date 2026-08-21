#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;
  result.reserve(s2.size());

  size_t pos = 0;

  for (size_t i = 1; i <= s2.size(); i++) {
    pos = s1.find(s2.data(), pos, i);
    if (pos == string::npos) {
      result.resize(s2.size(), -1);
      break;
    }
    result.push_back(static_cast<int>(pos));
  }
  return result;
}