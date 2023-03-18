#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e5 + 5;
int n, m;

//图：邻接表存
struct Node{
    int v, c, next;
}t[maxm << 2];
int tot = 0, h[maxn];
void addEdge(int u, int v, int c){
    t[++tot].v = v;
    t[tot].c = c;
    t[tot].next = h[u];
    h[u] = tot;
    in[v] ++;
}

int q[maxn];//topo候选队列
int in[maxn];//addEdge时统计所有点的入度; u -> v : c, in[v]++;
void topo(){
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) q[++rear] = i;
    }
    while(front <= rear){
        int u = q[front++];
        for (int i = h[u]; i; i = t[i].next){
            in[t[i].v] --;
            if (in[t[i].v] == 0)
                q[++rear] = t[i].v;
        }
    }
}

int main(){

    return 0;
}