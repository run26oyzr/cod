#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int f[maxn];
int c[maxn], x[maxn], p[maxn];
int s[maxn], smul[maxn];
int n, k;
int pow2(int x){
    return x * x;
}
int X(int x){
    return s[x];
}
int Y(int x){
    return f[x] + smul[x];
}
long double getK(int j1, int j2){
    if (X(j1) == X(j2)) return 1e18;
    return 1.0 * (Y(j2) - Y(j1)) / (X(j2) - X(j1));
}
int getK0(int i){
    return x[i];
}
signed q[maxn];
int front = 1, rear = 1;
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld %lld %lld", &x[i], &p[i], &c[i]);
        s[i] = s[i - 1] + p[i];
        smul[i] = smul[i - 1] + x[i] * p[i];
    }
    for (int i = 1; i <= n; i++){
        int k0 = getK0(i);
        while (front < rear && getK(q[front], q[front + 1]) <= k0) front++;
        int j = q[front];
        // cout << i << ' ' << j << endl;
        f[i] = f[j] + x[i] * (s[i] - s[j]) - (smul[i] - smul[j]) + c[i];
        while (front < rear && getK(q[rear - 1], q[rear]) >= getK(q[rear], i)) rear--;
        q[++rear] = i;
        // cout << "front:" << front << "; rear:" << rear << endl;
        // cout << i << ' ' << f[i] << endl;
        // cout << endl;
    }
    int ans = 1e18;
    for (int i = n; i >= 1; i--){
        ans = min(ans, f[i]);
        if (p[i]) break;
    }
    cout << ans << endl;
    return 0;
}