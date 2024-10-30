#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long min = 0, max = 0;
    cin >> min >> max;
    bool isSquare[1000001] = { false, };
    int squareCount = 0;

    for (long long i = 2; i * i <= max; ++i)
    {
        long long n = min / (i * i);
        if (0 != min % (i * i))
            n++;

        while (n * i * i <= max)
        {
            if (false == isSquare[n * i * i - min])
            {
                isSquare[n * i * i - min] = true;
                squareCount++;
            }
            n++;
        }
    }
    cout << max - min - squareCount + 1;
}