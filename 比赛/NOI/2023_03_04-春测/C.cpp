#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
struct Node{
	long double x, y;
};
Node t[maxn];
long double dis(int x, int y){
	return sqrt(pow((t[x].x - t[y].x), 2) + pow((t[x].y - t[y].y), 2));
}
long double minans = 1e9;
int minsol[20];
int n;
void dfs(int step, int sol[20]){
	if (step == n + 1){
		long double res = 0;
		for (int i = 2; i <= n; i++){
			res += dis(sol[i - 1], sol[i]);
		}
		if (res < minans){
			minans = res;
			for (int i = 1; i <= n; i++) minsol[i] = sol[i];
		}
		return;
	}
	for (int i = 1; i <= n; i++){
		bool flag = false;
		for (int j = 1; j < step; j++)
			if (sol[j] == i){flag = true; break;}
		if(flag) continue;
		sol[step] = i;
		dfs(step + 1, sol);
	}
	return;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	bool Bflag = true;
	int maxy = 0, maxid;
	for (int i = 1; i <= n; i++){
		cin >> t[i].x >> t[i].y;
		if (i != 1){
			if (t[i].x < t[i-1].x || t[i].y > t[i-1].y) Bflag = false;
		}
		if (t[i].y > maxy){
			maxy = t[i].y;
			maxid = i;
		}
	}
	if (n < 20){
		int A[20];
		for(int i = 0; i < 20; i++) A[i] = 0;
		A[1] = maxid;
		dfs(2, A);
		for (int i = 1; i <= n; i++) cout << minsol[i] << ' ';
	}else{
		if(Bflag){
			for (int i = 1; i <= n; i++) cout << i << ' ';
		}else{
			for (int i = maxid; i >= 1; i--) cout << i << ' ';
			for (int i = maxid + 1; i <= n; i++) cout << i << ' ';
		}
	}
	return 0;
}
