#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double weight, height;

    cin >> weight >> height;
    cout << fixed << setprecision(1) << weight / (height * height) << endl << (weight / (height * height) > 25 ? "PANG" : "Hai Xing");
    return 0;
}
