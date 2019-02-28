#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    int t;
    while (scanf("%d", &t) != EOF)
        v.push_back(t);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
            printf("->");
        printf("%d", v[i]);
    }
    return 0;
}
