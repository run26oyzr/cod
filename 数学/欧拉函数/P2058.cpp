#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 5;
int prim[maxn], phi[maxn];
bool isp[maxn];
int main(){
	int cnt = 0;
	int a;
	cin >> a;
	if (a == 1){
		cout << 0;
		return 0;
	}
	phi[1] = 1;
	for (int i = 2; i <= a; i++){
		if (!isp[i]){
			prim[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt && i * prim[j] <= a; j++){
			isp[i * prim[j]] = 1;
			if (i % prim[j] == 0){
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			else phi[i * prim[j]] = phi[i] * phi[prim[j]];
		}
	}
	long long ans = 0;
	for (int i = 2; i < a; i++){
		ans += phi[i];
	}
	ans *= 2;
	ans += 3;
	cout << ans;
	return 0;
}