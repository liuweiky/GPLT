#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    char c;
    string s;
    cin >> N >> c;
    cin.ignore();
    getline(cin, s);

    int sz = s.size();

    if (sz >= N)
        cout << s.substr(sz - N, N);
    else
    {
        for (int i = 1; i + sz <= N; i++)
            cout << c;
        cout << s;
    }

    return 0;
}
