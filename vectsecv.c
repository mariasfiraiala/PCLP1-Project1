#include <stdio.h>

int n_cresc(int n)
{
	int frecv[10] = {}; //vector de frecventa, va sorta cifrele
	int p10 = 1, n_crescator; //numarul cu cifrele sortate cresc
	while (n) {
		if (n % 10) {
			++frecv[n % 10];
			p10 *= 10; //puterea lui 10, compune noul nr
		}
		n /= 10;
	}
	n_crescator = 0; p10 /= 10;
	for (int i = 1; i < 10; ++i)
		while (frecv[i]) {
			n_crescator += p10 * i;
			p10 /= 10;
			--frecv[i];
		}
	return n_crescator;
}

int n_desc(int n)
{
	int frecv[10] = {}; //vector de frecventa => sortare
	int p10 = 1, n_descrescator;
	while (n) {
		++frecv[n % 10];
		p10 *= 10;
		n /= 10;
	}
	n_descrescator = 0; p10 /= 10;
	for (int i = 9; i >= 0; --i)
		while (frecv[i]) {
			n_descrescator += p10 * i;
			p10 /= 10;
			--frecv[i];
		}
	return n_descrescator;
}

int cautare(int v[], int n, int x)
{
	for (int i = 0; i < n; ++i)
		if (v[i] == x)
			return i;
	return -1;
}

int main(void)
{
	int perioada[100] = {}; //vector ptr perioda
	int n, k = 0, m, dif; // k = dimensiune vector
	scanf("%d", &n);
	dif = n_desc(n) - n_cresc(n); //diferenta pe care o punem in perioada
	while (cautare(perioada, k, dif) == -1) {
		perioada[k++] = dif;
		n = dif;
		dif = n_desc(n) - n_cresc(n);
	}
	m = cautare(perioada, k, dif); //pozitia de unde incepe perioada
	printf("%d\n", m);
	for (; m < k; ++m)
		printf("%d ", perioada[m]);
	return 0;
}
