#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
	int color, t;
};
Node hang[maxn], lie[maxn];
int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m, q;
		scanf("%d %d %d", &n, &m, &q);
		int opt, id, val;
		for (int i = 1; i <= q; i++){
			scanf("%d %d %d", &opt, &id, &val);
			if (opt == 0){
				hang[id].color = val;
				hang[id].t = i;
			}
			if (opt == 1){
				lie[id].color = val;
				lie[id].t = i;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				//printf("%d %d\n", hang[i].t, lie[j].t);
				printf("%d ", (hang[i].t > lie[j].t)?hang[i].color:lie[j].color);
			}
			printf("\n");
		}
		for (int i = 1; i <= n; i++) hang[i].color = 0, hang[i].t = 0;
		for (int j = 1; j <= m; j++) lie[j].color = 0, lie[j].t = 0;
	}
	return 0;
}
