#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000, maxm = 1e6 + 5;

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
int topo(int x, int y){
    int res = 0;
    int front = 1, rear = 0;
    for (int i = x; i <= y; i++){
        if (in[i] == 0){
            q[++rear] = i;
            f[i] = 1;
        }
    }
    while(front <= rear){
        int u = q[front++];
        for (int i = h[u]; i; i = t[i].next){
            f[t[i].v] = min(f[t[i].v], f[u] + 1);
            in[t[i].v] --;
            if (in[t[i].v] != 0) continue;
            else q[++rear] = t[i].v;
        }
    }
    return res;
}

int n, m;
int ain[maxn], vis[maxn], aout[maxn];
int main(){
    cin >> n >> m;
    int tt = n + m;
    int c;
    while(m--){
        cin >> c;
        int toti = 0, toto = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= c; i++){
            cin >> ain[i];
            vis[ain[i]] = 1;
        }
        for (int i = ain[i] + 1; i < ain[c]; i++){
            if(!vis[i]){
                aout[++toto] = i;
            }
        }
        int ss = n + m;
        for (int i = 1; i <= toto; i++)
            addEdge(aout[i], ss);
        for (int i = 1; i <= c; i++)
            addEdge(ss, ain[i]);
    }
    cout << (tt - n) - topo(1, tt);// m = tt - n   ans-(tt - n)
    system("pause");
    return 0;
}