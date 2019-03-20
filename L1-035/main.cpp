#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vs;

int main()
{
    string s;
    cin >> s;

    while (s != ".")
    {
        vs.push_back(s);
        cin >> s;
    }

    if (vs.size() < 2)
        cout << "Momo... No one is for you ...";
    else if (vs.size() < 14)
        cout << vs[1] << " is the only one for you...";
    else
        cout << vs[1] << " and " << vs[13] << " are inviting you to dinner...";

    return 0;
}
