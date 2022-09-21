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
	t2[tot2].v = v, t2[tot2].next = h2[u], h2[u] = tot2;
	in[v] ++;
}
stack <int> s;
int sum[maxn];
void dfs(int u){
	low[u] = dfn[u] = ++dep;
	s.push(u);
	for (int i = h[u]; i; i = t[i].next){
		int v = t[i].v;
		if (!dfn[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!sccnum[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]){
		scccnt++;
		while(1){
			int tmp = s.top(); s.pop();
			sccnum[tmp] = u;
			sum[u] ++;
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
        // cout << in[i] << endl;
        if (in[i] == 0 && sccnum[i] == i){
            q[++rear] = i;
            f[i] = sum[i];
        }
    }
    while(front <= rear){
        int u = q[front++];
        for (int i = h2[u]; i; i = t2[i].next){
        	f[t2[i].v] = max(f[t2[i].v], f[u] + sum[t2[i].v]);
            in[t2[i].v] --;
            if (in[t2[i].v] == 0) 
                q[++rear] = t2[i].v;
        }
    }
    for (int i = 1; i <= x; i++){
        if (f[i] == n) res++;
    } 
    return res;
}
int main(){
	cin >> n >> m;
	int x, y;
	while(m--){
		cin >> x >> y;
		addEdge(x, y);
	}
	for (int i = 1; i <= n; i++){
		if (!dfn[i]) 
		    dfs(i);
	}
	for (int u = 1; u <= n; u++){
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (sccnum[u] != sccnum[v]){
				addEdge2(sccnum[u], sccnum[v]);
			}
		}
	}

	// for (int i = 1; i <= n; i++){
	// 	if (sccnum[i] == i){
	// 		cout << i << ' ' << sum[i] << endl;
	// 	}
	// }
	// if (scccnt == 1) cout << sum[1];
	// else cout << topo(scccnt);
    cout << topo(n);
    system("pause");
	return 0;
}