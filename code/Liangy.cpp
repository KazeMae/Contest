#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin>> n >> k;
    vector<int> s(n);
    for(int i = 0; i < n; ++ i) {
        cin>> s[i];
    }
    int l = 0, r = n - 1, mid;
    while(r - l > 0) {
        mid = l + r + 1 >> 1;
        if(s[mid] <= k) l = mid;
        else r = mid - 1;
    }
    if(s[l] == k) cout<< l + 1 <<endl;
    else cout<< -1 <<endl;
    return 0;
}
