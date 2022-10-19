#include "Queue.cpp"
#include <queue>
#include <vector>
using namespace std;
// Base number sort.
void BaseNumberSort(vector<int> &v) {
  queue<int> q[10];
  int base = 1;
  int max = 0;
  // find the max number.
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  // calculate the max number's length.
  int maxDigit = 0;
  while (max) {
    max /= 10;
    maxDigit++;
  }

  for (int i = 0; i < maxDigit; i++) {
    for (int j = 0; j < v.size(); j++) {
      int digit = (v[j] / base) % 10;
      q[digit].push(v[j]);
    }
    int k = 0;
    for (int j = 0; j < 10; j++) {
      while (!q[j].empty()) {
        v[k++] = q[j].front(); // override the raw vector
        q[j].pop();
      }
    }
    base *= 10;
  }
}

int main() {
  Queue<char> q;
  q.EnQueue('A');
  q.EnQueue('B');
  q.EnQueue('C');
  cout << q.Front() << endl;
  q.Print();
  q.DeQueue();
  cout << q.Front() << endl;
  q.Print();
  q.EnQueue('D');
  q.EnQueue('E');
  cout << q.Front() << endl;
  q.Print();
  q.DeQueue();
  q.EnQueue('F');
  cout << q.Front() << endl;
  q.Print();

  cout << "----------------" << endl;
  vector<int> v = {38, 102, 45, 89, 67};

  // srand((unsigned)time(NULL));
  // for (int i = 0; i < 20; i++) {
  //   v.push_back(rand() % 100);
  // }
  cout << "Raw data: " << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  // sort
  BaseNumberSort(v);
  cout << "Sorted data: " << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
