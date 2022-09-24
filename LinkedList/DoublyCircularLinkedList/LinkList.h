// Node
struct Node {
  int data;
  Node *prev, *next;
  // print this node
  void show();
};

// LinkList
class LinkList {
public:
  // constructor
  LinkList();

  // destructor
  ~LinkList();

  // push a node to the list.
  void pushBack(Node *);

  // push a node with data.
  void pushBack(int);

  // erase a node from the list.
  void erase(Node *);

  // erase a node by data.
  void erase(int);

  // get the first node by given data
  Node *find(int);

  // show all nodes
  void show();

  // return the length of the list.
  int length() const;

  // return the _head of the list.
  const Node *head() const;

private:
  // the head node.
  // do not have illegal data.
  // do not in the circular list.
  // the prev of _head will always be nullptr.
  Node *_head;

  // the length of the list.
  int _length;
};
