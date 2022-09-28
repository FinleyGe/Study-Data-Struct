#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(100);
  vector<int>::iterator i = v.begin();
  i++;
  i.base();
}
