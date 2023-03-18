#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int d[MAXN][20];
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
	for (int i = 1; i <= n; i++) d[i][0] = read();
	for (int k = 1; (1 << k) <= n; k++){
		for (int i = 1; i <= n - (1 << k) + 1; i++){
			d[i][k] = min(d[i][k - 1], d[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int query(int L, int R)
{
	int k = floor(log_[R - L + 1]);
	return min(d[L][k], d[R - (1 << k) + 1][k]);
}
int main(){
    init();
    int l, r;
    while(m--){
        l = read(); r = read();
        printf("%d ", query(l, r));
    }
}