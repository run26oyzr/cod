#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e6 + 5;
struct Node{
    int num, id;
    int type;
    bool operator < (const Node T) const{
        return num < T.num;
    } 
}t[maxn * 2];
int cnt[maxn]; //选区内第 i 个 a/b 出现的次数
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        t[i].id = i;
        t[i].type = 1;
        cin >> t[i].num;
    }
    for (int i = 1; i <= n; i++){
        t[i + n].id = i;
        t[i + n].type = 0;
        cin >> t[i + n].num;
    }
    n *= 2;
    sort(t + 1, t + n + 1);
    int r = n;
    int cnta = 0; //选区外 a 的出现次数（应 <= m）
    for (int i = 0; i <= n; i++)
        cnt[i] = 2;
    while (r >= 1 && cnt[t[r].id] == 2 && cnta + t[r].type <= m){
        cnt[t[r].id]--;
        cnta += t[r].type;
        r--;
    }
    int ans = 1e9;
    for (int l = 1; l <= n; l++){
        while (r <= n && (cnt[t[l - 1].id] == 0 || cnta > m)){
            r++;
            cnt[t[r].id]++;
            cnta -= t[r].type;
        }
        if (r > n)
            break; 
        ans = min(ans, t[r].num - t[l].num);
        cnt[t[l].id]--;
        cnta += t[l].type;
    }
    cout << ans;
}