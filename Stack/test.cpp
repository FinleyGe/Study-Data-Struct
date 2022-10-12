#include "Stack.cpp"
#include <iostream>
#include <vector>
using namespace std;
// print all possible pop orders.
// At every step, we can either pop or push.
// @param Stack<char> input: the input stack.
// @param Stack<char> output: the output stack.
// @param vector<string> result: the result vector.
// @param string ans: the answer now.
// @param int n: the number of elements in the input stack.
void allPosablePop(Stack<char> input, Stack<char> stk, vector<string> &res,
                   string ans, int n) {
  // the input stack is empty. already generate a sequence.
  if (ans.size() == n) {
    res.push_back(ans);
    return;
  }

  Stack<char> stk_tmp(stk); // copy the stack. deep copy.

  // pop
  if (!stk.empty()) {
    string ans_temp = ans + stk.top();
    stk.pop();
    allPosablePop(input, stk, res, ans_temp, n);
  }

  // push
  if (!input.empty()) {
    stk_tmp.push(input.top());
    input.pop();
    allPosablePop(input, stk_tmp, res, ans, n);
  };
}

int main() {
  // test
  Stack<char> stk;

  cout << "Push A, B, C into the stack." << endl;
  stk.push('A');
  stk.push('B');
  stk.push('C');

  cout << "The top of the stack" << endl;
  cout << stk.top() << endl;
  cout << "Pop twice." << endl;

  stk.pop();
  stk.pop();

  cout << "The top of the stack" << endl;
  cout << stk.top() << endl;
  cout << "Push D, E, F into the stack." << endl;
  stk.push('D');
  stk.push('E');
  stk.push('F');
  cout << "The top of the stack" << endl;
  cout << stk.top() << endl;
  cout << "Pop 4 times." << endl;
  for (int i = 0; i < 4; i++) {
    stk.pop();
  }
  cout << "The top of the stack" << endl;
  try {
    cout << stk.top() << endl;
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  // input a string and output all of the possible pop orders.
  cout << "Input a string and output all of the possible pop orders: ";
  string s;
  cin >> s;

  Stack<char> input;
  for (int i = s.size() - 1; i >= 0; i--) {
    input.push(s[i]);
  }

  Stack<char> stk2;

  vector<string> res;
  string ans;
  int n = s.size();
  allPosablePop(input, stk2, res, ans, n);
  cout << "Result:" << endl;
  // for (int i = 0; i < res.size(); i++) {
  //   cout << res[i] << endl;
  // }
  cout << "count:" << res.size() << endl;
  return 0;
}
