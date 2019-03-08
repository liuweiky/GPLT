#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

#define MAX_N 1024

using namespace std;

int N, M;
int heap[MAX_N];
int n = 0;

void upjust(int s, int t)
{
    int j = t, i = t / 2;
    while (i >= s)
    {
        if (i * 2 + 1 <= t && heap[i * 2 + 1] < heap[j])
            j = i * 2 + 1;
        if (heap[j] < heap[i])
            swap(heap[j], heap[i]);
        i /= 2;
        j = i * 2;
    }
}

void insert_heap(int d)
{
    n++;
    heap[n] = d;
    upjust(1, n);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int d;
        scanf("%d", &d);
        insert_heap(d);
    }

    getchar();
    for (int i = 0; i < M; i++)
    {
        string str;
        getline(cin, str);
        if (str.find("root") != string::npos)
        {
            int r;
            sscanf(str.c_str(), "%d", &r);
            if (heap[1] == r)
                printf("T\n");
            else
                printf("F\n");
        }
        else if (str.find("siblings") != string::npos)
        {
            int s, t;
            char buf[20];
            sscanf(str.c_str(), "%d %s %d %s %s", &s, buf, &t, buf, buf);
            bool flag = false;
            for (int j = 1; j <= n / 2; j++)
            {
                if (j * 2 + 1 <= n && ((heap[j * 2] == s && heap[j * 2 + 1] == t) || (heap[j * 2] == t && heap[j * 2 + 1] == s)))
                {
                    flag = true;
                    printf("T\n");
                    break;
                }
            }
            if (!flag)
                printf("F\n");
        }
        else if (str.find("parent") != string::npos)
        {
            int s, t;
            char buf[20];
            sscanf(str.c_str(), "%d %s %s %s %s %d", &s, buf, buf, buf, buf, &t);
            bool flag = false;
            for (int i = 1; i <= n / 2; i++)
            {
                if (heap[i] == s && (heap[i * 2] == t || (i * 2 + 1 <= n && heap[i * 2 + 1] == t)))
                {
                    flag = true;
                    printf("T\n");
                    break;
                }
            }
            if (!flag)
                printf("F\n");
        }
        else
        {
            int s, t;
            char buf[20];
            sscanf(str.c_str(), "%d %s %s %s %s %d", &s, buf, buf, buf, buf, &t);
            bool flag = false;
            for (int i = 1; i <= n / 2; i++)
            {
                if (heap[i] == t && (heap[i * 2] == s || (i * 2 + 1 <= n && heap[i * 2 + 1] == s)))
                {
                    flag = true;
                    printf("T\n");
                    break;
                }
            }
            if (!flag)
                printf("F\n");
        }
    }

    return 0;
}
