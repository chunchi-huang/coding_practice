#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
    stack<char> buf;

    for (auto c : s)
    {
        if (c == '(')
            buf.push(')');
        else if (c == '{')
            buf.push('}');
        else if (c == '[')
            buf.push(']');
        else
        {
            if (buf.empty() || buf.top() != c)
                return false;
            else
                buf.pop();
        }
    }

    return buf.empty();
}

int main()
{
    string s = "()[]{}";
    bool ans = true;
    bool output = isValid(s);
    
    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}