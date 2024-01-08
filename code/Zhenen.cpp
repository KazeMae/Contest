#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int> > pos(n);
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a[i] = x;
            pos[x].push_back(i);   
        }
        if (pos[0].size() != 1){
            cout << "NO" << '\n';
            continue;
        }
        vector<int> l(n + 1), r(n + 1);
        for(int i = 1; i <= n; i++){
            l[i] = i - 1;
            r[i] = i + 1;
        }
        r[n] = 0;

        auto del = [&](int x){
            r[l[x]] = r[x];
            l[r[x]] = l[x];
        };

        bool ok = true;
        for(int i = n - 1; i >= 1; i--){
            for(int j = 0; j < pos[i].size(); j++){
                int k = j;
                while(k + 1 < pos[i].size() && r[pos[i][k]] == pos[i][k + 1]) k++;
                int L = pos[i][j], R = pos[i][k];
                if ((l[L] && a[l[L]] == i - 1) || (r[R] && a[r[R]] == i - 1)){

                }
                else{
                    ok = false;
                    break;
                }
                j = k;
            }
            for(auto x : pos[i]){
                del(x);
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

}
