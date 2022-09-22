#include <iostream>
using namespace std;
// Node struct

struct Node {
  int data;
  Node *next; // the next node
  Node *prev; // the previous node

  // default constructor
  Node();
  // constructor.
  // @param: int data
  Node(int);

  // opreator<<
  // cout << node will output the date of node.
  friend ostream &operator<<(ostream &, Node *);
};

class LinkList {
public:
  // Default constructor.
  LinkList();

  // Destructor
  ~LinkList();

  // push a node into the list at the top.
  void push_back(Node *);

  // push
  void push_back(int);

  // delete by index
  bool eraseAt(int);

  // delete by data
  bool erase(int);

  // find

  Node *find(int);

  // sort

  void sort();
  // print all node

private:
  // the head and the tail of the list. do not restore any data.
  Node *_head;
  Node *_tail;

  // the length of the list.
  int _length;
};
