#include <iostream>
template <class T> class Stack {
public:
  // Stack default constructor
  Stack();

  // Stack destructor
  ~Stack();

  // Stack copy constructor. This is a deep copy.
  Stack(const Stack<T> &);

  // Stack move constructor. This is a shallow copy.
  Stack(const Stack<T> &&);

  // Stack assignment operator. This is a deep copy.
  Stack<T> &operator=(const Stack<T> &);

  // Stack move assignment operator. This is a shallow copy.
  Stack<T> &operator=(const Stack<T> &&);
  // Stack push method
  void push(const T &);

  // Stack pop method
  void pop();

  // Stack get the top element method.
  T top() const;

  // Whether the stack empty
  bool empty() const;

  void print() const;

private:
  struct Node {
    T data;
    Node *next;
  };
  Node *_head; // always points to the top of the stack.
};

template <class T> Stack<T>::Stack() {
  _head = new Node;
  _head->next = nullptr;
}

template <class T> Stack<T>::~Stack() {
  if (this->_head == nullptr)
    delete this->_head;
  while (_head->next != nullptr) {
    Node *tmp = _head->next;
    _head->next = tmp->next;
    delete tmp;
  }
}

template <class T> Stack<T>::Stack(const Stack<T> &stack) {
  // deep copy
  this->_head = new Node;
  this->_head->next = nullptr;
  Node *now = this->_head;
  Node *tmp = stack._head->next;
  while (tmp != nullptr) {
    now->next = new Node;
    now = now->next;
    now->data = tmp->data;
    now->next = nullptr;
    tmp = tmp->next;
  }
}

template <class T> Stack<T>::Stack(const Stack<T> &&stack) {
  // shallow copy
  this->_head = stack._head;
  stack._head = nullptr;
}

template <class T> Stack<T> &Stack<T>::operator=(const Stack<T> &stack) {
  // deep copy
  if (this->_head != nullptr)
    delete this->_head;
  this->_head = new Node;
  this->_head->next = nullptr;
  Node *tmp = stack._head->next;
  while (tmp != nullptr) {
    this->push(tmp->data);
    tmp = tmp->next;
  }
  return *this;
}

template <class T> void Stack<T>::push(const T &data) {
  Node *node = new Node; // the new node.
  node->data = data;
  node->next = _head->next; // the new node will always be the top of the stack.
                            // which is means the _head will
                            // always point to the new node.
  _head->next = node;
}

template <class T> void Stack<T>::pop() {
  if (this->empty()) {
    throw "empty!"; // the stack is empty. throw exception.
  }
  Node *node = _head->next;
  _head->next = node->next;
  delete node; // free the memory
}

template <class T> bool Stack<T>::empty() const {
  return _head->next ==
         nullptr; // if _head points to nullptr, the stack is empty.
}

template <class T> T Stack<T>::top() const {
  if (this->empty()) {
    throw "empty!";
  }
  return _head->next->data;
}

template <class T> void Stack<T>::print() const {
  Node *tmp = _head->next;
  while (tmp != nullptr) {
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  }
  std::cout << std::endl;
}
