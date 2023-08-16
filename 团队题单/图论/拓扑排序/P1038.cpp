#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5;
int n, m;
int c[maxn], u[maxn];

struct Node{
    int v, c, next;
}t[maxm << 2];
int tot = 0, h[maxn];
int in[maxn], out[maxn];
void addEdge(int u, int v, int c){
    t[++tot].v = v;
    t[tot].c = c;
    t[tot].next = h[u];
    h[u] = tot;
    in[v] ++;
    out[u] ++;
}

struct Queue{
    int id, val;
}q[maxn];
void topo(){
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) q[++rear].id = i, q[rear].val = c[i];
    }
    while(front <= rear){
        int val = q[front].val;
        int uu = q[front++].id;
        for (int i = h[uu]; i; i = t[i].next){
            c[t[i].v] += max(c[uu], 0) * t[i].c;
            in[t[i].v] --;
            if (in[t[i].v] == 0){
                c[t[i].v] -= u[t[i].v];
                c[t[i].v] = max(c[t[i].v], 0);
                q[++rear].id = t[i].v, q[rear].val = c[t[i].v];
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> c[i] >> u[i];
    }
    int x, y, z;
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    topo();
    int flag = 0;
    for (int i = 1; i <= n; i++){
        if (out[i] == 0 && c[i] > 0){
            cout << i << ' ' << c[i] << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "NULL";
    system("pause");
    return 0;
}