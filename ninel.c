#include <stdio.h>
#define XMAX 1000000

int main(void)
{
	int n, i, x1, x2, x3, xmax_impar, xmin_par, count_s = 0;
	double m_a = 0;
	long long S; //suma copacilor valizi
	scanf("%d %d", &n, &x1);
	if (n > 1)
		scanf("%d", &x2);
	S = 0; xmax_impar = 0; xmin_par = XMAX;
	for (i = 2; i < n; ++i) {
		scanf("%d", &x3);
		if (x1 < x2 && x2 > x3) {
			S += x2;
			++count_s; //contor pentru numarul de copaci pe care ii cautam
			if ((i - 1) % 2 && x2 > xmax_impar)
				xmax_impar = x2;
			else if (!((i - 1) % 2) && x2 < xmin_par)
				xmin_par = x2;
		}
		x1 = x2;
		x2 = x3;
	}
	if (count_s)
		m_a = (double)S / count_s;
	if (!count_s)
		xmin_par = 0;
	else if (xmin_par == XMAX)
		xmin_par = -1;
	printf("%lld\n%.7lf\n%d\n%d", S, m_a, xmax_impar, xmin_par);
	return 0;
}
