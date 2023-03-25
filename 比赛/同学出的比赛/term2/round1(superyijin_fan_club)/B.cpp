#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2 * 1e5 + 5;
int tree[maxn];
int a[maxn];
int tmp[maxn];
int n;
struct Node{
	int pos, num;
	bool operator < (const Node T)const{
//		if (num < 0) 
		if (num == T.num) return pos > T.pos;
		return num > T.num;
	}
}sum[maxn];
int lowbit(int x){return x & (-x);}
void change(int id, int val){
	while(id <= n){
		tree[id] += val;
		id += lowbit(id);
	}
}
int query(int id){
	int res = 0;
	while(id >= 1){
		res += tree[id];
		id -= lowbit(id);
	}
	return res;
}
bool check(int x){
	sum[0].num = 0;
	sum[0].pos = 0;
	for (int i = 1; i <= n; i++){
		sum[i].pos = i;
		if (a[i] >= x) sum[i].num = sum[i - 1].num + a[i];
		else sum[i].num = sum[i - 1].num - a[i];
	}
	sort(sum, sum + n + 1);
	for (int i = 0; i <= n; i++){
		tmp[sum[i].pos] = i + 1;
	}
//	if (x == 9){
//		for (int i = 0; i <= n; i++){
//			cout << tmp[i] << ' ';
//		}
//		cout << endl;
//	}
	int res = 0;
	for (int i = 0; i <= n; i++) tree[i] = 0;
	for (int i = 0; i <= n; i++){
		res += query(tmp[i]);
		change(tmp[i], 1);
	}
//	cout << "check----------" << x << ' ' << res << endl;
	return (((n + 1) * n / 2 - res) >= res);
}
signed main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int l = -1e9 - 5, r = 1e9 + 5;
	while(l < r){
//		cout << "arange----------" << l << ' ' << r << endl;
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
//	if (!check(l)) l--;
	cout << l;
	return 0;
}