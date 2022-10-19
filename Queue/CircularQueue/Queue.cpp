// Circular Queue
#include <algorithm>
#include <iostream>
template <class T> class Queue {
public:
  // constructor. cap = 5 by default.
  Queue();
  Queue(int);
  ~Queue();

  // EnQueue
  void EnQueue(T);

  // DeQueue. return the Dequeued item.
  T DeQueue();

  // the front item.
  T Front();

  // the back item.
  T Back();

  bool isEmpty();

  // print the queue
  void Print();

private:
  // the queue. A array.
  T *_queue;

  // index of the front item
  int _front;

  // index of the back item
  int _back;

  // the max capacity.
  int _capacity;

  // the current size.
  int _size;
};

template <class T> Queue<T>::Queue() {
  _capacity = 5;
  _queue = new T[_capacity];
  _front = 0;
  _back = 0;
  _size = 0;
}

template <class T> Queue<T>::Queue(int cap) {
  _capacity = cap;
  _queue = new T[_capacity];
  _front = 0;
  _back = 0;
  _size = 0;
}

template <class T> Queue<T>::~Queue() { delete[] _queue; }

template <class T> void Queue<T>::EnQueue(T data) {
  _queue[(_back++) % _capacity] = data;
  _back %= _capacity;
  _size++;
}

template <class T> T Queue<T>::DeQueue() {
  T data = _queue[_front % _capacity];
  _front = (_front + 1) % _capacity;
  _size--;
  return data;
}

template <class T> T Queue<T>::Front() { return _queue[_front % _capacity]; }

template <class T> T Queue<T>::Back() { return _queue[_back % _capacity]; }

template <class T> bool Queue<T>::isEmpty() { return _size == 0; }

template <class T> void Queue<T>::Print() {
  for (int i = 0; i < _size; i++) {
    std::cout << ((_front + i) % _capacity) << "--"
              << _queue[(_front + i) % _capacity] << " ";
  }
  std::cout << std::endl;
  std::cout << "front: " << _front << " back: " << _back << std::endl;
}
