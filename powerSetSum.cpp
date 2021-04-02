#include <iostream>

using namespace std;

//부분집합 : O(n^2)
//핵심 : 각 원소가 포함되는 경우와 포함되지 않는 경우의 조합

const int N = 100;
const int CANDIDATE = 2;

int K;
int cnt;

void process_solution(int a[], int k, int n) {
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			sum += i;   //원본 배열에 대한 인덱스 생성
		}
	}

	if (sum == K)
	{
		cnt++;
		//cout << "{ ";
		//for (int i = 1; i <= n; i++) {
		//	if (a[i] == 1) {
		//		cout << i << " ";   //원본 배열에 대한 인덱스 생성
		//	}
		//}
		//cout << " } \n";
	}
}

int make_candidate(int a[], int k, int n, int c[]) {
	c[0] = 1;   //포함되는 경우
	c[1] = 0;   //포함되지 않는 경우

	return 2;
}


//a[] : 선택집합 - 현재까지 선택된 부분해
// k : 선택집합에 포함된 해의 수, backtrack이 호출된 깊이
// n : 모든 선택 수 , 풀어야 될 숫자
void backtrack(int a[], int k, int n, int cSum, int tSum) {
	int c[CANDIDATE] = { 0, };      //후보해 집합
	int nCands = 0;                 //후보해 집합에 포함된 원소의 수

	//가지치기
	if (cSum > K) return;		//현재까지 고려한 값을 가지고 찾은 가지치기 조건
	if (cSum + tSum < K) return;	//미래에 구할 수 있는 값을 가지고 찾은 가지치기 조건

	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;

		nCands = make_candidate(a, k, n, c);
		for (int i = 0; i < nCands; i++) {   //후보해의 수 만큼 반복
			a[k] = c[i];            //후보해 중에 하나를 선택집합에 추가
									//a 배열은 idx 1부터 N까지 사용 -> 처음에 N+1 사이즈로 선언한 이유
			int num = 0;
			if (a[k] == 1) {
				num = k;
			}
			if (cSum + num <= K || cSum + tSum >= K) { //호출 전에 검사
				backtrack(a, k, n, cSum + num, tSum - k);
			}
		}
	}
}
int main() {
	int a[N + 1] = { 0, };

	int tSum = N * (N + 1) / 2;
	K = 5000;

	backtrack(a, 0, N, 0, tSum);

	cout << cnt << endl;

	return 0;
}