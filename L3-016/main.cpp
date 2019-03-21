#include <iostream>
#include <sstream>
#include <queue>
#include <utility>
#include <map>

#define MAX_N 128

using namespace std;

struct node
{
    int data;
    node* lc;
    node* rc;
    node() {lc = rc = NULL;}
};

int N, M;
node* root = NULL;
bool is_sib = false;
bool has_bfs = false;
bool is_par = false;
bool is_lc = false;
bool is_rc = false;
map<int, int> levels;

void insert_bin(node* & r, int data)
{
    if (r == NULL)
    {
        r = new node;
        r->data = data;
        return;
    }
    if (data < r->data)
        insert_bin(r->lc, data);
    else
        insert_bin(r->rc, data);
}

void sib(int s1, int s2, node* r)
{
    if (r == NULL)
        return;
    if (r->lc != NULL && r->rc != NULL && ((r->lc->data == s1 && r->rc->data == s2) ||(r->lc->data == s2 && r->rc->data == s1)))
    {
        is_sib = true;
        return;
    }
    if (!is_sib)
        sib(s1, s2, r->lc);
    if (!is_sib)
        sib(s1, s2, r->rc);
}

void par(int s1, int s2, node* r)
{
    if (r == NULL)
        return;
    if (r->data == s1 && ((r->lc != NULL && r->lc->data == s2) || (r->rc != NULL && r->rc->data == s2)))
    {
        is_par = true;
        return;
    }
    if (!is_par)
        par(s1, s2, r->lc);
    if (!is_par)
        par(s1, s2, r->rc);
}

void islc(int s1, int s2, node* r)
{
    if (r == NULL)
        return;
    if (r->data == s2 && (r->lc != NULL && r->lc->data == s1))
    {
        is_lc = true;
        return;
    }
    if (!is_lc)
        islc(s1, s2, r->lc);
    if (!is_lc)
        islc(s1, s2, r->rc);
}

void isrc(int s1, int s2, node* r)
{
    if (r == NULL)
        return;
    if (r->data == s2 && (r->rc != NULL && r->rc->data == s1))
    {
        is_rc = true;
        return;
    }
    if (!is_rc)
        isrc(s1, s2, r->lc);
    if (!is_rc)
        isrc(s1, s2, r->rc);
}

void bfs(node* r)
{
    queue<pair<node*, int> > q;
    q.push(make_pair(r, 0));
    while (!q.empty())
    {
        pair<node*, int> p = q.front();
        q.pop();
        levels[p.first->data] = p.second;
        if (p.first->lc != NULL)
            q.push(make_pair(p.first->lc, p.second + 1));
        if (p.first->rc != NULL)
            q.push(make_pair(p.first->rc, p.second + 1));
    }
    has_bfs = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        insert_bin(root, d);
    }

    cin >> M;
    cin.ignore();

    stringstream ss;

    for (int i = 0; i < M; i++)
    {
        string statement;
        getline(cin, statement);
        ss.str("");
        ss.clear();
        if (statement.find("root") != string::npos)
        {
            ss << statement;
            int r;
            ss >> r;
            if (root->data == r)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (statement.find("siblings") != string::npos)
        {
            ss << statement;
            string buf;
            int s1, s2;
            ss >> s1 >> buf >> s2;
            is_sib = false;
            sib(s1, s2, root);
            if (is_sib)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (statement.find("same level") != string::npos)
        {
            ss << statement;
            string buf;
            int s1, s2;
            ss >> s1 >> buf >> s2;
            if (!has_bfs)
                bfs(root);
            if (levels.find(s1) == levels.end() || levels.find(s2) == levels.end())
            {
                cout << "No" << endl;
                continue;
            }
            if (levels[s1] == levels[s2])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (statement.find("parent") != string::npos)
        {
            ss << statement;
            string buf;
            int s1, s2;
            ss >> s1 >> buf >> buf >> buf >> buf >> s2;
            is_par = false;
            par(s1, s2, root);
            if (is_par)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (statement.find("left child") != string::npos)
        {
            ss << statement;
            string buf;
            int s1, s2;
            ss >> s1 >> buf >> buf >> buf >> buf >> buf >> s2;
            is_lc = false;
            islc(s1, s2, root);
            if (is_lc)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (statement.find("right child") != string::npos)
        {
            ss << statement;
            string buf;
            int s1, s2;
            ss >> s1 >> buf >> buf >> buf >> buf >> buf >> s2;
            is_rc = false;
            isrc(s1, s2, root);
            if (is_rc)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
