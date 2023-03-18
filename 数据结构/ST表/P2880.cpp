#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int minx[MAXN][20], maxx[MAXN][20];
int log_[MAXN];
int n, m;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void init()
{
    cin >> n >> m;
	for (int i = 2; i < MAXN; i++) log_[i] = log_[i >> 1] + 1;
	for (int i = 1; i <= n; i++) minx[i][0] = read();
	for (int i = 1; i <= n; i++) maxx[i][0] = minx[i][0];
	for (int k = 1; (1 << k) <= n; k++){
		for (int i = 1; i <= n - (1 << k) + 1; i++){
			minx[i][k] = min(minx[i][k - 1], minx[i + (1 << (k - 1))][k - 1]);
            maxx[i][k] = max(maxx[i][k - 1], maxx[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int query(int L, int R)
{
	int k = floor(log_[R - L + 1]);
	return max(maxx[L][k], maxx[R - (1 << k) + 1][k]) - min(minx[L][k], minx[R - (1 << k) + 1][k]);
}
int main(){
    init();
    int l, r;
    while(m--){
        l = read(); r = read();
        printf("%d\n", query(l, r));
    }
}