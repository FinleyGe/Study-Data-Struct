#include "LinkList.h"
#include <iostream>
using namespace std;

void Node::show() { cout << data << " : " << this << endl; }

LinkList::LinkList() {
  _head = new Node;
  _head->next = nullptr;
  _head->prev = nullptr;
  // next -> the first node.
  // prev -> the last node.
  _head->data = 0;
  _length = 0;
}

LinkList::~LinkList() {
  auto now = _head->next;
  while (now != _head && now != nullptr) {
    auto prev = now;
    now = now->next;
    delete prev;
  }
  delete _head;
}

void LinkList::pushBack(Node *node) {
  if (_head->next == nullptr) {
    // this list is empty.
    node->prev = _head;
    _head->next = node;
    node->next = _head;
    _head->prev = node;
    _length++;
    return;
  }
  // this list is not empty.
  auto last = _head->prev;
  last->next = node;
  node->prev = last;
  node->next = _head;
  _head->prev = node;
  _length++;
}

void LinkList::pushBack(int data) {
  auto node = new Node;
  node->data = data;
  pushBack(node);
}

void LinkList::erase(Node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  delete node;
  _length--;
}

void LinkList::erase(int data) {
  auto node = find(data);
  if (node == _head)
    return;
  else
    erase(node);
}

Node *LinkList::find(int data) {
  auto now = _head->next;
  if (now == nullptr) {
    // empty list.
    return _head;
  }
  while (now != _head && now->data != data) {
    now = now->next;
  }
  return now;
}

void LinkList::show() {
  auto now = _head->next;
  if (now == nullptr) {
    // the list is empty.
    cout << "Nothing" << endl;
    return;
  }
  while (now != _head) {
    cout << now->data << " : " << now << endl;
    now = now->next;
  }
}

int LinkList::length() const { return _length; }

const Node *LinkList::head() const { return _head; }
