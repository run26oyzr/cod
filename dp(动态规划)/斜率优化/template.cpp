#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int f[maxn];
int X(int x){

}
int Y(int x){

}
long double getK(int j1, int j2){
    return 1.0 * (Y(j2) - Y(j1)) / (X(j2) - X(j1));
}
int getK0(int i){

}
signed q[maxn];
int front = 1, rear = 1;
signed ans[205][maxn];
signed main(){
    int n;
    for (int i = 1; i <= n; i++){
        int k0 = getK0(i);
        while (front < rear && getK(q[front], q[front + 1]) >= k0) front++;
        int j = q[front];
        f[i] = ;
        while (front < rear && getK(q[rear - 1], q[rear]) <= getK(q[rear], i)) rear--;
        q[++rear] = i;
    }
    return 0;
}