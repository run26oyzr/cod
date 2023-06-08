#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int q = atoi(argv[2]);
    int t = atoi(argv[3]);
    int n = atoi(argv[4]);

    printf("%d %d\n", N, q);
    for (int i = 1; i <= N; i++){
        printf("%d ", rnd.next(1, (int)(10)));
    }
    printf("\n");

    vector<int> p(n);
    //给 1..n-1 号点设置父亲
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, t);
    //打乱节点排序
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());
    // 随机加边
    vector<pair<int,int> > edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    vector<int> nodes;
    int pos = n - 1;
    int len = (N - n) / n;
    // printf("len: %d %d\n", len,  N  - len * (n - 1) - n);
    for (int i = 0; i < n; i++){
        int now = i;
        if (i != n - 1){
            for (int j = 1; j <= len; j++){
                nodes.push_back(++pos);
            }
            shuffle(nodes.begin(), nodes.end());
            for (int j = 0; j < len; j++){
                // printf("debug: %d %d\n", now + 1, nodes[j] + 1);
                edges.push_back(make_pair(now, nodes[j]));
                now = nodes[j];
            }
            nodes.clear();
        }else{
            for (int j = 1; j <= N - len * (n - 1) - n; j++){
                nodes.push_back(++pos);
            }
            shuffle(nodes.begin(), nodes.end());
            for (int j = 0; j < N - len * (n - 1) - n; j++){
                // printf("debug: %d %d\n", now + 1, nodes[j] + 1);
                edges.push_back(make_pair(now, nodes[j]));
                now = nodes[j];
            }
            nodes.clear();
        }
    }

    //打乱边的顺序
    shuffle(edges.begin(), edges.end());
    for (int i = 0; i + 1 < N; i++){
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
    }

    int opt, a, b, k;
    for (int i = 1; i <= q; i++){
        opt = rnd.next(1, 3);
        a = rnd.next(1, N), b = rnd.next(1, N);
        if (opt == 1){
            k = rnd.next(1, (int)(10));
            printf("%d %d %d %d", opt, a, b, k);
        }else{
            printf("%d %d %d", opt, a, b);
        }
        if (i + 1 <= q) printf("\n");
    }
    
    return 0;
}
