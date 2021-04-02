#include <iostream>

using namespace std;

//�κ����� : O(n^2)
//�ٽ� : �� ���Ұ� ���ԵǴ� ���� ���Ե��� �ʴ� ����� ����

const int N = 5;
const int CANDIDATE = N;

int src[] = { 6,2,8,3,4,5,1 };   //���� ������

void process_solution(int a[], int k, int n) {
	cout << "{ ";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";   //���� �迭�� ���� �ε��� ����
		//cout << src[i - 1] << " ";
	}
	cout << " } \n";
}

int make_candidate(int a[], int k, int n, int c[]) {
	// ���� : nPr = n * (n-1) * ..... * (n-r+1)
	//		  nPr = n* (n-1)P(r-1)           ( r<= n)
	// ������ �ٽ� ? �տ��� ������ ���� ������ �������� ���� ���� ����� �ȴ�.
	int inPerm[N+1] = { 0, };  //a[]�� ���Ե��� ���� üũ�ϱ� ���� �迭
	for (int i = 1; i < k; i++) {
		inPerm[a[i]]++;
	}

	int nCands = 0;
	for (int i = 1; i <= n; i++) {
		if (inPerm[i] == 0) {		//a[]�� ���Ե��� ���� ���̸�
			c[nCands] = i;
			nCands++;
		}
	}
	return nCands;
}


//a[] : �������� - ������� ���õ� �κ���
// k : �������տ� ���Ե� ���� ��, backtrack�� ȣ��� ����
// n : ��� ���� �� , Ǯ��� �� ����
void backtrack(int a[], int k, int n) {
	int c[CANDIDATE] = { 0, };      //�ĺ��� ����
	int nCands = 0;                 //�ĺ��� ���տ� ���Ե� ������ ��

	//����ġ�� �� ��ġ
	//����ġ�� �ϸ� �Ű����� ���ڰ� �ϳ��� �þ
	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;

		nCands = make_candidate(a, k, n, c);
		for (int i = 0; i < nCands; i++) {   //�ĺ����� �� ��ŭ �ݺ�
			a[k] = c[i];            //�ĺ��� �߿� �ϳ��� �������տ� �߰�
									//a �迭�� idx 1���� N���� ��� -> ó���� N+1 ������� ������ ����
			backtrack(a, k, n);
		}
	}
}
int main() {
	int a[N + 1] = { 0, };

	backtrack(a, 0, 3);


	return 0;
}