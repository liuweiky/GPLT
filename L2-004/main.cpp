#include <cstdio>

#define MAX_N 1024

using namespace std;

int N;
int original[MAX_N];

bool is_pre = true, is_mir_pre = true;
int pre_ptr = 0, mir_pre_ptr = 0;

int cnt = 0;

struct node
{
    int key;
    node* l;
    node* r;
    node() {l = r = NULL;}
};

void insert_bst(node* &root, int key)
{
    if (root == NULL)
    {
        root = new node;
        root->key = key;
        return;
    }
    if (key < root->key)
        insert_bst(root->l, key);
    else
        insert_bst(root->r, key);
}

void preorder(node* r)
{
    if (r == NULL || !is_pre)
        return;
    if (r->key != original[pre_ptr++])
    {
        is_pre = false;
        return;
    }
    preorder(r->l);
    preorder(r->r);
}

void premirorder(node* r)
{
    if (r == NULL || !is_mir_pre)
        return;
    if (r->key != original[mir_pre_ptr++])
    {
        is_mir_pre = false;
        return;
    }
    premirorder(r->r);
    premirorder(r->l);
}

void postorder(node* r)
{
    if (r == NULL)
        return;
    postorder(r->l);
    postorder(r->r);
    if (cnt != 0)
        printf(" ");
    printf("%d", r->key);
    cnt++;
}

void postmirorder(node* r)
{
    if (r == NULL)
        return;
    postmirorder(r->r);
    postmirorder(r->l);
    if (cnt != 0)
        printf(" ");
    printf("%d", r->key);
    cnt++;
}

int main()
{
    scanf("%d", &N);

    node* root = NULL;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &original[i]);
        insert_bst(root, original[i]);
    }

    preorder(root);
    if (is_pre)
    {
        printf("YES\n");
        postorder(root);
        return 0;
    }

    premirorder(root);
    if (is_mir_pre)
    {
        printf("YES\n");
        postmirorder(root);
        return 0;
    }

    printf("NO");

    return 0;
}
