// 1988KB, 0ms

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> oprs;

int getprior(char opr) {
	if (opr == '(')
		return 0;

	else if (opr == '+' || opr == '-')
		return 1;

	else //opr == '*' || opr == '/'
		return 2;
}

int main() {

	int len;
	string infix;

	cin >> infix;

	len = infix.length();

	for (int i = 0; i < len; i++) {

		if (infix[i] >= 'A' && infix[i] <= 'Z') 
			cout << infix[i];
		else if (infix[i] == '(')
			oprs.push('(');
		else if (infix[i] == ')') {
			while (oprs.top() != '(') {
				cout << oprs.top();
				oprs.pop();
			}
			oprs.pop();
		}
		else { // +-*/
			if (oprs.empty() || (getprior(infix[i]) > getprior(oprs.top())))
				oprs.push(infix[i]);
			else {
				while (!oprs.empty() && (getprior(infix[i]) <= getprior(oprs.top()))) {
					cout << oprs.top();
					oprs.pop();
				}
				oprs.push(infix[i]);
			}
		}
	}

	while (!oprs.empty()) {
		cout << oprs.top();
		oprs.pop();
	}


	return 0;
}
