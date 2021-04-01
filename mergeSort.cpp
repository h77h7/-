#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int* r, int begin, int mid, int end) {
	int left_idx = begin;
	int right_idx = mid + 1;
	int r_idx = 0;

	//���� �� ���� �ִ� ���
	while (left_idx <= mid && right_idx <= end) {
		if (a[left_idx] < a[right_idx])
			r[r_idx++] = a[left_idx++];
		else r[r_idx++] = a[right_idx++];
	}

	//���ʸ� ���� �ִ� ���
	while (left_idx <= mid) {
		r[r_idx++] = a[left_idx++];
	}

	//�����ʸ� ���� �ִ� ���
	while (right_idx <= end) {
		r[r_idx++] = a[right_idx++];
	}

	r_idx = 0;
	for (int i = begin; i <= end; i++) {
		a[i] = r[r_idx++];
	}
}

void mergeSort(int *a, int* r, int begin, int end) {
	//������ ���� 1�� ���ϸ� ����
	if (end - begin <= 0) return;

	int mid = (begin + end) >> 1;
	mergeSort(a, r, begin, mid);
	mergeSort(a, r, mid + 1, end);

	if(a[mid] >= a[mid+1])
		merge(a, r, begin, mid, end);
}

void mergeSortOne(int *a, int* r, int begin, int end) {
	//������ ���� 1�� ���ϸ� ����
	if (end - begin <= 0) return;

	int mid = (begin + end) >> 1;
	mergeSort(a, r, begin, mid);
	mergeSort(a, r, mid + 1, end);

	//merge �Լ� inline
	if (a[mid] >= a[mid + 1]) {
		int left_idx = begin;
		int right_idx = mid + 1;
		int r_idx = 0;

		//���� �� ���� �ִ� ���
		while (left_idx <= mid && right_idx <= end) {
			if (a[left_idx] < a[right_idx])
				r[r_idx++] = a[left_idx++];
			else r[r_idx++] = a[right_idx++];
		}

		//���ʸ� ���� �ִ� ���
		while (left_idx <= mid) {
			r[r_idx++] = a[left_idx++];
		}

		//�����ʸ� ���� �ִ� ���
		while (right_idx <= end) {
			r[r_idx++] = a[right_idx++];
		}

		r_idx = 0;
		for (int i = begin; i <= end; i++) {
			a[i] = r[r_idx++];
		}
	}
		
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int partition(int *a, int begin, int end) {
	int pivot = a[begin];
	int i = begin;
	int j = end;
	while (i <= j) {
		while (i <= end && a[i] <= pivot) i++;
		while (j >= begin && a[j] > pivot) j--;

		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	swap(a[begin], a[j]);
	return j;
}
void quickSort(int *a, int begin, int end) {
	if (begin < end) {
		int pivot = partition(a, begin, end);

		quickSort(a, begin, pivot - 1);
		quickSort(a, pivot + 1, end);
	}
}

//partiton() inline
void quickSortOne(int *a, int begin, int end) {
	if (begin < end) {
		int pivot = a[begin];
		int i = begin;
		int j = end;
		while (i <= j) {
			while (i <= end && a[i] <= pivot) i++;
			while (j >= begin && a[j] > pivot) j--;

			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		swap(a[begin], a[j]);

		quickSortOne(a, begin, j - 1);
		quickSortOne(a, j + 1, end);
	}
}

int main() {
	int arr[] = { 1,5,6,78,5,85,8,6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	/*int *result = new int[n + 1]{ 0, };
	mergeSortOne(arr, result, 0, n-1);*/
	quickSort(arr, 0, n);

	printArray(arr, n);
}