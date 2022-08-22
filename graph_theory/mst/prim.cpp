#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5; 
struct Node{
    int v, c, next;
}t[maxm << 2];
int tot = 0, h[maxn];
struct Queue{
    int id, dis;//dis优化
    bool operator < (const Queue T)const{
        return dis > T.dis;//dis越小越靠前
    }
};
void addEdge(int u, int v, int c){
    t[++tot].v = v;
    t[tot].c = c;
    t[tot].next = h[u];
    h[u] = tot;
}
priority_queue <Queue> q;
int dis[maxn], vis[maxn];//dis:该点与点集S之间的最短距离
int prim(){
    dis[1] = 0;
    Queue now, nt;
    q.push(Queue{0, 1});
    int res = 0;
    while(!q.empty()){
        int u = q.top().id; q.pop();
        if (vis[u]) continue;//vis:是否已经作为最优值更新过其它节点
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

    return 0;
}