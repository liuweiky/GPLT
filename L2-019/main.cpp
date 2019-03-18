#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

set<string> follows;
map<string, int> likes;

int N, M;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        char inbuf[16];
        scanf("%s", inbuf);
        follows.insert(inbuf);
    }

    int total = 0;

    scanf("%d", &M);

    for (int i = 0;i < M; i++)
    {
        char inbuf[16];
        int cnt;
        scanf("%s %d", inbuf, &cnt);
        total += cnt;
        likes[inbuf] = cnt;
    }

    double avg = (double) total / M;

    vector<string> ans;

    for (map<string, int>::iterator it = likes.begin(); it != likes.end(); it++)
    {
        if (follows.find(it->first) == follows.end() && it -> second > avg)
            ans.push_back(it->first);
    }

    if (ans.size() == 0)
        printf("Bing Mei You");
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
                printf("\n");
            printf("%s", ans[i].c_str());
        }
    }

    return 0;
}
