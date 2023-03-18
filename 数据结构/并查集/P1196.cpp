#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5;
int fa[maxn], dis[maxn], siz[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    int fx = getfather(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = fx;
}
void merge(int x, int y, int mod = 0){
    int fx = getfather(x);
    int fy = getfather(y);
    fa[fx] = fy;
    dis[fx] = siz[fy];
    siz[fy] += siz[fx];
    return;
}
int query(int x, int y, int mod = 0){
    int fx = getfather(x);
    int fy = getfather(y);
    if(fx == fy) return abs(dis[y] - dis[x]) - 1;
    return -1;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
        siz[i] = 1;
        dis[i] = 0;
    }
    int x, y, z;
    char c;
    while(n--){
        cin >> c;
        cin >> x >> y;
        if (c == 'M'){
            merge(x, y);
        }
        else{
            cout << query(x, y) << endl;
        }
    }
    system("Pause");
    return 0;
}