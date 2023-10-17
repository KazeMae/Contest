#include <iostream>
#include <vector>
using namespace std;
int getbit(int m) {
    int k = 0;
    while(m) {
        k += m % 2;
        m /= 2;
    }
    return k;
}
int main()
{
    cout<< getbit(121) <<endl;
    return 0;
}

