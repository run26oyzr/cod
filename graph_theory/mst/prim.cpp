#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5; 

struct Node{
    int v, c, next;
}t[maxm << 2];
int tot = 0, h[maxn];
void addEdge(int u, int v, int c){
    t[++tot].v = v;
    t[tot].c = c;
    t[tot].next = h[u];
    h[u] = tot;
}

/**
 * @brief
 *  最小生成树: n个顶点, n - 1条边, 联通图, 边权和最小
 *  prim: 对于任意顶点, 选择权值最小的边加入
 *      1. 选择一个顶点, 加入到S集合中
 *      2. 从S顶点出发, 扩展边到达S的邻域, 加入到最小生成树中
 *      3. 重复第2步，直到S集合中的顶点数量 == n
 */
struct Queue{
    int id, dis;//dis优化
    bool operator < (const Queue T)const{
        return dis > T.dis;//dis越小越靠前
    }
};
priority_queue <Queue> q;
int dis[maxn], vis[maxn];//dis: 该点与点集S之间的最短距离; vis: 是否已经作为最优值更新过其它节点
int prim(){
    dis[1] = 0;
    Queue now, nt;
    q.push(Queue{0, 1});
    int res = 0;
    while(!q.empty()){
        int u = q.top().id; q.pop();
        if (vis[u]) continue;//已经作为最优值更新过其它节点
        res += dis[u];//累加边权
        vis[u] = 1;
        for (int i = h[u]; i; i = t[i].next){//从i点扩展
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