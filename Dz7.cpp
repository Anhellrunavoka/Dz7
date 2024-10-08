#include <iostream>
#include <stack>
using namespace std;
bool Pair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}
void print(string text) {
    stack<char> stac;
    string res;
    for (auto i : text) {
            if (i == '{' || i == '(' || i == '[' ) stac.push(i);
            else if (i == '}' || i == ')' || i == ']') {
                if (!stac.empty() && Pair(stac.top(), i)) {
                    stac.pop();
                }
                else {
                    cout << "Error:duzhka not in its place " << res.length() + 1 << endl;
                    return;
                }
            }
            res += i;
    }
    cout << res << endl;
    if (stac.empty()) {
        cout << "All correct" << endl;
    }
    else {
        cout << "Error: not closed duzhki" << endl;
    }
}
int main()
{
    print("({x-y-z} * [x + 2y] - (z + 4x))");
    print("({x-y-z] * [x + 2y) - (z + 4x})");
}
