#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void quick_sort(int l, int r)
{
    if (l >= r) return;

    int x = q[(l + r) / 2], i = l - 1, j = r + 1;

    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    cout<<j<<endl;  
    for(int i = 0;i<n;i++)
        cout<<q[i]<<" ";
    cout<<endl;
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}
