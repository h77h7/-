#include <iostream>

using namespace std;

//�κ����� : O(n^2)
//�ٽ� : �� ���Ұ� ���ԵǴ� ���� ���Ե��� �ʴ� ����� ����

const int N = 100;
const int CANDIDATE = 2;

int K;
int cnt;

void process_solution(int a[], int k, int n) {
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			sum += i;   //���� �迭�� ���� �ε��� ����
		}
	}

	if (sum == K)
	{
		cnt++;
		//cout << "{ ";
		//for (int i = 1; i <= n; i++) {
		//	if (a[i] == 1) {
		//		cout << i << " ";   //���� �迭�� ���� �ε��� ����
		//	}
		//}
		//cout << " } \n";
	}
}

int make_candidate(int a[], int k, int n, int c[]) {
	c[0] = 1;   //���ԵǴ� ���
	c[1] = 0;   //���Ե��� �ʴ� ���

	return 2;
}


//a[] : �������� - ������� ���õ� �κ���
// k : �������տ� ���Ե� ���� ��, backtrack�� ȣ��� ����
// n : ��� ���� �� , Ǯ��� �� ����
void backtrack(int a[], int k, int n, int cSum, int tSum) {
	int c[CANDIDATE] = { 0, };      //�ĺ��� ����
	int nCands = 0;                 //�ĺ��� ���տ� ���Ե� ������ ��

	//����ġ��
	if (cSum > K) return;		//������� ����� ���� ������ ã�� ����ġ�� ����
	if (cSum + tSum < K) return;	//�̷��� ���� �� �ִ� ���� ������ ã�� ����ġ�� ����

	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;

		nCands = make_candidate(a, k, n, c);
		for (int i = 0; i < nCands; i++) {   //�ĺ����� �� ��ŭ �ݺ�
			a[k] = c[i];            //�ĺ��� �߿� �ϳ��� �������տ� �߰�
									//a �迭�� idx 1���� N���� ��� -> ó���� N+1 ������� ������ ����
			int num = 0;
			if (a[k] == 1) {
				num = k;
			}
			if (cSum + num <= K || cSum + tSum >= K) { //ȣ�� ���� �˻�
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