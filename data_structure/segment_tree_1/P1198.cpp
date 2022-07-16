#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5;
int t[maxn << 2];
void add(int id, int L, int R, int val, int num){
	if (L == R){
		t[id] = val; return;
	}
	int mid = (L + R) >> 1;
	if (num <= mid) add(id << 1, L, mid, val, num);
	else add(id << 1 | 1, mid + 1, R, val, num);
	t[id] = max(t[id << 1], t[id << 1 | 1]);
}
int query(int id, int L, int R, int l, int r){
	if (l <= L && r >= R){
		return t[id];
	}
	int mid = (L + R) >> 1;
	int a = 0, b = 0;
	if (l <= mid) a = query(id << 1, L, mid, l, r);
	if (r > mid) b = query(id << 1 | 1, mid + 1, R, l, r);
	return max(a, b);
}
signed main()
{
	int cnt = 0, num = 0; 
	int m = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		char c; int x;
		cin >> c;
		if (c == 'A'){
			cin >> x;
			cnt ++;
			add(1, 1, n, (x + m) % k, cnt);
		}
		else{
			cin >> x;
			m = query(1, 1, n, cnt - x + 1, n);
			cout << m << endl;
		}
	}
	return 0;
}
