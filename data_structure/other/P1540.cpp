#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int vis[maxn];
queue <int> q;
int main(){
    int m, n;
    cin >> m >> n;
    int x;
    int cnt = 0;
    while(n--){
        cin >> x;
        if (vis[x]) continue;
        cnt++;
        q.push(x);
        vis[x] = 1;
        if (q.size() > m) {vis[q.front()] = 0; q.pop();}
    }
    cout << cnt;
    system("pause");
    return 0;
}