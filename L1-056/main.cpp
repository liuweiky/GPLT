#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<pair<string, double> > players;
int N;

int main()
{
    scanf("%d", &N);

    double avg = 0;

    for (int i = 0; i < N; i++)
    {
        double num;
        char buf[16];
        scanf("%s %lf", buf, &num);
        pair<string, double> p(buf, num);
        avg += p.second;
        players.push_back(p);
    }

    avg /= (N * 2);
    string best = "";
    double dbest = 9999999;

    for (int i = 0; i < N; i++)
        if (dbest > fabs(avg - players[i].second))
        {
            best = players[i].first;
            dbest = fabs(avg - players[i].second);
        }

    printf("%d %s", (int)avg, best.c_str());

    return 0;
}
