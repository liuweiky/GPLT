#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int ptr = 0;

    while (ptr < str.size())
    {
        if (str[ptr] != '6')
        {
            ptr++;
            continue;
        }

        int p = ptr + 1;
        while (p < str.size() && str[p] == '6')
            p++;

        if (p - ptr > 3 && p - ptr <= 9)
        {
            str = str.replace(ptr, p - ptr, "9");
            //cout << str << endl;
            ptr++;
        }
        else if (p - ptr > 9)
        {
            str = str.replace(ptr, p - ptr, "27");
            //cout << str << endl;
            ptr += 2;
        }
        else
            ptr = p;
    }

    cout << str;

    return 0;
}
