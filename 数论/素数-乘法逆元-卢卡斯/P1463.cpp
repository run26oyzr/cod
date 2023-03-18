#include <bits/stdc++.h>
#define int long long
using namespace std;
int prim[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
int maxx = 0, maxn = 0;
void dfs(int step, int ans, int nown, int prek){
	int maxnum = min(prek, (long long)(pow(n, (1.0 / prim[step]))));
	if (maxnum == 0 || step == 10){
		if (ans > maxx){
			maxx = ans;
			maxn = nown;
		}
		else if (ans == maxx && nown < maxn) maxn = nown;
		return;
	}
	for (int i = 0; i <= maxnum; i++){
		if (nown * pow(prim[step], i) > n) continue;
		dfs(step + 1, ans * (i + 1), nown * pow(prim[step], i), i);
	}
}
signed main(){
    /**
     * 将x表示为 P1^k1 * P2^k2 * P3^k3 * ...... * Pn^kn的形式（P1<P2<P3<......<Pn, k1>=k2>=k3>-......>=k4)
     * 若交换任意的ki与ki+1, 则得到的y必大于x
     * 对于y来说，有x<y且g(y)=g(x), 所以y一定不是反质数
     * 综上，只需要暴力dfs每一个素数对应的指数即可
     * 
    */
	cin >> n;
	dfs(0, 1, 1, 100);
	cout << maxn;
	return 0;
}