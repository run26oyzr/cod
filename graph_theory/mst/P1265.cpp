#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e3 + 5, maxm = 5 * 1e3 + 5; 
int n, m;

int nx[maxn], ny[maxn];
long double dis2(int x, int y){
    return sqrt(pow(abs(nx[x] - nx[y]), 2) + pow(abs(ny[x] - ny[y]), 2));
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
    int id;//dis优化
    long double dis;
    bool operator < (const Queue T)const{
        return dis > T.dis;//dis越小越靠前
    }
};
priority_queue <Queue> q;
long double dis[maxn];
int vis[maxn];//dis: 该点与点集S之间的最短距离; vis: 是否已经作为最优值更新过其它节点
long double prim(int x){
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[x] = 0;
    Queue now, nt;
    q.push(Queue{x, 0});
    long double res = 0;
    while(!q.empty()){
        int u = q.top().id; q.pop();
        if (vis[u]) continue;//已经作为最优值更新过其它节点
        res += dis[u];//累加边权
        vis[u] = 1;
        for (int i = 1; i <= n; i++){//从i点扩展
            int v = i;
            if (vis[i]) continue;
            if (i == u) continue;
            if (dis[v] > dis2(u, v)){
                dis[v] = dis2(u, v);
                q.push(Queue{v, dis2(u, v)});
            }
        }
    }
    return res;
}

int main(){
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++){
        cin >> nx[i] >> ny[i];
    }
    printf("%.2Lf", prim(1));
    system("pause");
    return 0;
}