#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e4 + 5;
struct Node{
    int x, y;
    bool operator < (const Node T) const{
        if (x == T.x) return y < T.y;
        return x < T.x;
    }
}t[maxn];
int f[maxn];
int X(int x){
    return t[x + 1].y;
}
int Y(int x){
    return f[x];
}
long double getK(int j1, int j2){
    // if (j1 == 0) return 1e19;
    return 1.0 * (Y(j2) - Y(j1)) / (X(j2) - X(j1));
}
int getK0(int i){
    return -t[i].x;
}
signed q[maxn];
int front = 1, rear = 1;
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i].x >> t[i].y;
    }
    sort(t + 1, t + n + 1);
    int pos = 1;
    for (int i = 1; i <= n; i++){
        while (pos && t[pos].y <= t[i].y) pos--;
        t[++pos] = t[i];
    }
    // for (int i = 1; i <= pos; i++) cout << t[i].x << ' ' << t[i].y << endl;
    // cout << endl;
    for (int i = 1; i <= pos; i++){
        int k0 = getK0(i);
        while (front < rear && getK(q[front], q[front + 1]) >= k0) front++;
        int j = q[front];
        // cout << i << ' ' << j << endl;
        f[i] = f[j] + t[i].x * t[j + 1].y;
        while (front < rear && getK(q[rear - 1], q[rear]) < getK(q[rear], i)) rear--;
        q[++rear] = i;
        // cout << "front:" << front << "; rear:" << rear << endl;
        // cout << f[i] << endl;
        // for (int i = front; i <= rear; i++) cout << q[i] << ' ';
        // cout << endl;
        // cout << endl;
    }
    cout << f[pos] << endl;
    return 0;
}