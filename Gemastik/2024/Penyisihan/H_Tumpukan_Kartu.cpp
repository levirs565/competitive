#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

struct Node {
  Node *prev = nullptr;
  Node *next = nullptr;
  int value;
};

void solution() {
  int N, K;
  cin >> N >> K;

  Node *head = nullptr;
  Node *tail = nullptr;

  map<int, Node *> nodes;
  int nodeCount = N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    Node *node = new Node();
    node->value = a;
    nodes[a] = node;

    if (head == nullptr)
      head = node;
    if (tail != nullptr) {
      tail->next = node;
      node->prev = tail;
    }

    tail = node;
  }

  for (int i = 0; i < K; i++) {
    char t;
    int a;
    cin >> t >> a;

    if (t == 'A') {
      Node *node = new Node();
      node->value = a;
      nodes[a] = node;

      node->next = head;
      head->prev = node;

      head = node;
      nodeCount++;
    } else {
      Node *node = nodes.at(a);

      Node *newTail = node->prev;
      newTail->next = nullptr;
      node->prev = nullptr;

      tail->next = head;
      head->prev = tail;

      head = node;
      tail = newTail;
    }
  }

  cout << nodeCount << endl;
  Node *current = head;
  while (current != nullptr) {
    cout << current->value << " ";
    current = current->next;
  }

  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}