#include <iostream>
using namespace std;
int main() {
	int n;
	cin>> n;
	switch(n % 10) {
		case 0:
			cout<< "123456";
			break;
		case 1:
			cout<< "789101112";
			break;
		case 2:
			cout<< "131415161718";
			break;
		case 3:
			cout<< "192021222324";
			break;
		case 4:
			cout<< "252627282930";
			break;
		case 5:
			cout<< "313233343536";
			break;
		case 7:
			cout<< "434445464748";
			break;
		case 8:
			cout<< "495051525354";
			break;
		case 9:
			cout<< "555657585960";
			break;
		default :
			cout<<"error";
	}
}
