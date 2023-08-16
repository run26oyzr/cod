#include <bits/stdc++.h>
using namespace std;
char a[105], b[105];
int find(char x){
	int len = strlen(b);
	for (int i = 0; i < len; i++){
		if (b[i] == x) return i;
	}
	return 0;
}
void dfs(int lx, int rx, int lz, int rz){
	if (lx >= rx){
		if (lx == rx) cout << a[lx];
		return;
	}
	int id = find(a[rx]);
	int len = id - lz;
	cout << a[rx];   
	dfs(lx, lx + len - 1, lz, id - 1);
	dfs(lx + len, rx - 1, id + 1, rz);    
	return;                                           
}
int main(){
	scanf("%s\n%s", b, a);
	int len = strlen(a);
	dfs(0, len - 1, 0, len - 1);
	return 0;
}
