#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxm = 2 * 1e4 + 5; 
struct Edge{
    int u, v, c, id;
    bool operator < (const Edge T) const {
        return c < T.c;
    }
}t1[maxm], t2[maxn];//边c, u & v 不固定起点和终点, 存1遍

int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);//路径压缩
}

/**
 * @brief 
 *  最小生成树: n个顶点, n - 1条边, 联通图, 边权和最小
 *  kruskal: 贪心思想
 *      1. 将图中的边按照边权从小到大排序
 *      2. 将剩下的边中最小权值边, 加入到生成树中
 *          a) 形成回路   将此边从最小生成树中删除
 *          b) 不形成回路 此边在最小生成树中
 *      3. 重复执行第2步, 直到加入的边数 == n - 1
 */


/**
 * @brief 
 *  1.处于同一个连通块内    不需要加(continue)
 *  2.不处于同一个连通块内  需要加
 */
int tot = 0;
int ans[maxn];
int which_in[maxn];
int n, m, k;
int kruskal1(int x){
    int num = 0, res = 0;//num: 已加边数; res: 最小生成树的边权和
    sort(t1 + 1, t1 + m + 1);//按权值从小到大排序
    for (int i = 1; i <= n; i++) fa[i] = i;//初始化并查集
    for (int i = 1; i <= m; i++){
        int fu = getfather(t1[i].u);
        int fv = getfather(t1[i].v);
        if (fu == fv) continue;//已经处于同一个连通块
        num++;//统计已加边数
        ans[++tot] = t1[i].id;
        which_in[t1[i].id] = 1;
        res = max(res, t1[i].c);//加对应边权值
        fa[fu] = fv;//合并连通块
        if(num == x) break;//达到最小生成树边数n - 1
    }
    return res;
}
int kruskal2(int x){
    int num = 0, res = 0;//num: 已加边数; res: 最小生成树的边权和
    sort(t2 + 1, t2 + m + 1);//按权值从小到大排序
    for (int i = 1; i <= m; i++){
        int fu = getfather(t2[i].u);
        int fv = getfather(t2[i].v);
        if (fu == fv) continue;//已经处于同一个连通块
        num++;//统计已加边数
        ans[++tot] = t2[i].id;
        which_in[t2[i].id] = 2;
        res = max(res, t2[i].c);
        fa[fu] = fv;//合并连通块
        if(num == x) break;//达到最小生成树边数n - 1
    }
    return res;
}
struct ans_{
    int id, p;
    bool operator < (const ans_ T)const{
        return id < T.id;
    }
}_ans[maxn];
int main(){
    cin >> n >> k >> m;
    int x, y, z1, z2;
    for (int i = 1; i < m; i++){
        cin >> x >> y >> z1 >> z2;
        t1[i].u = x, t1[i].v = y, t1[i].c = z1, t1[i].id = i;
        t2[i].u = x, t2[i].v = y, t2[i].c = z2, t2[i].id = i;
    }
    x = kruskal1(k);
    y = kruskal2(n - k - 1);
    cout << max(x, y) << endl;
    for (int i = 1; i <= tot; i++){
        _ans[i].id = ans[i], _ans[i].p = which_in[ans[i]];
    }
    sort(_ans + 1, _ans + n);
    for (int i = 1; i <= tot; i++){
        cout << _ans[i].id << ' ' << _ans[i].p << endl;
    }
    system("pause");
    return 0;
}