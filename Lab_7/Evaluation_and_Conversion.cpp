#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
int precedence(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}
bool isLeftAssociative(char op) {
    if (op == '^') return false; // ^ is usually right-associative
    return true;
}

// ---------- Postfix Evaluation ----------
long long applyOp(long long a, long long b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                cerr << "Error: Division by zero. Returning 0." << endl;
                return 0;
            }
            return a / b;
        case '^': {
            long long res = 1;
            for (long long i=0;i<b;i++) res *= a;
            return res;
        }
    }
    return 0;
}

// expects tokens separated by spaces; tokens can be integers or single-char operators
bool evalPostfix(const string &expr, long long &outResult) {
    istringstream iss(expr);
    string tok;
    stack<long long> st;
    while (iss >> tok) {
        // check if token is an integer (possibly negative) - try parse
        bool isNumber = true;
        size_t idx = 0;
        if (tok.size() == 0) continue;
        if ((tok[0] == '+' || tok[0] == '-') && tok.size() > 1) idx = 1; // sign
        for (size_t i = idx; i < tok.size(); ++i) {
            if (!isdigit((unsigned char)tok[i])) { isNumber = false; break; }
        }
        if (isNumber) {
            long long val = stoll(tok);
            st.push(val);
        } else if (tok.size() == 1 && isOperator(tok[0])) {
            if (st.size() < 2) {
                cerr << "Error: insufficient operands for operator " << tok << endl;
                return false;
            }
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long r = applyOp(a, b, tok[0]);
            st.push(r);
        } else {
            cerr << "Error: invalid token '" << tok << "'. Tokens must be integers or operators." << endl;
            return false;
        }
    }
    if (st.empty()) { cerr << "Error: empty stack after evaluation." << endl; return false; }
    outResult = st.top(); st.pop();
    if (!st.empty()) {
        cerr << "Warning: extra operands left in stack after evaluation." << endl;
    }
    return true;
}

// ---------- Infix to Postfix ----------
string infixToPostfix(const string &infix) {
    string output;
    stack<char> ops;
    // tokenization: we will treat multi-digit numbers as operands, and letters as operands
    for (size_t i = 0; i < infix.size(); ) {
        char c = infix[i];
        if (isspace((unsigned char)c)) { i++; continue; }
        // operand: letter or digit sequence
        if (isalpha((unsigned char)c) || isdigit((unsigned char)c)) {
            // read whole operand (letters/numbers)
            size_t j = i;
            string operand;
            while (j < infix.size() && (isalpha((unsigned char)infix[j]) || isdigit((unsigned char)infix[j]))) {
                operand.push_back(infix[j]);
                j++;
            }
            if (!output.empty()) output.push_back(' ');
            output += operand;
            i = j;
        } else if (c == '(') {
            ops.push(c);
            i++;
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(' ');
                output.push_back(ops.top());
                ops.pop();
            }
            if (!ops.empty() && ops.top() == '(') ops.pop();
            i++;
        } else if (isOperator(c)) {
            // operator
            char op1 = c;
            while (!ops.empty() && isOperator(ops.top())) {
                char op2 = ops.top();
                int p2 = precedence(op2), p1 = precedence(op1);
                if ((p2 > p1) || (p2 == p1 && isLeftAssociative(op1))) {
                    // pop op2
                    output.push_back(' ');
                    output.push_back(op2);
                    ops.pop();
                } else break;
            }
            ops.push(op1);
            i++;
        } else {
            // unknown character
            // we'll skip unknown but could also error
            i++;
        }
    }
    while (!ops.empty()) {
        if (ops.top() != '(' && ops.top() != ')') {
            output.push_back(' ');
            output.push_back(ops.top());
        }
        ops.pop();
    }
    // trim leading space
    if (!output.empty() && output[0] == ' ') output.erase(output.begin());
    return output;
}

// ---------- Menu ----------
int main() {
    cout << "=== Stack Applications Lab ===\n";
    cout << "1) Evaluate Postfix expression\n2) Convert Infix to Postfix\n0) Exit\n";
    int choice;
    while (true) {
        cout << "\nEnter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of line
        if (choice == 0) { cout << "Goodbye.\n"; break; }
        if (choice == 1) {
            cout << "Enter postfix expression (tokens separated by spaces). Example: 5 3 1 * + 9 -\n";
            string line;
            getline(cin, line);
            long long result;
            bool ok = evalPostfix(line, result);
            if (ok) cout << "Result: " << result << "\n";
            else cout << "Evaluation failed. See errors above.\n";
        } else if (choice == 2) {
            cout << "Enter infix expression. Example: A + B * (C - D)\n";
            string line;
            getline(cin, line);
            string postfix = infixToPostfix(line);
            cout << "Postfix: " << postfix << "\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
