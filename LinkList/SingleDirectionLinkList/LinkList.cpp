#include "LinkList.h"
#include <iostream>
using namespace std;

void Node::operator=(int data) { this->data = data; }

LinkList::LinkList() {
  Node *node = new Node(); // default constructor. data = 0, next = nullptr.
  this->pHead = node;
  this->_length = 0;
}

LinkList::~LinkList() {
  Node *now = this->pHead;
  Node *prev = this->pHead->next;
  if (now->next == nullptr) {
    // pHead -> nullptr. Just delete the pHead.
    delete now;
    return;
  }
  while (now->next != nullptr) { // can free the pHead.
    prev = now;
    now = now->next;
    delete prev;
  }
}

bool LinkList::insert(int index, int data) {
  if (index < 0 || index > this->_length) {
    // index out of range.
    return false;
  }
  Node *node = new Node(data);
  Node *now = this->pHead;
  for (int i = 0; i < index; i++) {
    now = now->next;
  }
  node->next = now->next;
  now->next = node;
  this->_length++;
  return true;
}

bool LinkList::erase(int index) {
  if (index > this->length() || index < 0) { // index out of length
    return false;
  }
  if (index == 0) { // index is 0.
    this->eraseTop();
    return true;
    if (this->length() == 0) { // if the length is 0, there is nothing to erase.
      return false;            // so should return false
    } else {
      return true;
    }
  }

  Node *node = (*this)[index - 1]; // before the deleting node.
  Node *tem = (*this)[index];      // the deleting node.

  node->next = tem->next; // handle the link.
  delete tem;             // free the memory.
  this->_length--;
  return true;
}

void LinkList::eraseTop() {
  if (this->isEmpty()) {
    return; // the list is empty, and nothing happened.
  }
  Node *node = (*this)[0];         // get the first node.
  pHead->next = pHead->next->next; // handle the link.
  this->_length--;
  delete node; // free the memory.
}

bool LinkList::isEmpty() { return pHead->next == nullptr; }

void LinkList::insertTop(int data) {
  Node *node = new Node(data);
  node->next = pHead->next;
  pHead->next = node;
  this->_length++;
}

void LinkList::insertTop(int length, int data[]) {
  for (int i = 0; i < length; i++) {
    insertTop(data[i]);
  }
}

Node *LinkList::getNode(int index) {
  if (index < 0) { // index can not be 0;
                   // return nullptr;
                   // throw "Index can't be negative"; will be better maybe.
    return nullptr;
  }
  Node *now = this->pHead->next;
  if (index > this->length() || index < 0) { // index larger than the length.
    return nullptr;
  }
  for (int i = 0; i < index; i++) {
    now = now->next;
  }
  return now;
}

bool LinkList::deleteFirstNode(int data) {
  Node *now = pHead->next; // Initialize the now as pHead->next,
                           // which is the first node.
  Node *prev = pHead;      // Restore the previous node.
                           // Initial value is pHead.
  while (now != nullptr) {
    if (now->data == data) {
      prev->next = now->next;
      delete now;
      now = prev->next;
      this->_length--; // decrease the length
      return true;
    }
    prev = now;      // do not match,
    now = now->next; // step to the next node.
  }
  return false;
}

void LinkList::sort() { this->selection_sort(); }

void LinkList::swap(Node *a, Node *b) {
  if (a->next == b) {
    // side by side, swap two nearing nodes.
    a->next = b->next;
    b->next->next = a->next;
    a->next->next = b->next->next;
  } else {
    // swap two nodes which are not side by side.
    a->next = b->next;
    b->next->next = a->next->next;
    b->next = a->next;
    a->next->next = b->next->next;
  }
}
void LinkList::selection_sort() {
  Node *beforeStart = pHead; // before the start node.
  // Start from the pHead->next
  while (beforeStart->next) { // loop until the start is nullptr (tail)
    // get the node with minimum data.
    int min = beforeStart->next->data; // the initial min data
    Node *beforeMin = beforeStart;     // Before the Min Node
    Node *beforeNow = beforeStart; // Before the Now Node (in the inner loop)
    while (beforeNow->next) {      // loop until the current node is nullptr
      if (beforeNow->next->data < min) { // find a smaller data
        min = beforeNow->next->data;
        beforeMin = beforeNow; // replace the min node
      }
      beforeNow = beforeNow->next; // step to next node.
    }

    // swap the min node and the start node.

    Node *start = beforeStart->next; // start node which will be the replaced
                                     // node by the min node.
    Node *now = beforeMin->next;     // now node is the min node.
    Node *nowNext =
        now->next; // min node's next node. (min node never be nullptr).
                   // this->swap(beforeStart->next, beforeMin->next);
                   // beforeStart = beforeStart->next;
    if (start == beforeMin) {
      // side by side, swap two nearing nodes.
      beforeStart->next = now;
      now->next = start;
      start->next = nowNext;
      // beforeStart = beforeStart->next
      // this will cause error.
    } else {
      // swap two nodes which are not side by side.
      beforeStart->next = now;
      now->next = start->next;
      beforeMin->next = start;
      start->next = nowNext;
      beforeStart = beforeStart->next; // step to next node
    }
  }
}

Node *LinkList::getTail() const {
  Node *tail = pHead;
  while (tail->next != nullptr)
    tail = tail->next;
  return tail;
}

void LinkList::quick_sort() { this->quick_sort(this->pHead, this->getTail()); }

void LinkList::quick_sort(Node *start, Node *end) {
  if (start == end) {
    return;
  }
  Node *left = start;
  Node *right = end;
  int len = getDistance(left, right);
}

Node *LinkList::findFirstNode(int data) {
  Node *now = pHead->next; // Initialize the now as pHead->next.
  while (now != nullptr) {
    if (now->data == data) {
      return now;
    }
    now = now->next;
  }
  return nullptr;
}

void LinkList::printAllNodes() {
  Node *now = pHead->next;
  if (now == nullptr) {
    cout << "[]" << endl;
    return;
  }
  cout << "[";
  while (now->next != nullptr) {
    cout << "(" << now->data << ", " << now << "), " << endl;
    now = now->next;
  }
  cout << "(" << now->data << ", " << now << ")]" << endl;
}

const bool LinkList::operator==(const LinkList &other) {
  Node *leftNow = this->pHead;       // left of ==
  Node *rightNow = other.getpHead(); // right of ==
  while (leftNow != nullptr &&
         rightNow != nullptr) { // loop until one of them is nullptr.
    if ((leftNow->next == nullptr && rightNow->next != nullptr) ||
        (leftNow->next != nullptr &&
         rightNow->next ==
             nullptr)) { // if one of them is nullptr and an other is not.
      return false;
    }
    if (leftNow->data == rightNow->data) { // if the data is equal.
      leftNow = leftNow->next; // step to next node in the same time.
      rightNow = rightNow->next;
    } else {
      return false; // if one pair data is not equal, return false
    }
  }
  return true;
}

Node *LinkList::operator[](int index) { return this->getNode(index); }

int LinkList::length() const { return this->_length; }

Node *LinkList::getpHead() const { return this->pHead; }

int LinkList::getDistance(Node *a, Node *b) const {
  int count = 0;
  Node *now = a;
  while (a != nullptr and now != b) {
    now = now->next;
    count++;
  }
  return count;
}
