#include "forel.h"

double distEv(const double *x, const double *c, const int m) {
	double d, r = 0;
	int i = 0;
	while (i++ < m) {
		d = *(x++) - *(c++);
		r += d * d;
	}
	return sqrt(r);
}

double getAvDist(const double *x, const int n, const int m) {
	double res = 0;
	int i, j;
	for (i = 0; i < n * m; i += m) {
		for (j = i + m; j < n * m; j += m) {
			res += distEv(&x[i], &x[j], m);
		}
	}
	return 2 * res / (n * n + n);
}

void autoscaling(double *x, const int n, const int m, double *eps) {
	double beforeAvDist = getAvDist(x, n, m), afterAvDist, sd, Ex, Exx;
	const int s = n * m;
	int i, j = 0;
	while (j < m) {
		i = j;
		Ex = Exx = 0;
		while (i < s) {
			sd = x[i];
			Ex += sd;
			Exx += sd * sd;
			i += m;
		}
		Exx /= n;
		Ex /= n;
		sd = sqrt(Exx - Ex * Ex);
		i = j;
		while (i < s) {
			x[i] = (x[i] - Ex) / sd;
			i += m;
		}
		j++;
	}
	afterAvDist = getAvDist(x, n, m);
	*eps /= (beforeAvDist / afterAvDist);
}

char equal(const double* const x, const double* const y, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (x[i] != y[i]) return 0;
	}
	return 1;
}

char calcCentrum(const double* const x, double *c, const int* const y, const int n, const int m, const int marker) {
	double *newC = (double*)malloc(m * sizeof(double));
	memset(&newC[0], 0, m * sizeof(double));
	int i, j, nums = 0;
	for (i = 0; i < n; i++) {
		if (y[i] == marker) {
			nums++;
			const int buf = i * m;
			for (j = 0; j < m; j++) {
				newC[j] += x[buf + j];
			}
		}
	}
	for (i = 0; i < m; i++) {
		newC[i] /= nums;
	}
	char res = equal(c, newC, m);
	memcpy(&c[0], &newC[0], m * sizeof(double));
	free(newC);
	return (res) ? 0 : 1;
}

void markingNeighbors(const double* x, const double* c, int* const y, const int n, const int m, const double r, const int marker) {
	int i;
	for (i = 0; i < n; i++) {
		if ((y[i] == -1) && (distEv(&x[i * m], &c[0], m) < r)) y[i] = marker;
	}
}

void forel(const double* const X, int* const y, const int n, const int m, const double inR) {
	double *x = (double*)malloc(n * m * sizeof(double));
	memcpy(&x[0], &X[0], n * m * sizeof(double));
	double r = inR;
	autoscaling(x, n, m, &r);
	memset(&y[0], -1, n * sizeof(int));
	double *c = (double*)malloc(m * sizeof(double));
	int i, marker = 0;
	for (i = 0; i < n; i++) {
		if (y[i] == -1) {
			char flag = 1;
			memcpy(&c[0], &x[i * m], m * sizeof(double));
			do {
				markingNeighbors(x, c, y, n, m, r, marker);
				flag = calcCentrum(x, c, y, n, m, marker);
			} while (flag);
			marker++;
		}
	}
	free(x);
	free(c);
}
