#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int N, M, K;

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    while (K--)
    {
        vector<int> vs;
        for (int i = 0; i < N; i++)
        {
            int t;
            scanf("%d", &t);
            vs.push_back(t);
        }
        stack<int> stk;
        int expect = 1;

        int ptr = 0;
        bool flag = true;

        while (true)
        {
            if (!stk.empty())
            {
                if (stk.top() == expect)
                {
                    stk.pop();
                    expect++;
                }
                else if (ptr < N)
                {
                    if (vs[ptr] == expect)
                    {
                        expect++;
                        ptr++;
                    }
                    else if (stk.size() == M)
                    {
                        flag = false;
                        break;
                    }
                    else
                        stk.push(vs[ptr++]);
                }
                else
                {
                    flag = false;
                    break;
                }

            }
            else
            {
                if (ptr == N)
                    break;
                else
                {
                    if (vs[ptr] == expect)
                    {
                        ptr++;
                        expect++;
                    }
                    else
                       stk.push(vs[ptr++]);
                }
            }
        }

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
