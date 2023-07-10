#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main(int argc, char** argv)
{
	clock_t begin = clock();
	system(argv[1]);
	double used = 1000.0 * double(clock() - begin) / CLOCKS_PER_SEC - 200.0;
	if (used < 0) used = 0.0;
	printf("\n------------------------------\n");
	printf("Time used: %lf ms.\n", used);
	return 0;
}
