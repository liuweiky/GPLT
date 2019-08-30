#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
map<string, string> father;
map<string, bool> gender;

int main()
{
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string first, last;
        cin >> first >> last;

        if (last.size() >= 4 && last.substr(last.size() - 4, 4) == "sson")
        {
            gender[first] = true;
            father[first] = last.substr(0, last.size() - 4);
        }
        else if (last.size() >= 7 && last.substr(last.size() - 7, 7) == "sdottir")
        {
            gender[first] = false;
            father[first] = last.substr(0, last.size() - 7);
        }
        else if (last[last.size() - 1] == 'm')
        {
            gender[first] = true;
            father[first] = last.substr(0, last.size() - 1);
        }
        else
        {
            gender[first] = false;
            father[first] = last.substr(0, last.size() - 1);
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        string first1, first2, last1, last2;

        cin >> first1 >> last1 >> first2 >> last2;

        if (gender.find(first1) == gender.end() || gender.find(first2) == gender.end())
        {
            cout << "NA\n";
            continue;
        }
        else if (gender[first1] == gender[first2])
        {
            cout << "Whatever\n";
            continue;
        }

        vector<string> f1, f2;

        f1.push_back(first1);
        f1.push_back(last1);
        f2.push_back(first2);
        f2.push_back(last2);

        string t = last1;

        while (father.find(t) != father.end())
        {
            t = father[t];
            f1.push_back(t);
        }
        t = last2;
        while (father.find(t) != father.end())
        {
            t = father[t];
            f2.push_back(t);
        }

        if (f1.size() < f2.size())
            swap(f1, f2);

        reverse(f1.begin(), f1.end());
        reverse(f2.begin(), f2.end());

        int k = 0;

        /*for (int k = 0; k < f1.size(); k++)
        {
            cout << f1[k] << ' ';
        }

        cout <<endl;
        for (int k = 0; k < f2.size(); k++)
        {
            cout << f2[k] << ' ';
        }*/

        for (k = 0; k < f2.size(); k++)
        {
            if (f1[k] != f2[k])
                break;
        }

        if (k != f2.size())
        {
            if (k == 0)
                cout << "Yes\n";
            else
            {
                k--;
                if (f2.size() - k >= 5)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
        else
            cout << "No\n";

        //cout << endl <<endl;
    }

    return 0;
}
