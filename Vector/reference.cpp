#include <iostream>
using namespace std;
// Reference class
// Provides a way to edit some object.
// In other words, it is an encapsulation for pointers.
// 引用类, 提供修改某个对象的方式. 换言之, 是指针的封装.

template <class T> class Reference {
public:
  // Constructor
  Reference<T>();
  Reference<T>(T &);
  // the data of the reference, can not be edited.
  T data() const;
  // the pointer of the reference. Can be used to edit the data.
  void setData(const T &);
  // Just cout the data.
  friend ostream &operator<<(ostream &, Reference<T>);
  // Assign the data to the reference.
  void operator=(const T &);

private:
  // Pointer to the data.
  T *_ptr;
};

template <class T> Reference<T>::Reference() { _ptr = new T; }

template <class T> Reference<T>::Reference(T &t) { _ptr = &t; }

template <class T> T Reference<T>::data() const { return *_ptr; }

template <class T> void Reference<T>::setData(const T &t) { *_ptr = t; }

ostream &operator<<(ostream &out, Reference<int> r) {
  out << r.data();
  return out;
}

template <class T> void Reference<T>::operator=(const T &t) { setData(t); }
