#include <iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;
// transform midfix expression to postfix expression.
// the number must be a single digit.
// the expression must be valid.
// only + - * are supported.
string trans(const string &raw) {
  stack<char> stk;            // operator stack
  string res;                 // postfix expression
  for (const char &i : raw) { // analyse every char
    if (i == '(') {           // when it is (, just push it into stack.
      stk.push(i);
    } else if (i == ')') { // when it is ), pop all operators until (.
      while (!stk.empty()) {
        if (stk.top() == '(') {
          stk.pop();
          break;
        } else {
          res += stk.top();
          stk.pop();
        }
      }
    } else if (i == '+' or i == '-' or i == '*') { // when it is operator, pop
                                                   // all operators which have
                                                   // lower priority.
      while (!stk.empty()) {
        if (stk.top() == '(' or (i == '*' and stk.top() != '*'))
          break;
        res += stk.top();
        stk.pop();
      }
      stk.push(i);
    } else { // when it is number, just push it into result.
      res += i;
    }
  }
  // after analysing all chars, pop all operators in stack.
  while (!stk.empty()) {
    res += stk.top();
    stk.pop();
  }
  return res;
}

int main() {

  list<string> listIn = {
      "(1+5-4)*(6-9)",
      "2+3*5+(6+9*4)*4",
      "1+2+3",
      "1+2*5+1",
  };
  list<string> listOut;
  cout << "midfix expressions:" << endl;
  for (const string &i : listIn) {
    cout << i << endl;
  }

  for (auto &&i : listIn) {
    listOut.push_back(trans(i));
  }

  cout << "postfix expressions:" << endl;

  for (auto &&i : listOut) {
    cout << i << endl;
  }
  return 0;
}
