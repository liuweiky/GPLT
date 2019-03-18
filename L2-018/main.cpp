#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

#define MAX_E 10240

using namespace std;

int Ae = 0, Be = 0, Qe = 0;
double poly_a[MAX_E];
double poly_b[MAX_E];
double poly_q[MAX_E];

vector<pair<int, double> > ansq, ansr;

void divide()
{
    double t = poly_a[Ae] / poly_b[Be];
    int e = Ae - Be;
    poly_q[e] = t;
    Qe = max(Qe, e);
    for (int i = Ae, cnt = 0; Be - cnt >= 0; i--, cnt++)
        poly_a[i] -= t * poly_b[Be - cnt];
    Ae--;
}

void get_ans()
{
    for (int i = Qe; i >= 0; i--)
    {
        double c = poly_q[i];
        c = round(c * 10) / 10;
        if (c != 0.0)
        {
            pair<int, double> p;
            p.first = i;
            p.second = c;
            ansq.push_back(p);
        }
    }
    for (int i = Ae; i >= 0; i--)
    {
        double c = poly_a[i];
        c = round(c * 10) / 10;
        if (c != 0.0)
        {
            pair<int, double> p;
            p.first = i;
            p.second = c;
            ansr.push_back(p);
        }
    }
}

int main()
{
    fill_n(poly_a, MAX_E, 0.0);
    fill_n(poly_b, MAX_E, 0.0);
    fill_n(poly_q, MAX_E, 0.0);

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int e;
        double c;
        scanf("%d %lf", &e, &c);

        Ae = max(Ae, e);
        poly_a[e] = c;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int e;
        double c;
        scanf("%d %lf", &e, &c);

        Be = max(Be, e);
        poly_b[e] = c;
    }

    while (Ae >= Be)
        divide();

    get_ans();

    if (ansq.size() == 0)
        printf("0 0 0.0");
    else
    {
        int sz = ansq.size();
        printf("%d", sz);
        for (int i = 0; i < sz; i++)
            printf(" %d %.1f", ansq[i].first, ansq[i].second);
    }

    printf("\n");

    if (ansr.size() == 0)
        printf("0 0 0.0");
    else
    {
        int sz = ansr.size();
        printf("%d", sz);
        for (int i = 0; i < sz; i++)
            printf(" %d %.1f", ansr[i].first, ansr[i].second);
    }

    return 0;
}
