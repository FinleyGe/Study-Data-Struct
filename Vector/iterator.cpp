#include "reference.cpp"
template <class T> class Iterator {
public:
  // go to next;
  void next();

  // go to next n;
  void next(int);

  // go to prev;
  void prev();

  // go to prev n;
  void prev(int);

  // next
  void operator++();

  // prev
  void operator--();

  // next n
  void operator+=(int);

  // prev n
  void operator-=(int);

  // return reference
  Reference<T> &data() const;

  // return reference
  Reference<T> &operator*() const;

private:
  T *now;
};
