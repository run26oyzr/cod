#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int a, b, cnt = 0;
int vis[maxn][maxn];
int pos[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(int x, int y, int step){
	vis[x][y] = 1;
	int num = 0;
	if (x == 1 || x == a + 1 || y == 1 || y == b + 1){
		if (step > 1){
			cnt ++;
			return;
		}
	}
	for (int i = 0; i < 4; i++){
		if (x == 1 && (i == 1 || i == 3)) continue;
		if (y == 1 && (i == 0 || i == 2)) continue;
		int nx = x + pos[i][0];
		int ny = y + pos[i][1];
		if (nx < 1 || ny < 1 || nx > a + 1 || ny > b + 1) continue;
		if (vis[nx][ny]) continue;
		dfs(nx, ny, step + 1);
		vis[nx][ny] = 0;
	}
	return;
}

int main()
{
	scanf("%d %d", &a, &b);
	for (int i = 2; i <= a; i++){
		dfs(i, 1, 1);
		vis[i][1] = 0;
	}
	for (int i = 2; i <= b; i++){
		dfs(1, i, 1);
		vis[1][i] = 0;
	}
	cout << cnt;
	return 0;
}
