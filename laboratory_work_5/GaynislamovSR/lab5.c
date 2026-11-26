#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vvod() {
	int n;
	if (scanf("%i", &n) != 1 || n <= 0) {
		while (getchar() != '\n');
		return -1;
	}
	return n;
}

int *fill(int n) {
	int *arr = (int*)(malloc(sizeof(int)*n));
	for (int i = 0; i < n; i++)
		arr[i] = rand()%10000;
	return arr;
}

void swap(int *arr, int i, int j) {
	int r = arr[i];
	arr[i] = arr[j];
	arr[j] = r;
}

void vstavka(int *arr, int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && arr[j-1] > arr[j]; j--)
			swap(arr, j-1, j);
}

int *merge(int *left, int ln, int *right, int rn)
{
	int i, j, r;
	int *res = (int*)malloc(sizeof(int)*(ln+rn));

	i = j = r = 0;
	while (i < ln && j < rn)
		if (left[i]<right[j]) res[r++] = left[i++];
		else res[r++] = right[j++];

	while (i < ln) res[r++] = left[i++];
	while (j < rn) res[r++] = right[j++];

	return res;
}

int *mergesort(int *arr, int n) {
	int mid;
	int *l, *r, *sortl, *sortr, *res;

	if (n <= 1) return arr;

	mid = n/2;
	l = (int*)malloc(sizeof(int)*mid);
	for (int i = 0; i<mid; i++) l[i] = arr[i];
	r = (int*)malloc(sizeof(int)*(n-mid));
	for (int i = 0; i<(n-mid); i++) r[i] = arr[i+mid];

	sortl = mergesort(l, mid);
	sortr = mergesort(r, n-mid);
	res = merge(sortl, mid, sortr, n-mid);

	if (sortl != l) free(sortl);
	if (sortr != r) free(sortr);
	free(r); free(l);
	return res;
}

int max(int*arr, int n) {
	int mx = -1;
	for (int i = 0; i < n; i++) 
		if (mx < arr[i]) mx = arr[i];
	return mx;
}

void countingsort(int *arr, int exp, int n) {
	int *res = (int*)malloc(sizeof(int)*n);
	int count[10] = {0};
	int j;

	for (int i = 0; i < n; i++) 
		count[(arr[i]/exp)%10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i-1];

	for (int i = n-1; i >= 0; i--) {
		j = (arr[i]/exp)%10;
		res[count[j]-1] = arr[i];
		count[j]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = res[i];

	free(res);
}

void radixsort(int *arr, int n)
{
	int mx, exp;

	mx = max(arr, n);
	exp = 1;

	while (mx/exp > 0) {
		countingsort(arr, exp, n);
		exp *= 10;
	}
}

int main()
{
	srand(time(NULL));

	int n, v, *arr, *res;
	float sec;
	char c;

	for (;;) 
	{
		printf("Введите размер массива: ");
		n = vvod();
		if (n == -1) {printf("err\n"); continue;}
		
		printf("Сортировки: \n");
		printf("1. Вставками\n");
		printf("2. mergeSort\n");
		printf("3. radixsort\n");
		printf("Ваш выбор: ");
		v = vvod();
		printf("\n");

		switch(v) 
		{
		case 1: 
			for (int i = 1; i <= 5; i++) {
				arr = fill(n);
				clock_t start = clock(); 
				vstavka(arr, n);
				clock_t end = clock();
				sec = (float)(end-start) / CLOCKS_PER_SEC;
				printf("%i. %f\n", i, sec);
				free(arr);
				n*=5;
			} printf("\n");
			break;

		case 2:
			for (int i = 1; i <= 5; i++) {
				arr = fill(n);
				clock_t start = clock(); 
				res = mergesort(arr, n);
				clock_t end = clock();
				sec = (float)(end-start) / CLOCKS_PER_SEC;
				printf("%i. %f\n", i, sec);
				if (res != arr) free(res);
				free(arr);
				n*=5;
			} printf("\n");
			break;

		case 3:
			for (int i = 1; i <= 5; i++) {
				arr = fill(n);
				clock_t start = clock(); 
				radixsort(arr, n);
				clock_t end = clock();
				sec = (float)(end-start) / CLOCKS_PER_SEC;
				printf("%i. %f\n", i, sec);
				free(arr);
				n*=5;
			} printf("\n");
			break;			

		default: printf("err\n"); 
		}

		printf("продолжить (y/n): ");
		scanf(" %c", &c);
		if (c == 'n') break;
	}
	return 0;
}