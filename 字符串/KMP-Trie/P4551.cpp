#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxln = 32;

struct Node{
    int v, c, next;
}t[maxn << 1];
int h[maxn], tot;
void addEdge(int u, int v, int c){
    ++tot;
    t[tot].c = c, t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}

int dis[maxn];
void dfs(int u, int fa){
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa) continue;
        dis[v] = dis[u] ^ t[i].c;
        dfs(v, u);
    }
}

int ch[maxn * maxln][2];
int Tot = 0;
void insert(int x){
    int p = 0;
    for (int i = maxln - 1; i >= 0; i--){
        int y = (x >> i) & 1;
        if (!ch[p][y])
            ch[p][y] = ++Tot;
        p = ch[p][y]; 
    }
} 

int solve(int id){
    int x = dis[id];
    int p = 0;
    int num = 0;
    for (int i = maxln - 1; i >= 0; i--){
        int y = (x >> i) & 1;
        if (ch[p][y ^ 1]){
            p = ch[p][y ^ 1];
            num += (1 << i);
        }else{
            p = ch[p][y];
        }
    }
    // cout << id << ' ' << dis[id] << ' ' << num << endl;
    return num;
}

int main(){
    int n;
    cin >> n;
    int u, v, val;
    for (int i = 1; i <= n - 1; i++){
        cin >> u >> v >> val;
        addEdge(u, v, val);
        addEdge(v, u, val);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        insert(dis[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, solve(i));
    cout << ans;
    return 0;
}