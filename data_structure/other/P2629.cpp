#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int q[maxn], front = 1, rear = 0;
int a[maxn << 1];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n + 1; i < 2 * n; i++) a[i] = a[i - n];
    
    return 0;
}