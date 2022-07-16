#include <iostream>
using namespace std;

struct node{
	int a, b, c, d;
};
const int maxn = 1e4 + 5;
node t[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> t[i].a >> t[i].b >> t[i].c >> t[i].d;
	}
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = n; i >= 1; i--){
		if (t[i].a <= x && t[i].b <= y && t[i].a + t[i].c >= x && t[i].b + t[i].d >= y){
			printf("%d", i);
			return 0;
		} 
	}
	printf("-1");
	return 0;
}
