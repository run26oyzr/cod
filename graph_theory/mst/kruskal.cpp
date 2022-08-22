#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5; 
struct Edge{
    int u, v, c;
    bool operator < (const Edge T) const {
        return c < T.c;
    }
}t[maxm];//边c, u & v 不固定起点和终点, 存1遍

int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);//路径压缩
}

/*  对于一个边的端点i, j
 *  1.处于同一个连通块内    不需要加(continue)
 *  2.不处于同一个连通块内  需要加
 */
int n, m;
int kruskal(){
    int num = 0, res = 0;//num: 已加边数; res: 最小生成树的边权和
    sort(t + 1, t + m + 1);//按权值从小到大排序
    for (int i = 1; i <= n; i++) fa[i] = i;//初始化并查集
    for (int i = 1; i <= m; i++){
        int fu = getfather(t[i].u);
        int fv = getfather(t[i].v);
        if (fu == fv) continue;//已经处于同一个连通块
        num++;//统计已加边数
        res += t[i].c;//加对应边权值
        fa[fu] = fv;//合并连通块
        if(num == n - 1) break;//达到最小生成树边数n - 1
    }
    return res;
}
int main(){

    return 0;
}