#include <bits/stdc++.h>
using namespace std;
const int maxn = 30, maxm = 605;
int n, m;

struct Node{
    int v, next;
}t[maxm << 2];
int tot = 0, h[maxn];
int in[maxn], in2[maxn];
void addEdge(int u, int v){
    t[++tot].v = v;
    t[tot].next = h[u];
    h[u] = tot;
    in[v] ++;
}

struct Queue{
    int id, val;
};
Queue q[maxn];
int ans[maxn];
int vis[maxn];
int f[maxn];
int topo(int x){
    memset(ans, 0, sizeof(ans));
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0 && vis[i]) q[++rear].id = i, q[rear].val = 1;
    }
    for (int i = 1; i <= n; i++){
        in2[i] = in[i];
    }
    int ans1 = 0, cnt = 0;
    while(front <= rear){
        int val = q[front].val;
        int u = q[front++].id;
        ans[++cnt] = u;
        for (int i = h[u]; i; i = t[i].next){
            in2[t[i].v] --;
            if (in2[t[i].v] == 0){
                q[++rear].id = t[i].v, q[rear].val = val + 1;
                ans1 = max(ans1, val + 1);
            }
        }
    }
    int res = 0;
    if (cnt < min(n, x)) res = 1;
    else if (ans1 == n) res = 2;
    return res;
}

int main(){
    scanf("%d %d", &n, &m);
    char c1, c2;
    for (int i = 1; i <= m; i++){
        scanf("\n %c < %c", &c1, &c2);
        vis[c1  - 'A' + 1] = vis[c2  - 'A' + 1] = 1;
        addEdge(c1  - 'A' + 1, c2 - 'A' + 1);
        int x = topo(i);
        if (x == 1){
            printf("Inconsistency found after %d relations.", i);
            system("pause");
            return 0;
        }
        else if (x == 2){
            printf("Sorted sequence determined after %d relations: ", i);
            for (int i = 1; i <= n; i++) cout << (char)('A' + ans[i] - 1);
            cout << ".";
            system("pause");
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    system("pause");
    return 0;
}