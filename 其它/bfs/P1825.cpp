#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e2 + 5;
struct node{
	int x, y;
	int step;
};
queue<node> q;
int a, b, n, m;
int vis[maxn][maxn], t[2][26][2];
char s[maxn][maxn];
int pos[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
void bfs(){
	node now, nt;
	int nx, ny;
	now.x = a; now.y = b; now.step = 0;
	q.push(now);
	vis[a][b] = 1;
	while (!q.empty()){
		now = q.front(); 
		q.pop(); 
		if (s[now.x][now.y] == '='){
			cout << now.step << endl;
			return;
		}
		for (int i = 0; i < 4; i++){
			nx = now.x + pos[i][0];
			ny = now.y + pos[i][1];
			char e = s[nx][ny];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (e == '#') continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			if (e >= 'A' && e <= 'Z'){
				if (nx == t[0][e - 'A'][0] && ny == t[0][e - 'A'][1]){
					nx = t[1][e - 'A'][0];
					ny = t[1][e - 'A'][1];
				}
				else{
					nx = t[0][e - 'A'][0];
					ny = t[0][e - 'A'][1];
				}
			}
			nt.x = nx; nt.y = ny; nt.step = now.step + 1;
			q.push(nt);
		}
	}
	return;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 26; j++){
			for (int k = 0; k < 2; k++){
				t[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		scanf("\n");
		for (int j = 1; j <= m; j++){
			scanf("%c", &s[i][j]);
			if (s[i][j] == '@'){
				a = i;
				b = j;
			}
			if (s[i][j] <= 'Z' && s[i][j] >= 'A'){
				if (t[0][s[i][j] - 'A'][1] == 0){
					t[0][s[i][j] - 'A'][0] = i;
					t[0][s[i][j] - 'A'][1] = j;
				}
				else{
					t[1][s[i][j] - 'A'][0] = i;
					t[1][s[i][j] - 'A'][1] = j;
				}
			}
		} 
	}
	bfs();
	return 0;
}
