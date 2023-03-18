#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5, maxm = 1e3 + 5; 
int n, m;

struct Node{
    int v, next;
    long double c;
}t[maxm * maxm * 4];
int tot = 0, h[maxn];
void addEdge(int u, int v, long double c){
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

int nx[maxn], ny[maxn];
long double dis2(int x, int y){
    return sqrt(pow(abs(nx[x] - nx[y]), 2) + pow(abs(ny[x] - ny[y]), 2));
}
int vis2[maxn][maxn];
int main(){
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++){
        cin >> nx[i] >> ny[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        addEdge(x, y, 0);
        addEdge(y, x, 0);
        vis2[x][y] = vis2[y][x] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!vis2[i][j]){
                addEdge(i, j, dis2(i, j));
                vis2[i][j] = 1;
            }
        }
    }
    // cout << prim(1) << endl;
    printf("%.2Lf", prim(1));
    system("pause");
    return 0;
}