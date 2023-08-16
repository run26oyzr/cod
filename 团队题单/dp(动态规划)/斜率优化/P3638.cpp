#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int f[maxn];
int x[maxn], s[maxn];
int a, b, c;
int X(int x){
    return s[x];
}
int Y(int x){
    return f[x] + a * s[x] * s[x] - b * s[x];
}
long double getK(int j1, int j2){
    return 1.0 * (Y(j2) - Y(j1)) / (X(j2) - X(j1));
}
int getK0(int i){
    return 2 * a * s[i];
}
signed q[maxn];
int front = 1, rear = 1;
signed main(){
    int n;
    cin >> n;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        s[i] = s[i - 1] + x[i];
    }
    for (int i = 1; i <= n; i++){
        int k0 = getK0(i);
        while (front < rear && getK(q[front], q[front + 1]) >= k0) front++;
        int j = q[front];
        // cout << i << ' ' << j << endl;
        f[i] = f[j] + a * (s[i] - s[j]) * (s[i] - s[j]) + b * (s[i] - s[j]) + c;
        while (front < rear && getK(q[rear - 1], q[rear]) <= getK(q[rear], i)) rear--;
        q[++rear] = i;
    }
    cout << f[n];
    return 0;
}