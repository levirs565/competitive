#include <iostream>
#include <vector>

using namespace std;

int main() {
  string pattern;
  cin >> pattern;

  auto pos = pattern.find('*');
  string before = pattern.substr(0, pos), after = pattern.substr(pos + 1);
  int N;
  cin >> N;
  while (N--) {
    string str;
    cin >> str;
    bool match = str.substr(0, min(pos, str.size())) == before &&
                 str.size() >= after.size() &&
                 str.substr(max(str.size() - after.size(), pos)) == after;

    if (match) {
      cout << str << endl;
    }
  }

  return 0;
}