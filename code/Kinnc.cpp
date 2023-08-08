/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime
 */
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    for(int i = 1; i < n; i++) {
        cout<<i << " ";
        printf("%.32lf\n", (double)(4 * i - 2) / (i + 1));
    }
}
