#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
int a[maxn];
signed main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt2 = 0, cnt3 = 0, cnt4 = 0;
	while(m % 4 == 0){
		m /= 4;
		cnt4++;
	}
	while(m % 3 == 0){
		m /= 3;
		cnt3++;
	}
	while(m % 2 == 0){
		m /= 2;
		cnt2++;
	}
	if (m > 1){
		cout << -1;
		return 0;
	}
	if (cnt4 + cnt3 + cnt2 > n){
		cout << -1;
		return 0;
	} 
	sort(a + 1, a + n + 1);
	int tmp1 = 0;
	for (int i = 1; i <= n; i++)
		tmp1 += a[i];
	int cnt4_ = cnt4, cnt2_ = cnt2;
	int tot = 1e18;
	for (int cnt = 0; cnt <= cnt4_; cnt++){
		cnt4 = cnt;
		cnt2 = cnt2_ + (cnt4_ - cnt) * 2;
		if (cnt4 + cnt2 + cnt3 > n) continue;
		int tmp2 = 0;
		for (int i = 1; i <= cnt4; i++)
			tmp2 += 3 * a[i];
		for (int i = cnt4 + 1; i <= cnt4 + cnt3; i++)
			tmp2 += 2 * a[i];
		for (int i = cnt4 + cnt3 + 1; i <= cnt4 + cnt3 + cnt2; i++)
			tmp2 += 1 * a[i];
		tot = min(tot, tmp2);
	}
	int ans = tmp1 + tot;
	cout << ans;
	return 0;
}
//2*2=2+2,优先考虑b_i为4 
//把4换成2个2，ans更小了？？？ 
//2^60>10^18,暴力枚举2和4的分布 
//30*2000<1e8