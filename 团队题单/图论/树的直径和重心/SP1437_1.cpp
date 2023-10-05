//dfs，无法解决负权边
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
struct Node{
    int v, next;
}t[maxn << 1];
int h[maxn], tot = 0;
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v, t[tot].next = h[u], h[u] = tot;
}
int maxdep = 0, longest;
void dfs(int u, int fa, int depth){
    if (depth > maxdep){
        maxdep = depth;
        longest = u;
    }
    for (int i = h[u]; i; i = t[i].next){
        int v = t[i].v;
        if (v == fa)
            continue;
        dfs(v, u, depth + 1);
    }
}
int main(){
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0, 0);
    dfs(longest, 0, 0);
    cout << maxdep;
    return 0;
}