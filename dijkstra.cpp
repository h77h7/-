#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;			// 일반적으로 987654321으로 사용

int A[VERTEX][VERTEX] = { 0 };		//인접행렬
int D[VERTEX] = { 0 };				//거리 갱신
bool U[VERTEX] = { false };			//선택 정점 집합
int V;								//정점 총 수

int extractMin() {
	int minVertex = 0;
	int minDistance = INFINITI;

	for (int i = 1; i <= V; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	return minVertex;
}

int dijkstra(int s) {
	U[s] = true;

	for (int v = 1; v <= V; v++) {
		D[v] = A[s][v];
	}
	D[s] = 0;		// 문제에 따라서 출발 지점의 가중치가 0이 아닐 수도 있어서 0으로 초기화

	for (int i = 1; i < V; i++) {
		int w = extractMin();
		//extractMin에 우선순위 큐를 활용할 때 V에 비해 시작점에 인접한 정점은 매우 적으므로 dijkstra 틀을 바꿔야함
		U[w] = true;

		for (int v = 1; v <= V; v++) {
			if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v])	//min함수 안쓰고 풀기
				D[v] = D[w] + A[w][v];
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
	}

	int distance = dijkstra(1);

	cout << "최단거리: " << distance << endl;
	printDistance();
	return 0;
}
