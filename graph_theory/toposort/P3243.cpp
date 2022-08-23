#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5;
int n, m;

struct Node{
    int v, next;
}t[maxm << 2];
int in[maxn];
int tot = 0, h[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
    in[v] ++;
}

priority_queue<int> q;
int ans[maxn];
int cnt = 0;
void topo(){
    while(!q.empty()) q.pop();
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.top(); q.pop();
        ans[++cnt] = u;
        for (int i = h[u]; i; i = t[i].next){
            in[t[i].v] --;
            if (in[t[i].v] == 0)
                q.push(t[i].v);
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(in, 0, sizeof(in));
        memset(ans, 0, sizeof(ans));
        memset(h, 0, sizeof(h));
        cnt = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            t[i].v = t[i].next = 0;
        }
        int x, y;
        while(m--){
            cin >> x >> y;
            addEdge(y, x);
        }
        topo();
        if (cnt < n) cout << "Impossible!" << endl;
        else {
            for (int i = n; i >= 1; i--){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}