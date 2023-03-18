#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
	int left, right;
	int sum, lazy;
};
int n, m, a[maxn];
Node t[maxn << 2];
void update(int id){
	t[id].sum = t[id << 1].sum + t[id << 1].lazy * (t[id << 1].right - t[id << 1].left + 1)+
				t[id << 1 | 1].sum + t[id << 1 | 1].lazy * (t[id << 1 | 1].right - t[id << 1 | 1].left + 1);
}
void pushdown(int id){
	if (t[id].lazy != 0){
		t[id << 1].lazy += t[id].lazy;
		t[id << 1 | 1].lazy += t[id].lazy;
		
		t[id].sum += t[id].lazy * (t[id].right - t[id].left + 1);
		t[id].lazy = 0; 
	}
}
void buildtree(int id, int L, int R){
	t[id].left = L, t[id].right = R, t[id].lazy = 0;
	if (L == R){
		t[id].sum = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildtree(id << 1, L, mid);
	buildtree(id << 1 | 1, mid + 1, R);
	update(id);
}
void buildtree(){
	int len = 1;
	while (len < n) len *= 2;
	for (int id = len; id < len * 2; id++){
		t[id].left = t[id].right = id - len + 1;
		t[id].lazy = 0;
		t[id].sum = a[id - len + 1];
	}
	for (int id = len - 1; id >= 1; id--){
		t[id].left = t[id << 1].left;
		t[id].right = t[id << 1 | 1].right;
		t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
		t[id].lazy = 0;
	}
}
void change(int id, int L, int R, int c){
	if (t[id].left == L && t[id].right == R){
		t[id].lazy += c;
		return;
	}
	//lazy �·� ��ɫ��
	pushdown(id);
	//��ȫ����
	if (R <= t[id << 1].right) change(id << 1, L, R, c);
	//��ȫ����
	else if (t[id << 1 | 1].left <= L) change(id << 1 | 1, L, R, c);
	//��Խ����
	else {
		change(id << 1, L, t[id << 1].right, c);
		change(id << 1 | 1, t[id << 1 | 1].left, R, c);
	}
	//���� ��ɫ��
	update(id);
}
int query(int id, int L, int R){
//	cout << id << ' ' << t[id].left << ' ' << t[id].right << endl;
	if (t[id].left == L && t[id].right == R){
		return t[id].sum + t[id].lazy * (t[id].right - t[id].left + 1);
	}
	pushdown(id);
	if (R <= t[id << 1].right) return query(id << 1, L, R);
	else if (t[id << 1 | 1].left <= L) return query(id << 1 | 1, L, R);
	else 
		return query(id << 1, L, t[id << 1].right) + query(id << 1 | 1, t[id << 1 | 1].left, R);
}
signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	buildtree(1, 1, n);
//	buildtree();
	while (m--){
		int x, y, z, b;
		cin >> x;
		if (x == 1){
			cin >> y >> z >> b;
			change(1, y, z, b);
		}
		else if (x == 2){
			cin >> y >> z;
			cout << query(1, y, z) << endl;
		}
	}
	system("PAUSE");
	return 0;
}
