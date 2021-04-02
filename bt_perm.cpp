#include <iostream>

using namespace std;

//부분집합 : O(n^2)
//핵심 : 각 원소가 포함되는 경우와 포함되지 않는 경우의 조합

const int N = 5;
const int CANDIDATE = N;

int src[] = { 6,2,8,3,4,5,1 };   //원본 데이터

void process_solution(int a[], int k, int n) {
	cout << "{ ";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";   //원본 배열에 대한 인덱스 생성
		//cout << src[i - 1] << " ";
	}
	cout << " } \n";
}

int make_candidate(int a[], int k, int n, int c[]) {
	// 순열 : nPr = n * (n-1) * ..... * (n-r+1)
	//		  nPr = n* (n-1)P(r-1)           ( r<= n)
	// 순열의 핵심 ? 앞에서 선택한 것을 제외한 나머지가 다음 선택 대상이 된다.
	int inPerm[N+1] = { 0, };  //a[]에 포함도니 값을 체크하기 위한 배열
	for (int i = 1; i < k; i++) {
		inPerm[a[i]]++;
	}

	int nCands = 0;
	for (int i = 1; i <= n; i++) {
		if (inPerm[i] == 0) {		//a[]에 포함되지 않은 값이면
			c[nCands] = i;
			nCands++;
		}
	}
	return nCands;
}


//a[] : 선택집합 - 현재까지 선택된 부분해
// k : 선택집합에 포함된 해의 수, backtrack이 호출된 깊이
// n : 모든 선택 수 , 풀어야 될 숫자
void backtrack(int a[], int k, int n) {
	int c[CANDIDATE] = { 0, };      //후보해 집합
	int nCands = 0;                 //후보해 집합에 포함된 원소의 수

	//가지치기 들어갈 위치
	//가지치기 하면 매개변수 숫자가 하나씩 늘어남
	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;

		nCands = make_candidate(a, k, n, c);
		for (int i = 0; i < nCands; i++) {   //후보해의 수 만큼 반복
			a[k] = c[i];            //후보해 중에 하나를 선택집합에 추가
									//a 배열은 idx 1부터 N까지 사용 -> 처음에 N+1 사이즈로 선언한 이유
			backtrack(a, k, n);
		}
	}
}
int main() {
	int a[N + 1] = { 0, };

	backtrack(a, 0, 3);


	return 0;
}