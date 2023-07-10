#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e4 + 5;
int f[maxn], c[maxn], s[maxn];
int n, L;
long double pow(int x, int y){
    return x * x;
}
long double getXY(int j1, int j2){
    long double y = f[j2] - f[j1] + pow(s[j2] + j2 + L + 1, 2) - pow(s[j1] + j1 + L + 1, 2);
    long double x = s[j2] + j2 - s[j1] - j1;
    return y / x;
}
long double getK(int i){
    return 2 * (s[i] + i);
}
int q[maxn];
int front = 1, rear = 1;
signed main(){
    cin >> n >> L;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        s[i] = s[i - 1] + c[i];
    }
    for (int i = 1; i <= n; i++){
        long double k0 = getK(i);
        // cout << "slope:" << getXY(q[front], q[front + 1]) << "; k0:" << k0 << endl;
        while (front < rear && getXY(q[front], q[front + 1]) <= k0) front++;
        int j = q[front];
        // cout << i << ' ' << j << endl;
        f[i] = f[j] + pow(s[i] - s[j] + i - j - 1 - L, 2);
        while (front < rear && getXY(q[rear - 1], q[rear]) > getXY(q[rear], i)) rear--;
        q[++rear] = i;
        // cout << "front:" << front << "; rear:" << rear << endl;
        // cout << "f:" << f[i] << endl;
        // cout << endl;
    }
    cout << f[n];
    return 0;
}