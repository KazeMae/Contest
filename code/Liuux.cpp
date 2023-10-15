#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
mt19937_64 rng(steady_clock::now().time_since_epoch().count());
long long myRand(long long B) {
    return (unsigned long long)rng() % B + 1; 
}

void algorithm_1(int n, int k, vector<int> &s) {
    for(int pos = 0; pos < n; ++ pos) {
        if(s[pos] == k) {
            return ;
        }
    }
    return ;
}
void algorithm_2(int n, int k, vector<int> &s) {
    int l = 0, r = n - 1, mid;
    while(r - l > 0) {
        mid = l + r + 1 >> 1;
        if(s[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return ;
}
signed main () {
    cout<< setiosflags(ios::fixed) << setprecision(10);
    // 数据组数为 100
    int times = 100;
    while(times --) {
        // 数据生成
        int n = myRand(5000000), k = 1000000000;
        vector<int> s(n);
        for(int i = 0; i < n; ++ i) 
            s[i] = myRand(1000000000);

        sort(s.begin(), s.end());

        // 算法一运行和时间统计
        auto bt1 = steady_clock::now();
        algorithm_1(n, k, s);
        auto at1 = steady_clock::now();

        // 算法二运行和时间统计
        auto bt2 = steady_clock::now();
        algorithm_2(n, k, s);
        auto at2 = steady_clock::now();

        double algo1 = duration<double, milli>(at1 - bt1).count();
        double algo2 = duration<double, milli>(at2 - bt2).count();
        cout<< n << " " << algo1 << " " << algo2 << endl;
    }
}
