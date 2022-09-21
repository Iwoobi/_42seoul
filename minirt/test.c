#include "stdio.h"
#include "stdlib.h"

void	ft(double *b)
{
	b[0] = 1000;
	b[1] = 2000;
}

int main()
{
	double a[2000];
	int i = 0;
	while (i < 2000)
	{
		a[i] = -1 * i;
		i++;
	}
	printf("%f %f\n", a[0], a[1]);
	ft(a);
	printf("%f %f\n", a[0], a[1]);

}
