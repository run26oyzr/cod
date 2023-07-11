#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int f[maxn], c[maxn], s[maxn], ff[maxn];
int n, k;
int pow2(int x){
    return x * x;
}
int X(int x){
    return s[x];
}
int Y(int x){
    return ff[x] - pow2(s[x]);
}
long double getK(int j1, int j2){
    if (X(j2) == X(j1)) return 1e19;
    return 1.0 * (Y(j2) - Y(j1)) / (X(j2) - X(j1));
}
int getK0(int i){
    return -s[i];
}
signed q[maxn];
int front = 1, rear = 1;
signed ans[205][maxn];
signed main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        s[i] = s[i - 1] + c[i];
    }
    for (int t = 1; t <= k; t++){
        for (int i = 1; i <= n; i++) ff[i] = f[i];
        memset(q, 0, sizeof(q));
        front = rear = 1;
        for (int i = 1; i <= n; i++){
            int k0 = getK0(i);
            while (front < rear && getK(q[front], q[front + 1]) >= k0) front++;
            int j = q[front];
            // cout << i << ' ' << j << endl;
            f[i] = ff[j] + (s[i] - s[j]) * s[j];
            ans[t][i] = j;
            while (front < rear && getK(q[rear - 1], q[rear]) <= getK(q[rear], i)) rear--;
            q[++rear] = i;
            // cout << "front:" << front << "; rear:" << rear << endl;
            // cout << t << ' ' << i << ' ' << f[i] << endl;
            // cout << endl;
        }
    }
    cout << f[n] << endl;
    int tmp = ans[k][n];
    // for (int i = 1; i <= k; i++){
    //     cout << tmp << ' ';
    //     tmp = ans[i - 1][tmp];
    // }
    for (int i = k; i >= 1; i--){
        cout << tmp << ' ';
        tmp = ans[i - 1][tmp];
    }
    return 0;
}