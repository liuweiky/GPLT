#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_N 64

using namespace std;

int tree[MAX_N];
bool is_leaf[MAX_N];
int tree_data[MAX_N];
int root = 1;
int N;

void insert_bst(int r, int data)
{
    if (is_leaf[r])
    {
        is_leaf[r] = false;
        tree_data[r] = data;
        return;
    }
    if (data < tree_data[r])
        insert_bst(2 * r + 1, data);
    else
        insert_bst(2 * r, data);
}

void level_order(int n)
{
    queue<int> q;
    q.push(n);
    int cnt = 1;
    while (!q.empty())
    {
        int nn = q.front();
        q.pop();
        if (is_leaf[nn])
            continue;
        printf("%d", tree_data[nn]);
        if (cnt++ != N)
            printf(" ");
        else
            printf("\n");
        q.push(2 * nn);
        q.push(2 * nn + 1);
    }
}

int main()
{
    fill_n(tree, MAX_N, -1);
    fill_n(is_leaf, MAX_N, true);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        insert_bst(root, t);
    }

    level_order(root);

    for (int i = 1; i <= N; i++)
    {
        if (is_leaf[i])
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}
