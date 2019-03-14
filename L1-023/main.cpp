#include <cstdio>
#include <cctype>
#include <algorithm>

#define ASCII_LEN 256

using namespace std;

int ascii_map[ASCII_LEN];

int main()
{
    fill_n(ascii_map, ASCII_LEN, 0);

    char c;

    while ((c = getchar()) != '\n')
        ascii_map[toupper(c)]++;

    char buf[] = {'G', 'P', 'L', 'T'};

    bool flag = true;

    while (flag)
    {
        flag = false;
        for (int i = 0; i < 4; i++)
        {
            if (ascii_map[buf[i]] > 0)
            {
                flag = true;
                printf("%c", buf[i]);
                ascii_map[buf[i]]--;
            }
        }
    }

    return 0;
}
