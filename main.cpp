#include <iostream>
#include "LinkList.h"
using namespace std;

void test() {
  LinkList l1;
  LinkList l2;
  LinkList l3;
  LinkList l4;
  int v1[] = {1, 2, 3};
  int v2[] = {1, 2, 3};
  int v3[] = {1, 2, 4};
  int v4[] = {1, 2, 3, 4};
  l1.insertTop(3, v1);
  l2.insertTop(3, v2);
  l3.insertTop(3, v3);
  l4.insertTop(4, v4);
  cout << "l1: ";
  l1.printAllNodes();
  cout << "l2: ";
  l2.printAllNodes();
  cout << "l3: ";
  l3.printAllNodes();
  cout << "l4: ";
  l4.printAllNodes();
  cout << "l1 == l2 " << ((l1 == l2) ? "true" : "false") << endl;
  cout << "l2 == l3 " << ((l2 == l3) ? "true" : "false") << endl;
  cout << "l1 == l3 " << ((l1 == l3) ? "true" : "false") << endl;
  cout << "l1 == l4 " << ((l1 == l4) ? "true" : "false") << endl;
}

int main() {
  string command;
  int data = 0;
  LinkList *list = new LinkList;
  while (true) {
    cout << "> ";
    cin >> command;
    if (command == "exit") {
      delete list;
      cout << "Bye!" << endl;
      return 0;
    } else if (command == "insert") {
      cin >> data;
      list->insertTop(data);
    } else if (command == "insertAt") {
      int index;
      cin >> index >> data;
      cout << list->insert(index, data) << endl;
    } else if (command == "insertLot") {
      int n;
      cin >> n;
      int m;
      while (n--) {
        cin >> m;
        list->insertTop(m);
      }
    } else if (command == "deleteAt") {
      int index;
      cin >> index;
      cout << list->erase(index) << endl;
    } else if (command == "edit") {
      int index;
      cin >> index >> data;
      *((*list)[index]) = data;
    } else if (command == "show") {
      list->printAllNodes();
    } else if (command == "delete") {
      cin >> data;
      cout << (list->deleteFirstNode(data) ? "Deleted!" : "Did not delete!")
           << endl;
    } else if (command == "find") {
      cin >> data;
      Node *node = list->findFirstNode(data);
      if (node != nullptr) {
        cout << node << endl;
      } else {
        cout << "Did not find" << endl;
      }
    } else if (command == "test") {
      test();
    } else if (command == "empty") {
      cout << (list->isEmpty() ? "true" : "false") << endl;
    } else if (command == "sort") {
      list->sort();
    } else {
      cout << "Wrong command" << endl;
    }
  }
  return 0;
}
