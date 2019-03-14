#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, k, M;

int main()
{
    scanf("%d %d %d", &N, &k, &M);

    vector<double> ans;

    for (int i = 0; i < N; i++)
    {
        double total = 0;
        double max_s = INT_MIN, min_s = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            double ts;
            scanf("%lf", &ts);
            max_s = max(max_s, ts);
            min_s = min(min_s, ts);
            total += ts;
        }
        total -= max_s;
        total -= min_s;
        total /= (k - 2);
        ans.push_back(total);
    }

    sort(ans.begin(), ans.end());

    for (int i = ans.size() - M; i < ans.size(); i++)
    {
        if (i != ans.size() - M)
            printf(" ");
        printf("%.3f", ans[i]);
    }

    return 0;
}
