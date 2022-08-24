#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, maxm = 3 * 1e6 + 5;

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
int st[maxn];
int tp;
vector<int> bcc[maxn];
int dfn[maxn], low[maxn], dep;
bool cut[maxn];
void dfs(int u, int fa){
    dfn[u] = low[u] = ++dep;
    int son = 0;
    st[++tp] = u;
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if(v == fa) continue;
        son++;
        if (!dfn[v]){
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            if (low[v] > dfn[u]){
                bccnum++;
                while(1){
                    int tmp = st[tp--];
                    bcc[bccnum].push_back(tmp);
                    if(tmp == v) break;
                }
                bcc[bccnum].push_back(u);
            }
        }
        else low[u] = min(dfn[v], low[u]);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        if (x == y) continue;
        addEdge(x, y); addEdge(y, x);
    }
    for (int i = 1; i <= n; i++){
        if (out[i] == 0 && in[i] == 0){
            bccnum++;
            bcc[bccnum].push_back(i);
        }
        else if(!dfn[i]) dfs(i, 0);
    }
    cout << bccnum << endl;
    for (int i = 1; i <= bccnum; i++){
        cout << bcc[i].size() << ' ';
        while(!bcc[i].empty()){
            cout << bcc[i].back() << ' ';
            bcc[i].pop_back();
        }
        
        cout << endl;
    }
    system("pause");
    return 0;
}