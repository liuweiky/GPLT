#include <cstdio>
#include <queue>

#define MAX_N 64

using namespace std;

struct node
{
    int data;
    node* l;
    node* r;
    node() {l = r = NULL;}
};

int preorder[MAX_N];
int inorder[MAX_N];

int N;

node* root = NULL;

node* rebuild(int pl, int pr, int il, int ir)
{
    if (pl > pr)
        return NULL;
    node* n = new node;
    n->data = preorder[pl];

    int k;

    for (int i = il; i <= ir; i++)
    {
        if (inorder[i] == n->data)
        {
            k = i;
            break;
        }
    }

    n->l = rebuild(pl + 1, pl + k - il, il, k - 1);
    n->r = rebuild(pl + k - il + 1, pr, k + 1, ir);
    return n;

}

void level_order(node* r)
{
    queue<node*> q;
    q.push(r);
    int cnt = 1;
    while (!q.empty())
    {
        node* rr = q.front();
        q.pop();
        printf("%d", rr->data);
        if (cnt++ != N)
            printf(" ");
        if (rr->r != NULL)
            q.push(rr->r);
        if (rr->l != NULL)
            q.push(rr->l);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &preorder[i]);

    root = rebuild(1, N, 1, N);

    level_order(root);

    return 0;
}
