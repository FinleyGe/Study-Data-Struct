struct Node {
  // restore data;
  int data;

  // restore the next node, nullptr for the last node.
  Node *next;

  // Constructor of the Node.
  // Set the next as nullptr by default.
  Node() {
    this->data = 0;
    this->next = nullptr;
  }
  // Constructor of Node.
  // Create a new node with a specified data.
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  };
  // Edit the Node.
  void operator=(int data);
};

class LinkList {
public:
  // Constructor of the LinkList. Create the first node (as the last node).
  // Set the data as 0, and the next as nullptr by default.
  LinkList();

  // Destructor of the LinkList.
  ~LinkList();

  // insert a node at a specified position by index.
  // return true for successful insertion.
  // false for failure. (index out of range)
  bool insert(int index, int data);

  // Insert a new node as the head.
  // (Insert the head of the list).
  void insertTop(int data);

  // Insert a sort of nodes by int[] and its length;
  void insertTop(int length, int data[]);

  // Delete the first matching node by data.
  // Return true for delete a node and false for do not delete anything.
  bool deleteFirstNode(int data);

  // Delete the node by index.
  // return true for successful deletion.
  // false for failure. (index out of range)
  bool erase(int index);

  // Delete the head of the list.
  void eraseTop();
  // Find the first matching node.
  // Return the node's address, otherwise return nullptr for do not find.
  Node *findFirstNode(int data);

  // Return the node by index.
  // return nullptr when index is out of length.
  Node *getNode(int index);

  // Print all nodes like [1,2,3]
  // Print [] if the list is empty.
  void printAllNodes();

  // override operator ==. Compare two link list.
  const bool operator==(const LinkList &other);

  // override operator []. Get node by index.
  Node *operator[](int index);

  // Return whether the list is empty.
  bool isEmpty();

  // Sort the list.
  void sort();

  // Getter of pHead.
  Node *getpHead() const;

  // Getter of length.
  int length() const;

  // Get the last node in the list.
  Node *getTail() const;

  // swap two nodes.
  // a: the node before the first node.
  // b: the node before the second node.
  void swap(Node *a, Node *b);

  // swap two nodes by index.
  void swap(int a, int b);
  // compute the distance between two nodes.

  void getDistance(Node *, Node *);

  // get the index of the node.
  int getIndex(Node *node);

private:
  // the node before the head,
  // whose data is always 0,
  // and next is always the head of the list.
  Node *pHead;

  // the length of the link list.
  int _length;

  // selection_sort.
  void selection_sort();

  // quick_sort.
  void quick_sort();

  void quick_sort(Node *, Node *);
};
