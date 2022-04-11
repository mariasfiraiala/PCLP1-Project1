#include <stdio.h>
#define DIMMAX 100

int validnomo(void)
{
	int mat[DIMMAX][DIMMAX]; //gridul pe care il verificam
	int restrictii_l[DIMMAX][DIMMAX], restrictii_c[DIMMAX][DIMMAX];
	int n, m; //dimensiune matrice
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &restrictii_l[i][0]);
		int k = restrictii_l[i][0]; //nr de restrictii pt fiecare linie
		for (int j = 1; j <= k; ++j)
			scanf("%d", &restrictii_l[i][j]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &restrictii_c[i][0]);
		int k = restrictii_c[i][0]; //nr de restrictii pt fiecare coloana
		for (int j = 1; j <= k; ++j)
			scanf("%d", &restrictii_c[i][j]);
	}
	for (int l = 0; l < n; ++l)
		for (int c = 0; c < m; ++c)
			scanf("%d", &mat[l][c]);
	for (int l = 0; l < n; ++l) {
		int c = 0, nr1 = 0;//nr de grupuri de 1 pe linie
		while (c < m) {
			while (!mat[l][c] && c < m)
				++c;
			int i = c;
			while (mat[l][i] && i < m)
				++i;//calculeza cati 1 sunt intr-un pachet
			if (i != c)
				if (restrictii_l[l][++nr1] != i - c)
					return 0;
			c = i;
		}
		if (nr1 != restrictii_l[l][0])
			return 0;
	}
	for (int c = 0; c < m; ++c) {
		int l = 0, nr1 = 0;
		while (l < n) {
			while (!mat[l][c] && l < n)
				++l;
			int i = l;
			while (mat[i][c] && i < n)
				++i;
			if (i != l)
				if (restrictii_c[c][++nr1] != i - l)
					return 0;
			l = i;
		}
		if (nr1 != restrictii_c[c][0])
			return 0;
	}
	return 1;
}

int main(void)
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; ++i) {
		if (validnomo())
			printf("Corect\n");
		else
			printf("Eroare\n");
	}
	return 0;
}
