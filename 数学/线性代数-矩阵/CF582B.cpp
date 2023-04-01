/**
 * 不降子序列一定能在 n 个循环节之内达到最大值
 * 在 1~n 中选出出现最多的数，循环部分为 cnt * (T - m) 次
 * 循环前/后分别求出以循环部分为结尾/开头的不降子序列长度 
*/
#include <bits/stdc++.h>
using namespace std;
int a[105];
int cnt[305];
int f[105][105];
int main(){
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int maxnum = 0, maxval = 0;
    for (int i = 1; i <= 300; i++){
        if (cnt[i] >= maxval){
            maxval = cnt[i];
            maxnum = i;
        }
    }
    int l, tmp = 1;
    int nowmax = 0;
    for (l = 1; l < n; l++){
        bool flag = false;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i < j && l != 1){
                    if (a[i] >= a[j]) f[l][i] = max(f[l][i], f[l - 1][j] + 1);
                }
                else if (i > j){
                    if (a[i] >= a[j]) f[l][i] = max(f[l][i], f[l][j] + 1);
                }
            }
            nowmax = max(nowmax, f[l][i]);
            // cout << f[l][i] << ' ';
        }
        // cout << endl;
        if (l == T){
            cout << nowmax + 1;
            return 0;
        }
        if (flag) break;
        tmp = max(tmp, nowmax + maxval * (n - l) + 1);
        if (nowmax == n - 1) break;
        // cout << nowmax << ' ' << tmp << endl;
    }
    // tmp += maxval * (n - l);
    // cout << maxnum << endl;
    // cout << l << endl;
    cout << tmp + maxval * (T - n);
    return 0;
}