#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e3 + 5, maxm = 2 * 1e5 + 5; 
struct Node{
    int v, c, next;
}t[maxm << 2];
int tot = 0, h[maxn];
struct Queue{
    int id, dis;
    bool operator < (const Queue T)const{
        return dis > T.dis;
    }
};
void addEdge(int u, int v, int c){
    t[++tot].v = v;
    t[tot].c = c;
    t[tot].next = h[u];
    h[u] = tot;
}
priority_queue <Queue> q;
int dis[maxn], vis[maxn];
int prim(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    Queue now, nt;
    q.push(Queue{1, 0});
    int res = 0;
    while(!q.empty()){
        int u = q.top().id; q.pop();
        if (vis[u]) continue;
        res += dis[u];
        vis[u] = 1;
        for (int i = h[u]; i; i = t[i].next){
            int v = t[i].v;
            if (dis[v] > t[i].c){
                dis[v] = t[i].c;
                q.push(Queue{v, dis[v]});
            }
        }
    }
    return res;
}
int main(){
    int n, m;
    cin >> n >> m;
    int x, y, z;
    while(m--){
        cin >> x >> y >> z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    int ans = prim();
    for (int i = 1; i <= n; i++){
        if (vis[i] == 0){
            cout << "orz";
            system("pause");
            return 0;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}