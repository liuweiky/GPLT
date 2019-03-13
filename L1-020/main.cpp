#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_ID 102400

using namespace std;

int friends[MAX_ID];
bool queried[MAX_ID];
int N, K, M;
vector<int> ans;

int main()
{
    fill_n(friends, MAX_ID, 0);
    fill_n(queried, MAX_ID, false);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        for (int j = 0; j < K; j++)
        {
            int id;
            scanf("%d", &id);
            friends[id] += (K - 1);
        }
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int id;
        scanf("%d", &id);
        if (friends[id] == 0 && !queried[id])
        {
            ans.push_back(id);
            queried[id] = true;
        }
    }

    if (ans.size() == 0)
        printf("No one is handsome");
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%05d", ans[i]);
        }
    }

    return 0;
}
