#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 5;
int a[maxn], f[maxn];
stack<int> s;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = n; i >= 1;i--){
        while( !s.empty() && a[s.top()] <= a[i]) s.pop();
        if(!s.empty()) f[i] = s.top();
        else f[i] = 0;
        s.push(i);
    }
    for(int i = 1; i <= n; i++){
        printf("%d ", f[i]);
    }
 return 0;
} 