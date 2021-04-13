//우선순위 큐(heap)사용
#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;			// 일반적으로 987654321으로 사용

int A[VERTEX][VERTEX] = { 0 };		//인접행렬
int D[VERTEX] = { 0 };				//거리 갱신
bool U[VERTEX] = { false };			//선택 정점 집합
int V;								//정점 총 수

const int HEAP_SIZE = 50;

int heap[HEAP_SIZE] = { 0, };
int heapcount = 0;

void push(int value) {
	heap[++heapcount] = value;

	int child = heapcount;
	int parent = child >> 1;

	while (parent > 0 && D[heap[parent]] > D[heap[child]]) {		// 비교는 heap의 값을 index로 하는 D의 값
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
		child = (D[heap[child]] < D[heap[child + 1]]) ? child : child + 1;
	}

	while (child <= heapcount && D[heap[parent]] > D[heap[child]]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;    //left child
		if (child + 1 <= heapcount) {    //right child가 있을 때
			child = (D[heap[child]] < D[heap[child + 1]]) ? child : child + 1;
		}
	}
	return ret;
}

// O(VlogE)
int dijkstra_pq(int s) {
	/*U[s] = true;

	for (int v = 1; v <= V; v++) {
		D[v] = A[s][v];
	}
	D[s] = 0;	*/	// 문제에 따라서 출발 지점의 가중치가 0이 아닐 수도 있어서 0으로 초기화

	D[s] = 0;
	push(s);

	while(heapcount > 0){	//!pq.empty()
		int w = pop();

		if (U[w] == false) {
			U[w] = true;

			for (int v = 1; v <= V; v++) {
				if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v]) {	//min함수 안쓰고 풀기
					D[v] = D[w] + A[w][v];
					push(v);
				}
			}
		}

	}
	return D[V];
}

void printDistance() {
	for (int i = 0; i < V; i++) {
		printf("%3c ", 'A' + i);
	}
	printf("\n");

	for (int i = 1; i <= V; i++) {
		printf("%3d ", D[i]);
	}
	printf("\n");
}
int main() {
	freopen("data.txt", "r", stdin);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];

			if (i != j && A[i][j] == 0) {
				A[i][j] = INFINITI;
			}
		}
		D[i] = INFINITI;
		U[i] = false;
	}

	int distance = dijkstra_pq(1);

	cout << "최단거리: " << distance << endl;
	printDistance();
	return 0;
}
