#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int a[N], tmp[N];

void merge_sort_r(vector<int> &a, vector<int> &tmp, int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort_r(a, tmp, l, mid), merge_sort_r(a, tmp, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else tmp[k ++] = a[j ++];
    while (i <= mid) tmp[k ++]  = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];

    for (i = l, j = 0; i <= r; ++ i, ++ j ) a[i] = tmp[j];
}

void merge_sort(vector<int> &a, int n) {
    vector<int> tmp(n);
    merge_sort_r(a, tmp, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i)
        cin >> a[i];

    merge_sort(a, n);

    for (int i = 0; i < n; ++ i)
        cout << a[i] << " ";

    return 0;
}
