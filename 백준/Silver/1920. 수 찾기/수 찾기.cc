#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[100001] = { 0, };
bool Check(int left, int right, int f)
{
    int middle = 0;
    while (left <= right) {
        int middle = (left + right) / 2;

        if (A[middle] == f)
            return true;

        if (A[middle] > f)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, m = 0, temp = 0;
    cin >> n;
    for (int i = 0;i < n;++i)
    {
        cin >> temp;
        A[i] = temp;
    }
    sort(A, A + n);

    cin >> m;

    for (int i = 0;i < m;++i)
    {
        cin >> temp;
        cout << Check(0, n - 1, temp) << '\n';
    }
}