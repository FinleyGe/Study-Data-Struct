#include "LinkList.h"

Node::Node() {
  this->data = 0;
  this->next = nullptr;
  this->prev = nullptr;
}

Node::Node(int data) {
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}

LinkList::LinkList() {
  _head = new Node;
  _tail = new Node;
  _head->next = _tail;
  _tail->prev = _head;
  _length = 0;
}

LinkList::~LinkList() {
  auto now = _head;
  while (now != nullptr) {
    Node *prev = now;
    delete prev;
    now = now->next;
  }
}

void LinkList::push_back(Node *node) {
  auto prevTail = _tail->prev;
  prevTail->next = node;
  node->next = _tail;
  _tail->prev = node;
}

void LinkList::push_back(int data) {
  auto node = new Node(data);
  this->push_back(node);
}
