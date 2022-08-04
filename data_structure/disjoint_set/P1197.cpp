#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5, maxm = 4 * 1e5 + 5;
int cnt = 0;
struct Node{
    int next, val;
}t[maxm];
int h[maxn];
void addedge(int u, int v){
	++cnt;
	t[cnt].val = v; t[cnt].next = h[u]; h[u] = cnt;
}

int main(){

    system("Pause");
    return 0;
}