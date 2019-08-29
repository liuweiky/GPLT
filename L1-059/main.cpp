#include <iostream>

using namespace std;

void judge(string str)
{
    if (str.find("ong,") != string::npos && str.find("ong.") != string::npos)
    {
        int cnt = 0, i;
        for (i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == ' ')
                cnt++;
            if (cnt == 3)
                break;
        }

        str = str.replace(str.begin() + i + 1, str.end(), "qiao ben zhong.");
        cout << str << endl;
    }
    else
        cout << "Skipped" << endl;
}

int main()
{
    string str;
    int N;
    cin >> N;

    getline(cin, str);
    while (N--)
    {
        getline(cin, str);
        judge(str);
    }

    return 0;
}
