#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e5 + 5;
typedef long long ll;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct Node{
    int v, next; 
}t[maxn];
int tot = 0, h[maxn];
void addEdge(int u, int v){
    ++tot;
    t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
struct Queue{
    int pos, val;
};
queue <Queue> q;
int dis[maxn], a[maxn];
int s;
void dijkstra(){
    q.push({s, a[s]});
    while(!q.empty()){
        int u = q.front().pos, val = q.front().val;
        dis[u] = val;
        q.pop();
        for (int i = h[u]; i; i = t[i].next){
            int v = t[i].v;
            q.push({v, val ^ a[v]});
        }
    }
}
set <int> s1;
set <int> ::iterator it;
signed main(){
    srand(time(0));
    int n = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
    }
    int x;
    for (int i = 1; i <= n; i++){
        x = read();
        if (x == 0) s = i;
        else addEdge(x, i);
    }
    dijkstra();
    //从源点算到各个点的异或值，两个点的异或值再异或就消掉上面的部分了
    /*
    //已知一个序列求任选两个数异或的最大值不会O(n),只会暴力……所以后面就是随机化的了……
    if (n <= 1e4){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                ans = max(ans, dis[i] ^ dis[j]);
            }
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            for (int id = 1; id <= 500; id++){
                int j = rand() % n + 1;
                ans = max(ans, dis[i] ^ dis[j]);
            }
        }
    }
    */
    /*
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ans = max(ans, dis[i] ^ dis[j]);
        }
    }
    */
    long long ans = 0, tot = 0;
    for (int i = 32; i >= 0; i--){
        s1.clear();
        tot |= (1 << i);
        for (int j = 1; j <= n; j++) s1.insert(tot & dis[j]);
        for (it = s1.begin(); it != s1.end(); it++){
            if (s1.count(ans + (1 << i) ^ (*it))){
                ans += (1 << i);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}