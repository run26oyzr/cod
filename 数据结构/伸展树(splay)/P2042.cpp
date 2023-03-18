#include <bits/stdc++.h>
using namespace std;
#define ls t[id].ch[0]
#define rs t[id].ch[1]

int max(int x, int y, int z){
    return max(x, max(y, z));
}

const int maxn = 2 * 1e5;
struct Node{
    int val, size, ch[2];
    int rev;
    int rnd;
    int la, flag;
    int sum, lsum, rsum, maxs;
}t[maxn << 1];

int tot = 0, rt = 0;
int st[maxn], tp = 0;
int a[maxn];

int newNode(int val, int _rnd = 0){
    int id;
    if (tp) id = st[tp--];
    else id = ++tot;
    t[id].val = val;
    t[id].size = 1;
    t[id].ch[0] = t[id].ch[1] = 0;
    t[id].rev = t[id].flag = 0;
    t[id].sum = t[id].maxs = val;
    t[id].lsum = t[id].rsum = val;
    return id;
}

/*
    int buildtree(int L, int R){ //无rand 准备按秩合并
        if (L > R) return 0;
        if (L == R) return newNode(a[L]);
        int mid = (L + R) >> 1;
        int id = newNode(a[mid]);
        t[id].ch[0] = buildtree(L, mid - 1);
        t[id].ch[1] = buildtree(mid + 1, R);
        return id;
    }
*/
int buildtree(int L, int R, int rnd = 0){
    if (L > R) return 0;
    if (L == R) return newNode(a[L], rnd);
    int mid = (L + R) >> 1;
    int id = newNode(a[mid]);
    t[id].ch[0] = buildtree(L, mid - 1, rnd + rand() + 1);
    t[id].ch[1] = buildtree(mid + 1, R, rnd + rand() + 1);
    return id;
}

void update(int id){
    t[id].size = t[ls].size + t[rs].size + 1;
    //la
    t[id].sum = t[ls].sum + t[rs].sum + t[id].val;
    t[id].lsum = max(t[ls].lsum, t[ls].sum + t[id].val, t[ls].sum + t[id].val + t[rs].lsum);
    t[id].rsum = max(t[rs].rsum, t[rs].sum + t[id].val, t[rs].sum + t[id].val + t[ls].rsum);

    t[id].maxs = t[id].val;
    if (ls) t[id].maxs = max(t[id].maxs, t[ls].maxs, t[ls].rsum + t[id].val);
    if (rs) t[id].maxs = max(t[id].maxs, t[rs].maxs, t[rs].lsum + t[id].val);
    if (ls && rs) t[id].maxs = max(t[id].maxs, t[ls].rsum + t[id].val + t[rs].lsum);
}

void reverse(int id){
    t[id].rev ^= 1;
    swap(ls, rs); 
    swap(t[id].lsum, t[id].rsum);
}
void setLa(int id, int la){
    t[id].la = la; t[id].flag = 1;
    t[id].val = la;
    t[id].sum = t[id].size * t[id].val;
    t[id].maxs = max(t[id].val, t[id].sum);
    t[id].lsum = t[id].rsum = t[id].maxs;
}
void pushdown(int id){ //lazy 修改时直接修改对id的影响
    if (t[id].rev){
        if (ls) reverse(ls);
        if (rs) reverse(rs);
        t[id].rev = 0;   
    }
    if (t[id].flag){ //或if (t[id].la != -INF)
        if (ls) setLa(ls, t[id].la);
        if (rs) setLa(rs, t[id].la);
        t[id].flag = 0; t[id].la = -1e9; //-INF
    }
}

void split(int id, int val, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    pushdown(id);
    if (t[id].val <= val)
        x = id, split(t[id].ch[1], val, t[id].ch[1], y);
    else
        y = id, split(t[id].ch[0], val, x, t[id].ch[0]);
    update(id);
}

int merge(int x, int y){
    if (!x || !y) return x + y;
    if (t[x].rnd < t[y].rnd){
        pushdown(x);
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    else{
        pushdown(y);
        t[y].ch[0] = merge(t[y].ch[0], x);
        update(y);
        return y;
    }
}

void reback(int id){
    if (!id) return;
    st[++tp] = id;
    reback(ls);
    reback(rs);
}

int merge(int x, int y, int z){
    return merge(x, merge(y, z));
}


int x, y, z;
void insert(int pos, int num){
    split(rt, pos - 1, x, z);
    // y = buildtree(1, num);
    // rt = merge(x, y, z);
    for (int i = 1; i <= num; i++){
        rt = merge(x, newNode(a[i]));
    }
    rt = merge(x, z);
}
void del(int pos, int num){
    split(rt, pos - 1, x, y);
    split(y, tot, y, z);
    reback(y); //内存回收 dfs
    rt = merge(x, z);
}
void make_same(int pos, int num, int la){
    split(rt, pos - 1, x, y);
    split(y, tot, y, z);
    setLa(y, la);
    rt = merge(x, y, z);
}
void rev(int pos, int num){
    split(rt, pos - 1, x, y);
    split(y, tot, y, z);
    reverse(y);
    rt = merge(x, y, z);
}
void get_sum(int pos, int num){
    split(rt, pos - 1, x, y);
    split(y, tot, y, z);
    cout << t[y].sum << endl;
    rt = merge(x, y, z);
}
void get_max_sum(){
    cout << t[rt].maxs << endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    insert(0, n);
    // rt = buildtree(1, n);
    int pos, num, la;
    string s;
    while(m--){
        cin >> s;
        if (s == "INSERT"){
            cin >> pos >> num;
            for (int i = 1; i <= num; i++) cin >> a[i];
            insert(pos, num);
        }
        if (s == "DELETE"){
            cin >> pos >> num;
            del(pos, num);
        }
        if (s == "MAKE-SAME"){
            cin >> pos >> num >> la;
            make_same(pos, num, la);
        }
        if (s == "REVERSE"){
            cin >> pos >> num;
            rev(pos, num);
        }
        if (s == "GET-SUM"){
            cin >> pos >> num;
            get_sum(pos, num);
        }
        if (s == "MAX-SUM") get_max_sum();
    }
    system("pause");
}