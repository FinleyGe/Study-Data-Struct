#include "vector.cpp"
#include <string>
using namespace std;

Vector<int> v;
void print(string msg) {
  cout << msg << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  cout << "size: " << v.size() << endl;
  cout << "capacity: " << v.capacity() << endl;
}
int main() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    v.pushBack(rand() % 1000);
  }
  print("insert 10 random numbers");
  v.insert(3, 2333);
  print("insert 2333 at index 3");
  v.erase(4);
  print("erase the element at index 4");
  v[5] = 666;
  print("set the element at index 5 to 666");
  cout << "Is the vector sorted? " << (v.isSorted() ? "Yes" : "No") << endl;
  v.sort();
  print("sort the vector");
  cout << "Is the vector sorted? " << (v.isSorted() ? "Yes" : "No") << endl;
  return 0;
}
