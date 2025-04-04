#include <iostream>
#include <vector>
#include <set>

using namespace std;

int xA, xB;
vector<int> A, B;
set<int> akhir;

void bruteforce(int hari) {
  if (hari == 5) {
    akhir.insert(xA);
    return;    
  }

  int oldXa = xA, oldXb = xB;
  if (hari % 2 == 1) {
    for (int i = 0; i < A.size(); i++) {
      xA = oldXa;
      xB = oldXb;
      int v = A[i];
      A.erase(A.begin() + i);
      int count = min(xA, v);
      xA -= count;
      xB += count;
      B.push_back(v);
      bruteforce(hari + 1);
      B.pop_back();
      A.insert(A.begin() + i, v);
    }
  } else if (hari % 2 == 0) {
    for (int i = 0; i < B.size(); i++) {
      xA = oldXa;
      xB = oldXb;
      int v = B[i];
      B.erase(B.begin() + i);
      int count = min(xB, v);
      xB -= count;
      xA += count;
      A.push_back(v);
      bruteforce(hari + 1);
      A.pop_back();
      B.insert(B.begin() + i, v);
    }
  }
}

void solution() {
    int nA, nB;
    cin >> nA >> nB;

    A.resize(nA);
    B.resize(nB);

    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;

    xA = 1000;
    xB = 1000;
    bruteforce(1);

    cout << akhir.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}