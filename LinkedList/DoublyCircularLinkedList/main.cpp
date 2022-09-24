#include "LinkList.h"
#include <iostream>
using namespace std;
// solve the Josephus Problem.
// param a: the amount of nodes.
// param b: erase node every b times.

void testJosephus(int a, int b) {
  LinkList l;
  // insert 41 nodes.
  for (int i = 1; i <= a; i++) {
    l.pushBack(i);
  }

  cout << "initial status:" << endl;
  l.show();
  cout << "-------------------" << endl;

  auto now = l.find(1); // the first node.
  int count = 1;        // count, erase a node when it up to 3
  int times = 0;        // how many nodes were ereased

  while (l.length() > 1) {
    now = now->next;
    if (now == l.head()) {
      now = now->next;
    }
    if (count++ == b) {
      auto duplicateNode = now;
      now = now->next;
      cout << "The No. " << ++times << " will be killed: ";
      duplicateNode->show();
      l.erase(duplicateNode);
      count = 1;
    };
  }
  cout << "The last one: ";
  l.show();
}

int main() {
  LinkList l;
  for (int i = 0; i < 10; i++)
    l.pushBack(i);
  l.show();
  // remove the odds
  for (int i = 0; i < 10; i += 2) {
    l.erase(i);
  }
  cout << endl;
  l.show();

  testJosephus(41, 3);
  return 0;
}
