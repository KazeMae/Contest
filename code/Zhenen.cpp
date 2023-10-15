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
    for(int pos = 0; pos < n; ++ pos) {
        if(s[pos] == k) {
            cout<< pos + 1 <<endl;
            return 0;
        }
    }
    cout<< -1 <<endl;
    return 0;
}

