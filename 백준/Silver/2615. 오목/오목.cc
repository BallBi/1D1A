#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int baduck[20][20] = { 0, };
int aX = -1, aY = -1;



bool IsRightDiagonal(int n, int m, int x)
{
    if (19 <= n + 4 || 19 <= m + 4)
        return false;

    for (int i = 1; i <= 4; ++i)
    {
        if (x != baduck[n + i][m + i])
            return false;
    }

    if (19 > n + 5 && 19 > m + 5 && x == baduck[n + 5][m + 5])
        return false;

    if (0 <= n - 1 && 0 <= m - 1 && x == baduck[n - 1][m - 1])
        return false;

    aX = n;
    aY = m;

    return true;
}

bool IsLeftDiagonal(int n, int m, int x)
{
    if (0 > m - 4)
        return false;

    for (int i = 1; i <= 4; ++i)
    {
        if (x != baduck[n + i][m - i])
            return false;
    }

    if (19 > n + 5 && 0 <= m - 5 && x == baduck[n + 5][m - 5])
        return false;

    if (0 <= n - 1 && 19 > n + 1 && x == baduck[n - 1][m + 1])
        return false;

    aX = n + 4;
    aY = m - 4;

    return true;
}

bool IsVertical(int n, int m, int x)
{
    if (19 <= n + 4)
        return false;

    for (int i = 1; i <= 4; ++i)
    {
        if (x != baduck[n + i][m])
            return false;
    }

    if (19 > n + 5 && x == baduck[n + 5][m])
        return false;

    if (0 <= n - 1 && x == baduck[n - 1][m])
        return false;

    aX = n;
    aY = m;

    return true;
}

bool IsHorizon(int n, int m, int x)
{
    if (19 <= m + 4)
        return false;

    for (int i = 1; i <= 4; ++i)
    {
        if (x != baduck[n][m + i])
            return false;
    }

    if (19 > m + 5 && x == baduck[n][m + 5])
        return false;

    if (0 <= m - 1 && x == baduck[n][m - 1])
        return false;

    aX = n;
    aY = m;

    return true;
}

bool IsOMok(int n, int m, int x, int& winCount)
{
    int temp = IsRightDiagonal(n, m, x) + IsLeftDiagonal(n, m, x) + IsVertical(n, m, x) + IsHorizon(n, m, x);
    winCount += temp;
    if (temp > 0)
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int winCount = 0;
    int bw = 0;
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            cin >> baduck[i][j];
        }
    }

    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            if (0 == baduck[i][j])
                continue;

            if (true == IsOMok(i, j, baduck[i][j], winCount))
            {
                if (winCount > 1)
                {
                    cout << 0 << endl;
                    return 0;
                }
                bw = baduck[i][j];
            }
        }
    }

    if (winCount > 1 || aX == -1 && aY == -1)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << bw << endl;
    cout << aX + 1 << " " << aY + 1 << endl;

    return (0);
}