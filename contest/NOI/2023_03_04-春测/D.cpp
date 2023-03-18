#include <bits/stdc++.h>
using namespace std;
const int maxn = 15 * 1e4 + 5;
int a[5][maxn];
int k;
int n;
int dfs(int step, int A[25], int B[25]){
	if (step == n + 1){
		int res = 0;
		int minnum = 1e9, maxnum = 0;
		for (int i = 1; i <= n; i++){
			minnum = min(minnum, A[i]);
			maxnum = max(maxnum, A[i]);
		}
		res = max(res, maxnum - minnum);
		minnum = 1e9, maxnum = 0;
		for (int i = 1; i <= n; i++){
			minnum = min(minnum, B[i]);
			maxnum = max(maxnum, B[i]);
		}
		res = max(res, maxnum - minnum);
		return res;
	}
	int C[25], D[25];
	for (int i = 1; i < step; i++) C[i] = A[i], D[i] = B[i];
	int res = 1e9;
	C[step] = a[1][step];
	D[step] = a[2][step];
	res = min(res, dfs(step + 1, C, D));
	C[step] = a[2][step];
	D[step] = a[1][step];
	res = min(res, dfs(step + 1, C, D));
	return res;
}
void func(){
	cin >> n;
	int minnum = 1e9, maxnum = 0;
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			minnum = min(minnum, a[i][j]);
			maxnum = max(maxnum, a[i][j]);
		}
	}
	if (k == 1){
		cout << maxnum - minnum << endl;
		return; 
	}else if(k == 2){
		int A[25], B[25];
		for (int i = 0; i < 25; i++) A[i] = B[i] = 0;
		cout << dfs(1, A, B) << endl;
	}else{
		cout << 0 << endl;
		return;	
	}
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int T;
	cin >> T >> k;
	while(T--) func();
	return 0;
}
