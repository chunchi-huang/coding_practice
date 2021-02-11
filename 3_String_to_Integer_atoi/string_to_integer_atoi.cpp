#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s)
{
    long res = 0;
    int n = s.size(), sign = 1;

    for (int i = 0; i < n;)
    {

        while (s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+')
            sign = s[i++] == '-' ? -1 : 1;

        while (i < n && isdigit(s[i]))
        {
            res = res * 10 + (s[i++] - '0');

            if (res * sign >= INT_MAX)
                return INT_MAX;
            if (res * sign <= INT_MIN)
                return INT_MIN;
        }
        return (int)res * sign;
    }
    return (int)res * sign;
}

int main() {

    string s = "42";
    cout << myAtoi(s) << endl;

}