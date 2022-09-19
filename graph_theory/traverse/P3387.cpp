#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5;
int h[maxn], dep, dfn[maxn], low[maxn], scccnt, sccnum[maxn], tot, in[maxn], h2[maxn], tot2;
struct Node{
	int v, next;
}t[maxn], t2[maxn];
void addEdge(int u, int v){
	++tot;
	t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}
void addEdge2(int u, int v){
	++tot2;
	t2[tot].v = v, t2[tot].next = h2[u], h2[u] = tot;
	in[v] ++;
}
stack <int> s;
int val[maxn];
int z[maxn];
void dfs(int u, int fa){
	low[u] = dfn[u] = ++dep;
	s.push(u);
	for (int i = h[u]; i; i = t[i].next){
		int v = t[i].v;
		if (!dfn[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if (!sccnum[i]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]){
		scccnt++;
		while(1){
			int tmp = s.top(); s.pop();
			sccnum[tmp] = scccnt;
			val[scccnt] += z[tmp];
			if (tmp == u) break;
		}
	}
}
int n, m;
int q[maxn];
int f[maxn];
int topo(int x){
    int res = 0;
    int front = 1, rear = 0;
    for (int i = 1; i <= x; i++){
        if (in[i] == 0){
            q[++rear] = i;
            f[i] = val[i];
        }
    }
    while(front <= rear){
        int u = q[front++];
        res = max(res, f[u]);
        for (int i = h2[u]; i; i = t[i].next){
        	f[t[i].v] = max(f[t[i].v], f[u] + val[t[i].v]);
        	res = max(res, f[t[i].v]);
            in[t[i].v] --;
            if (in[t[i].v] == 0) 
                q[++rear] = t[i].v;
        }
    }
    return res;
}
int main(){
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++){
		cin >> z[i];
	}
	while(m--){
		cin >> x >> y;
		addEdge(x, y);
	}
	for (int i = 1; i <= n; i++){
		if (!dfn[i]) 
		    dfs(i, 0);
	}
	int cnt2 = 0;
	for (int u = 1; u <= n; u++){
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (sccnum[u] != sccnum[v]){
				addEdge2(sccnum[u], sccnum[v]);
				cnt2++;
			}
		}
	}
	if (scccnt == 1) cout << val[1];
	else cout << topo(cnt2);
	return 0;
}