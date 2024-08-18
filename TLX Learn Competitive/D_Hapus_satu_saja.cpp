#include <iostream>
#include <vector>

using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++; j++;
        } else if (i + 1 < a.size() && a[i + 1] == b[j]) {
            i++;
            count++;
        } else if (j + 1 < b.size() && a[i] == b[j + 1]) {
            j++;
            count++;
        } else {
            count = 100;
            break;
        }
    }

    count += a.size() - i + b.size() - j;
    if (count != 1) {
        cout << "Wah, tidak bisa :(";
    } else {
        cout << "Tentu saja bisa!";
    }

    cout << endl;

  return 0;
}