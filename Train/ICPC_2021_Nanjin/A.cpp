#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ix, iy;
    cin>> n >> x >> y;
    if(x > n / 2) ix = n;
    else ix = 1;
    if(y > n / 2) iy = n;
    else iy = 1;
    
    if(iy == n) for(int i = 0; i < n - 1; ++ i) cout<< "R";
    else for(int i = 0; i < n - 1; ++ i) cout<< "L";

    if(ix == n) for(int i = 0; i < n - 1; ++ i) cout<< "D";
    else for(int i = 0; i < n - 1; ++ i) cout<< "U";

    for(int i = 0; i < abs(ix - x); ++ i) {
        if(ix > x) cout<< "U";
        else cout<< "D";
    }
    for(int i = 0; i < abs(iy - y); ++ i) {
        if(iy > y) cout<< "L";
        else cout<< "R";
    }
    
}
