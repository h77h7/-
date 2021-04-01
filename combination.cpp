#include <iostream>

using namespace std;


//부분집합의 핵심 - 각 원소가 포함되는 경우(1)과 포함되지 않는 경우(0)의 조합
void powerset_loop() {
	int bit[3] = { 0, };
	for (int i = 0; i <= 1; i++) {
		bit[0] = i;
		for (int j = 0; j <= 1; j++) {
			bit[1] = j;
			for (int k = 0; k <= 1; k++) {
				bit[2] = k;
				printArray(bit, 3);
			}
		}
	}
	
}


int arr[] = { 1,2,3,4,5,6 };
int t[5] = { 0, };

//nPn
void perm_loop() {

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (j == i) continue;
			for (int k = 1; k < 4; k++) {
				if (k == j || k == i) continue;

				printf("{ %d %d %d }\n", i, j, k);
			}
		}
	}
}
void printArray(int* a, int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("} \n");
}

//nPn
void perm_recursive(int k, int n) {
	if (k == n) {
		printArray(arr, n);
	}

	else {
		for (int i = k; i < n; i++) {
			swap(arr[i], arr[k]);
			perm_recursive(k + 1, n);
			swap(arr[i], arr[k]);
		}
	}
}

//nPr = n * n-1Pr-1
void perm_formula(int n, int r, int q) {
	if (r == 0) {
		printArray(t, q);
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			t[r - 1] = arr[n - 1]; //n
			perm_formula(n - 1, r - 1, q); //n-1 P r-1
			swap(arr[i], arr[n - 1]);
		}
	}
}

//nPir = n * nPir-1
void nPIr(int n, int r, int q) {
	if (r == 0) {
		printArray(t, q);
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			t[r - 1] = arr[n - 1]; //n
			nPIr(n, r - 1, q); //n PI r-1
			swap(arr[i], arr[n - 1]);
		}
	}
}

//부분집합의 핵심 - 각 원소가 포함되는 경우(1)과 포함되지 않는 경우(0)의 조합
void powerset_loop() {
	int bit[3] = { 0, };
	for (int i = 0; i <= 1; i++) {
		bit[0] = i;
		for (int j = 0; j <= 1; j++) {
			bit[1] = j;
			for (int k = 0; k <= 1; k++) {
				bit[2] = k;
			}
		}
	}
}

int main() {
	printf("순열(반복)\n");
	perm_loop();

	printf("\n\n");

	printf("순열(재귀)\n");
	perm_recursive(0, 3);

	printf("\n\n");

	printf("순열(점화)\n");
	perm_formula(3, 3, 3);

	printf("\n\n");

	printf("중복순열\n");
	nPIr(3, 3, 3);

	return 0;
}