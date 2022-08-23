#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5, mod = 80112002;
int n, m;

struct Node{
    int v, next;
}t[maxm << 2];
int tot = 0, h[maxn];
int in[maxn], out[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
    in[v] ++;
    out[u] ++;
}

int q[maxn];
int f[maxn];
int topo(){
    int res = 0;
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0){
            q[++rear] = i;
            f[i] = 1;
        }
    }
    while(front <= rear){
        int u = q[front++];
        if (out[u] == 0)
            res += f[u], res %= mod;
        for (int i = h[u]; i; i = t[i].next){
            f[t[i].v] += f[u]; f[t[i].v] %= mod;
            in[t[i].v] --;
            if (in[t[i].v] != 0) continue;
            else q[++rear] = t[i].v;
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--){
        scanf("%d %d", &x, &y);
        addEdge(x, y);
    }
    cout << topo();
    system("pause");
    return 0;
}