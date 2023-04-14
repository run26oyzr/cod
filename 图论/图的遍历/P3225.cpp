#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5, maxm = 1e3 + 5;

struct Node{
    int v, next;
}t[maxm << 2];
int tot = 0, h[maxn];
int in[maxn], out[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
    in[v]++;
    out[u]++;
}

int bccnum = 0;
vector<int> bcc[maxn];
stack <int> s;
int dfn[maxn], low[maxn], dep;
bool cut[maxn];
int root;
int son = 0;
void dfs(int u, int fa){
    dfn[u] = low[u] = ++dep;
    s.push(u);
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if(v == fa) continue;
        if (!dfn[v]){
            dfs(v, u);
            if (u == root) son++;
            low[u] = min(low[v], low[u]);
            if (low[v] >= dfn[u]){
            	cut[u] = 1;
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
}
int vis[maxn], cut_cnt, node_cnt;
void dfs(int u){
    vis[u] = 1;
    node_cnt++;
    if (cut[u]) cut_cnt++;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (!vis[v]) {
            vis[v] = 1;
            dfs(v);
        }
    }
}
unsigned long long solution_cnt, exit_cnt;
void init(){
    solution_cnt = 1, exit_cnt = 0;
    tot = 0;
    for (int i = 0; i < maxm << 2; i++) t[i].v = t[i].next = 0;
    for (int i = 0; i < maxn; i++){
        h[i] = 0;
        in[i] = 0;
        out[i] = 0;
        cut[i] = 0;
        low[i] = 0;
        dfn[i] = 0;
        vis[i] = 0;
        bcc[i].clear();
    }
    while(!s.empty()) s.pop();
    bccnum = 0, dep = 0;
}
int choose_two(int x){
    return x * (x - 1) / 2;
}
int main(){
    int n, m;
    int x, y;
    int times = 0;
    while(cin >> m&&m){
        times++;
        n = 0;
        init();
    	for (int i = 1; i <= m; i++){
        	cin >> x >> y;
            n = max(n, x);
            n = max(n, y);
        	if (x == y) continue;
    	    addEdge(x, y); addEdge(y, x);
    	}
    	for (int i = 1; i <= n; i++){
        	// if (out[i] == 0 && in[i] == 0){
            	// bccnum++;
            	// bcc[bccnum].push_back(i);
        	// }
        	// else if(!dfn[i]){
            if (!dfn[i]){
                root = i;
                dfs(i, 0);
                if (son > 1) cut[i] = 1;
                son = 0;
            }
    	}
    	for (int i = 1; i <= n; i++){
            cut_cnt = 0;
            node_cnt = 0;
            if (!vis[i] && !cut[i]){
                dfs(i);
                if (cut_cnt == 0){
                    exit_cnt += 2;
                    solution_cnt *= choose_two(node_cnt);
                }
                else if (cut_cnt == 1){
                    exit_cnt += 1;
                    solution_cnt *= node_cnt - 1;
                }
            }
        }
        printf("Case %d: %lld %lld\n", times, exit_cnt, solution_cnt);
    }
    system("pause");
    return 0;
}