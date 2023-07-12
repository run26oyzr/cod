#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e4 + 5;
int f[maxn], ff[maxn];
int c[maxn], x[maxn], p[maxn];
int s[maxn], smul[maxn];
int n, k;
int X(int x){
    return s[x];
}
int Y(int x){
    cout << "Y: " << x << ' ' << smul[x] << endl;
    return ff[x] + smul[x];
}
long double getK(int j1, int j2){
    if (j1 == 0) return -1e18;
    if (X(j1) == X(j2)) return -1e18;
    cout << Y(j2) - Y(j1) << ' ' << X(j2) - X(j1) << "-----getK" << endl;
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
        scanf("%lld %lld", &p[i], &x[i + 1]);
        x[i] += x[i - 1];
        s[i] = s[i - 1] + p[i];
        smul[i] = smul[i - 1] + x[i] * p[i];
        cout << x[i] << ' ';
    }
    cout << endl;
    for (int t = 1; t <= 3; t++){
        front = rear = 1;
        memset(q, 0, sizeof(q));
        for (int i = 1; i <= n; i++) ff[i] = f[i];
        for (int i = 1; i <= n; i++){
            int k0 = getK0(i);
            // cout << getK(q[front], q[front + 1]) << ' ' << k0 << endl;
            while (front < rear && getK(q[front], q[front + 1]) <= k0) front++;
            int j = q[front];
            // cout << i << ' ' << j << endl;
            f[i] = ff[j] + x[i] * (s[i] - s[j]) - (smul[i] - smul[j]);
            while (front < rear && getK(q[rear - 1], q[rear]) >= getK(q[rear], i)) rear--;
            q[++rear] = i;
            cout << "front:" << front << "; rear:" << rear << endl;
            // cout << t << ' ' << i << ' ' << f[i] << endl;
            for (int j = front; j <= rear; j++) cout << q[j] << ' ';
            cout << endl;
            cout << endl;
        }
    }
    cout << f[n];
    return 0;
}