#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, maxm = 1e6 + 5;
long long cnt = 0;
struct Node{
	int u, v, w;
}t[maxn];
int siz[maxn];
int c[maxm];
//maxm:最大边数
//maxn:最大点数 
struct node{
	int v, c, nxt;
}e[maxm << 1];//内存地 
int tot = 0;
int h[maxn];
//u:开始
//v:结束
//c:边权 
void addEdge(int u, int v, int c){
	tot++;
	e[tot].v = v; e[tot].c = c; e[tot].nxt = h[u]; h[u] = tot;
}

int dfs(int u, int fa){
	siz[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if (v == fa) continue;
		c[v] = c[u] ^ e[i].c;
		dfs(v, u);
		//回溯
		siz[u] += siz[v]; 
	}
	return siz[u];
}

int main(){
	int n;
	scanf("%d", &n);
	int u, v, w, j = 0;
	for (int i = 1; i < n; i++){
		scanf("%d %d %d", &u, &v, &w);
		t[++j].u = u; t[j].v = v; t[j].w = w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	for (int i = 1; i < n; i++){
		cnt += t[i].w * abs(dfs(t[i].u, t[i].v) - dfs(t[i].v, t[i].u));
	}
	cout << cnt;
	return 0;
}
