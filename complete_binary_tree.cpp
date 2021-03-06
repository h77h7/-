#include <iostream>

using namespace std;

const int TREE_SIZE = 50;

int tree[TREE_SIZE] = { 0, };
int V;
int E;

int findNode(int node) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == node) return i;
	}
	return -1;
}

void preorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	cout << tree[node] << " ";             // V
	preorder(node << 1);                   // L
	preorder(node << 1 | 1);               // R
}

void inorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	
	inorder(node << 1);                   // L
	cout << tree[node] << " ";             // V
	inorder(node << 1 | 1);               // R
}

void postorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	postorder(node << 1);                   // L
	postorder(node << 1 | 1);               // R
	cout << tree[node] << " ";             // V
}

void levelorder(int node) {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextlevel = 1;
	for (int i = 1; i < TREE_SIZE; i++) {
		if (i == pow2[nextlevel]) {
			cout << endl;
			nextlevel++;
		}
		if (tree[i]) {
			cout << tree[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	freopen("tree_input.txt", "r", stdin);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int parent, child;
		cin >> parent >> child;

		int pIdx = findNode(parent); //부모노드 위치 찾기
		if (pIdx < 1) {
			pIdx = 1;		//부모노드 못찾았으면 root로 설정
			tree[pIdx] = parent;
		}
		if (tree[2 * pIdx] == 0)
			tree[2 * pIdx] = child;
		else tree[2 * pIdx + 1] = child;
	}

	cout << "전위순회 : ";
	preorder(1);
	cout << endl << endl;

	cout << "중위순회 : ";
	inorder(1);
	cout << endl << endl;

	cout << "후위순회 : ";
	postorder(1);
	cout << endl << endl;

	cout << "레벨순회 : \n";
	levelorder(1);
	cout << endl << endl;
}