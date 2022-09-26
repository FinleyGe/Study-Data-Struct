#include "reference.cpp"
#include <algorithm>
#include <stdexcept>

template <class T> class Vector {
public:
  // Default Constructor.
  // A empty vector will be created.
  Vector();

  // Constructor
  //@param int : size of the vector
  Vector(int);

  ~Vector();

  // push a value in the vector.
  // @param T : value to be pushed back
  void pushBack(T);

  // insert a data at a given index.
  bool insert(int, T);

  // delete a data.
  // @return the deleted data.
  T popBack();

  // erase a data by its index.
  // @param int: index of the data.
  bool erase(int);

  // get the size of the vector.
  int size() const;

  // get the capacity of the vector.
  int capacity() const;

  // get the data at a given index.

  Reference<T> getItemByIndex(int);

  Reference<T> operator[](int);

  // get the index of a given data.
  // @param T : data to be searched.
  // @return int : index of the data. -1 for not found.
  int indexOf(T);

  // Sort the vector.
  // By default, ascending order.
  void sort();

  // Sort the vector.
  // @param bool(func): compare two data.
  void sort(bool (*)(T, T));

  // whether the vector is sorted.
  bool isSorted();

private:
  // length of data;
  int _size;
  // capacity of data;
  int _capacity;
  // data
  T *_data;

  // resize the vector.
  // if size == capacity => double the size.
  // else => nothing to do.
  void _resize();
};
template <class T> Vector<T>::Vector() {
  _size = 0;
  _capacity = 0;
  _data = nullptr;
}

template <class T> Vector<T>::Vector(int size) {
  _size = size;
  _capacity = size;
  _data = new T[size];
}

template <class T> Vector<T>::~Vector() { delete[] _data; };

template <class T> void Vector<T>::pushBack(T data) {
  _resize();
  _data[_size++] = data;
}

template <class T> T Vector<T>::popBack() { return _data[_size--]; }

template <class T> bool Vector<T>::insert(int index, T data) {
  if (index < 0 || index > _size)
    return false;
  _resize();
  auto oldData = _data;
  _data = new T[_capacity];
  for (int i = 0; i < index; i++) {
    _data[i] = oldData[i];
  }
  _data[index] = data;
  for (int i = index + 1; i < _size + 1; i++) {
    _data[i] = oldData[i - 1];
  }
  // free old data memory.
  delete oldData;
  _size++;
  return true;
}

template <class T> bool Vector<T>::erase(int index) {
  if (index < 0 || index > _size)
    return false;
  auto oldData = _data;
  _data = new T[_capacity];
  // until the data before the index.
  for (int i = 0; i < index; i++) {
    _data[i] = oldData[i];
  }
  // from the data after the index.
  for (int i = index + 1; i < _size; i++) {
    _data[i - 1] = oldData[i];
  }
  // free old data memory.
  delete oldData;
  _size--;
  return true;
}

template <class T> Reference<T> Vector<T>::getItemByIndex(int index) {
  if (index < 0 || index >= _size) {
    throw std::out_of_range("index out of range");
  }
  auto ref = Reference<T>(_data[index]);
  return ref;
}

template <class T> void Vector<T>::_resize() {
  if (_size != _capacity)
    return;
  if (_capacity == 0)
    _capacity++;
  else
    _capacity *= 2;

  auto oldData = _data;
  _data = new T[_capacity];

  for (int i = 0; i < _size; i++) {
    _data[i] = oldData[i];
  }

  delete oldData;
}

template <class T> int Vector<T>::indexOf(T data) {
  for (int i = 0; i < _size; i++) {
    if (_data[i] == data)
      return i;
  }
  return -1;
}

template <class T> Reference<T> Vector<T>::operator[](int index) {
  return getItemByIndex(index);
}

template <class T> int Vector<T>::size() const { return _size; }

template <class T> int Vector<T>::capacity() const { return _capacity; }

template <class T> void Vector<T>::sort() { std::sort(_data, _data + _size); }

template <class T> void Vector<T>::sort(bool (*func)(T, T)) {
  std::sort(_data, _data + _size, func);
}

template <class T> bool Vector<T>::isSorted() {
  for (int i = 0; i < _size - 1; i++) {
    if (_data[i] > _data[i + 1])
      return false;
  }
  return true;
}
