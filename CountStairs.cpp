//Stairs
#include "stdafx.h"

typedef unsigned long long Ull;

Ull a[502][502];

inline void calcCountPosition(int maxLength, int n)
{	
	if (maxLength == n)	{
		a[maxLength][n] = 1 + a[maxLength - 1][n];
		return;
	}
	a[maxLength][n] = a[maxLength - 1][n - maxLength] + a[maxLength - 1][n];
}

int main()
{
	int n, i, j;
	std::cin >> n;

	for (i = 1; i <= n; ++i) {
		a[i][1] = 1;
	}

	for (i = 2; i <= n; ++i) {
		for (j = 2; j <= i; ++j) {
			calcCountPosition(j, i);
		}
		for (j = i + 1; j <= n; ++j) {
			a[j][i] = a[j - 1][i];
		}
	}

	std::cout << a[n][n] << std::endl;
	system("pause"); //delete for testing!
    return 0;
}