#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1005;
struct Node{
    int x, p;
    bool operator < (const Node T) const{
        return x < T.x;
    }
}t[maxn];
int q[maxn], front = 1, rear = 0;
int f[maxn][maxn];
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i].x >> t[i].p;
    }
    sort(t + 1, t + n + 1);
    int k;
    long long ans = 0;
    for (int j = 2; j <= n; j++){
        k = j - 1;
        for (int i = j + 1; i <= n; i++){
            while (front <= rear && f[j][q[rear]] <= f[j][k]) rear--;
            while (t[j].x - t[k].x <= t[i].x - t[j].x) {q[++rear] = k, k--;}
            f[i][j] = f[j][q[front]] + t[i].p;
            ans = max(ans, f[i][j]);
        }
    }
    for (int j = n - 1; j >= 2; j--){
        k = j + 1;
        for (int i = j - 1; i >= n; i++){
            while (front <= rear && f[j][q[rear]] <= f[j][k]) rear--;
            while (t[j].x - t[k].x <= t[i].x - t[j].x) {q[++rear] = k, k++;}
            f[i][j] = f[j][q[front]] + t[i].p;
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
    system("pause");
    return 0;
}