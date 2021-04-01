#include <iostream>

using namespace std;

const int HEAP_SIZE = 50;

int heap[HEAP_SIZE] = { 0, };
int heapcount = 0;

void push(int value) {
	heap[++heapcount] = value;

	int child = heapcount;
	int parent = child >> 1;

	while (parent > 0 && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;          //child와 parent 재조정
		parent = child >> 1;
	}
}

//pq로 운영하는 경우 extractMin(), extractMax()이름을 사용함.
int pop() {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapcount];
	heap[heapcount--] = 0;

	int child = parent << 1;    //left child
	if (child + 1 <= heapcount) {    //right child가 있을 때
		child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}

	while (child <= heapcount && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;    //left child
		if (child + 1 <= heapcount) {    //right child가 있을 때
			child = (heap[child] < heap[child + 1]) ? child : child + 1;
		}
	}
	return ret;
}

void printHeap() {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextlevel = 1;
	for (int i = 1; i < HEAP_SIZE; i++) {
		if (i == pow2[nextlevel]) {
			cout << endl;
			nextlevel++;
		}
		if (heap[i]) {
			cout << heap[i] << " ";
		}
	}
	cout << endl;
}

int main() {

	push(20);
	push(17);
	push(19);
	push(4);
	push(13);
	push(11);
	push(23);

	printHeap();

	cout << pop() << endl << endl;
	printHeap();

	return 0;
}