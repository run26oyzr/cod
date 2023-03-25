/**
 * 因为 n>m，所以 (n!)/(m!) 必为整数
 * 将 m 进行质因数分解，使得 m = p1^k1 * p2^k2 * ...... px^kx
 * ans = phi(m!) * (n!) / (m!) (mod R)
 *     = m! * (1 - 1/p1) * (1 - 1/p2) * ...... * (1 - 1/px) * (n!) / (m!) (mod R)
 *     = n! * (1 - 1/p1) * (1 - 1/p2) * ...... * (1 - 1/px) (mod R)
 * 预处理 n! mod R
 * 筛出 1~m 的所有质数并求出它们的逆元，即可算出 (p1-1/p1) * (p2-1/p2) * ...... * (px-1/px)
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
#define int long long
int Mod;
int prim[maxn], cnt;
bool isp[maxn];
int inv[maxn];
int jie_cheng[maxn];
int phi_cheng[maxn], phi_[maxn];
void find_prime(){
	for (int i = 2; i <= 1e7; i++){
		if (!isp[i]) prim[++cnt] = i;
		for (int j = 1; j <= cnt && i * prim[j] <= 1e7; j++){
			isp[i * prim[j]] = 1;
			if (i % prim[j] == 0) break;
		}
	}
}
void find_inv(){
	inv[1] = 1;
	for (int i = 2; i <= 1e7; i++){
		inv[i] = (((-Mod/i) * inv[Mod % i] % Mod) + Mod) % Mod; 
	}
}
void get_jie_cheng(){
	jie_cheng[1] = 1;
	for (int i = 2; i <= 1e7; i++){
		if (i == Mod) jie_cheng[i] = jie_cheng[i - 1];
		else jie_cheng[i] = (jie_cheng[i - 1] % Mod) * i % Mod;
	}
}
void get_phi(){
	phi_cheng[0] = 1;
	for (int i = 1; i <= cnt; i++){
		if (prim[i] == Mod) phi_cheng[i] = phi_cheng[i - 1] * (prim[i] - 1);
		else phi_cheng[i] = (phi_cheng[i - 1] * (prim[i] - 1) % Mod) * inv[prim[i]] % Mod;
		for (int j = prim[i]; j <= prim[i + 1] - 1; j++) phi_[j] =  phi_cheng[i];
	}
	phi_[1] = 1;
}
signed main(){
	int T;
	scanf("%lld %lld", &T, &Mod);
	find_prime();
	find_inv();
	get_jie_cheng();
	get_phi();
	while(T--){
		int n, m;
		scanf("%lld %lld", &n, &m);
		if (n >= Mod && m < Mod){
			printf("0\n");
			continue;
		}
		int ans = 1;
		ans = ans * jie_cheng[n] % Mod;
		ans = ans * phi_[m] % Mod;
		printf("%lld\n", (ans + Mod) % Mod);
	}
	return 0;
}