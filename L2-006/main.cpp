#include <cstdio>
#include <queue>

#define MAX_N 36

using namespace std;

int cnt = 0;

struct node
{
    int data;
    node* l;
    node* r;
    node() {l = r = NULL;}
};

int postorder[MAX_N];
int inorder[MAX_N];
int N;

node* rebuild(int pl, int pr, int il, int ir)
{
    if (pl > pr)
        return NULL;
    node* n = new node;
    n->data = postorder[pr];
    int k;
    for (int i = il; i <= ir; i++)
    {
        if (inorder[i] == n->data)
        {
            k = i;
            break;
        }
    }
    n->l = rebuild(pl, pl + k - il - 1, il, k - 1);
    n->r = rebuild(pl + k - il, pr - 1, k + 1, ir);
    return n;
}

void level_order(node* r)
{
    queue<node*> q;
    q.push(r);
    while (!q.empty())
    {
        node* n = q.front();
        q.pop();
        printf("%d", n->data);
        if (++cnt != N)
            printf(" ");
        if (n->l != NULL)
            q.push(n->l);
        if (n->r != NULL)
            q.push(n->r);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &postorder[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);

    node* root = NULL;

    root = rebuild(1, N, 1, N);

    level_order(root);

    return 0;
}
