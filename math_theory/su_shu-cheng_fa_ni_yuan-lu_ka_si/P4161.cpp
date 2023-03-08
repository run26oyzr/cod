#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e3 + 5;
bool isp[maxn];
int prim[maxn];
int dp[maxn];
signed main(){
	/**
	 * 这里的数字表示长度为Ai的区间循环Ai次后值又回到了1,2,3.....,Ai 
	 * 2 3 1 1 1 1 1
	 * 2 6 1 1
	 * 这里的6是没有用的，因为lcm(2,3)=6
	 * 所以，题意转化为lcm为 P1^k1 * P2^k2 * P3^k3 ...... * Pn^kn，求出所有可能性 
	 * 显然，需要使用dp
	 * （长度：P1*k1 + P2*k2 + P3*k3 ...... + Pn*kn） 
	 * dp[i][j]:枚举到第i个质数，长度为n的时候，所有的方案和 
     * (i可以使用滚动数字优化掉)
	*/
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!isp[i]) prim[++cnt] = i;
        for (int j = 1; j <= cnt && prim[j] * i <= 1000; j++){
            isp[prim[j] * i] = 1;
            if (i % prim[j] == 0) break;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= cnt; i++){
        for (int j = n; j >= prim[i]; j--){
            for (int k = prim[i]; k <= j; k *= prim[i]){
                dp[j] += dp[j - k];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++){
        ans += dp[i];
    }
    cout << ans;
	return 0;
}