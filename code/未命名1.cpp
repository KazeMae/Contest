#include <iostream>
using namespace std;
int main() {
	int l, r, cnt = 0;
	scanf("%d%d", &l ,&r);
//	cin>> l >> r;
	for(int a = l; a <= r; ++ a) 
	{
		for(int b = l; b <= r; ++ b) 
		{
			for(int c = l; c <= r; ++ c) 
			{
				if(a + b + c <= r) 
				{
//					cnt ++;
//					cnt += 1;
					cnt = cnt + 1;
				}
			}
		} 
	}
//	cout<< cnt <<endl;
	printf("%d\n", cnt);
	int c = 1, d = 1;
	cout << ++ c << " " << d ++ <<endl; 
}
