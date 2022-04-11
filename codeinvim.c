#include <stdio.h>
#define NMAX 100

void myquicksort(int begin, int end, int v[])
{
	int aux, b = begin, e = end, pivot = v[(b + e) / 2];
	while (v[b] < pivot)
		++b;
	while (v[e] > pivot)
		--e;
	while (b < e) {
		aux = v[b];
		v[b] = v[e];
		v[e] =  aux;
		do
			++b;
		while (v[b] < pivot);
		do
			--e;
		while (v[e] > pivot);
	}
	if (begin < e)
		myquicksort(begin, e, v);
	if (e + 1 < end)
		myquicksort(e + 1, end, v);
}

int main(void)
{
	int x[NMAX], c[NMAX], punctaj[NMAX]; //vectori pt note, credite si punctaj
	int n, pmin, m, i, p_partial;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	scanf("%d", &pmin);

	p_partial = 0;
	for (i = 0; i < n; ++i) {
		punctaj[i] = (10 - x[i]) * c[i];
		p_partial += c[i] * x[i];
	}
	myquicksort(0, n - 1, punctaj);
	m = 0;
	for (i = n - 1; i >= 0 && p_partial < pmin; --i) {
		p_partial += punctaj[i];
		++m;
	}

	if (p_partial < pmin)
		printf("-1");
	else
		printf("%d", m);
	return 0;
}
