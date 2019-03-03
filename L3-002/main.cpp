#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stk;
vector<int> sorted;
int N;

void insert_bin(int i)
{
    int low = 0, high = sorted.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sorted[mid] < i)
            low = mid + 1;
        else if (sorted[mid] > i)
            high = mid - 1;
        else
        {
            sorted.insert(sorted.begin() + mid, i);
            return;
        }
    }
    sorted.insert(sorted.begin() + low, i);
}

void del(int i)
{
    int low = 0, high = sorted.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sorted[mid] < i)
            low = mid + 1;
        else if (sorted[mid] > i)
            high = mid - 1;
        else
        {
            sorted.erase(sorted.begin() + mid);
            return;
        }
    }
}

bool psh(int i)
{
    stk.push_back(i);
    insert_bin(i);
    return true;
}

int pp()
{
    if (stk.size() == 0)
        return -1;
    int i = stk[stk.size() - 1];
    stk.pop_back();
    del(i);
    return i;
}

int pm()
{
    if (stk.size() == 0)
        return -1;
    return sorted[(sorted.size() - 1) / 2];
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char buf[16];
        scanf("%s", buf);
        if (buf[1] == 'o')
        {
            int res = pp();
            if (res < 0)
                printf("Invalid\n");
            else
                printf("%d\n", res);
        }
        else if (buf[1] == 'e')
        {
            int res = pm();
            if (res < 0)
                printf("Invalid\n");
            else
                printf("%d\n", res);
        }
        else
        {
            int t;
            scanf("%d", &t);
            psh(t);
        }
    }

    return 0;
}
