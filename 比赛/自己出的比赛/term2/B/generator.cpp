#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int q = atoi(argv[2]);   

    printf("%d %d\n", n, q);
    for(int i = 1; i <= n; i++) printf("%d ", rnd.next(1, (int)(1e9)));
    printf("\n");
    while(q--){
        int opt = rnd.next(1, 2);
        int a = rnd.next(1, n), b = rnd.next(1, n);
        if(a > b) swap(a, b);
        int val = rnd.next(1, (int)(1e9));
        if(opt == 1){
            printf("%d %d %d %d\n", opt, a, b, val);
        }else{
            printf("%d %d %d\n", opt, a, b);
        }
    }

    return 0;
}
