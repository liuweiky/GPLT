#include <cstdio>

using namespace std;

int hh, mm;

int main()
{
    scanf("%d:%d", &hh, &mm);

    if (hh <= 11 || (hh == 12 && mm == 0))
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    else
    {
        if (mm != 0)
            hh++;
        hh -= 12;
        for (int i = 0; i < hh; i++)
            printf("Dang");
    }

    return 0;
}
