#include "Stack.cpp"
#include <string>
using namespace std;
string infixToPostfix(const string &s) {
  Stack<char> st;
  string res;

  for (auto &&c : s) {
    if (c == ' ')
      continue;
    if (c == '(') {
      st.push('(');
    } else if (c == ')') {
      while (!st.empty()) {
        char c = st.top();
        if (c == '(') {
          st.pop();
          break;
        }
        res.push_back(c);
        st.pop();
      }
    } else if (c == '+' || c == '-') {
      st.push(c);
    } else if (c == '*') {
      while (!st.empty()) {
        char c = st.top();
        if (c == '(') {
          break;
        }
        st.pop();
        res.push_back(c);
      }
    } else {
      res += c;
    }
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << infixToPostfix(s) << endl;
  return 0;
}
