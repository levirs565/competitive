#include <iostream>
#include <cstdlib>
#include <memory.h>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int t;
    string str;
    cin >> t;
    cin.ignore();
    getline(cin, str);

    constexpr int charCount = 'z' - 'a' + 1;
    bool has[charCount];
    memset(&has, false, sizeof(has));
    int distinctCount = 0;

    for (const char &ch : str) {
      if (!has[ch - 'a']) {
        has[ch - 'a'] = true;
        distinctCount++;
        if (distinctCount >= charCount)
          break;
      }
    }

    string table = "";
    int charIndex[charCount];
    memset(&charIndex, 0, sizeof(charIndex));

    for (int i = 0; i < charCount; i++)
        if (has[i]) {
            charIndex[i] = int(table.size());
            table += char('a' + i);
        }

    for (char &ch: str) {
        int index = table.size() - 1 - charIndex[ch - 'a'];
        ch = table[index];
    } 

    std::cout << str << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}