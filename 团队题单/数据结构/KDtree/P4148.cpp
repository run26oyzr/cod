#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct KDtree{
	const double alpha = 0.75; //如果rt的一个子树的size大于整体size的alpha倍，那么就重构 
	const static int K = 2; //总共的维数 
	struct Node{
		int pos[K]; //每个点的位置信息（每一维的坐标），从0开始编号
		int val; //每个点的权值
	}p[maxn]; //用来重构 
	struct KDtree_Node{
		Node point;
		int lson, rson; //左右子
		int size, sum; //size用来判断重构，sum是题目需要维护的
		int minpos[K], maxpos[K]; //minpos维护对应区间中第i维(1 <= i <= k)的最小，maxpos维护最大，从0开始编号
	}t[maxn];
	int tot = 0, trash[maxn], tp = 0; //tot为开新点的编号，trash是一个栈，用来回收空间
	int newNode(){
		int a;
		if (!tp)
			a = ++tot; //如果trash为空，则新建节点
		else 
			a = trash[tp--]; //如果trash不为空，就去trash顶
        //初始化t[a]的值
		t[a].lson = t[a].rson = 0;
		t[a].size = 0;
		t[a].point.pos[0] = t[a].point.pos[1] = 0;
		t[a].point.val = 0; 
		return a;
	}
	void update(int id){
		t[id].size = 1 + t[t[id].lson].size + t[t[id].rson].size; //维护size，要包括自己的 1
		t[id].sum = t[id].point.val + t[t[id].lson].sum + t[t[id].rson].sum; //维护sum，要加上自己的val
		for (int i = 0; i < K; i++){
            //维护第 i 维上坐标的最大与最小(即区间)
			t[id].minpos[i] = t[id].maxpos[i] = t[id].point.pos[i];
			if (t[id].lson){
				t[id].minpos[i] = min(t[id].minpos[i], t[t[id].lson].minpos[i]);
				t[id].maxpos[i] = max(t[id].maxpos[i], t[t[id].lson].maxpos[i]);
			}
			if (t[id].rson){
				t[id].minpos[i] = min(t[id].minpos[i], t[t[id].rson].minpos[i]);
				t[id].maxpos[i] = max(t[id].maxpos[i], t[t[id].rson].maxpos[i]);
			}
		} 
	}
	int rebuild(int L, int R, int d){
		if (L > R)
			return 0;
		int mid = (L + R) >> 1;
		nth_element(p + L, p + mid, p + R + 1, [d](Node a, Node b){return a.pos[d] < b.pos[d];}); //按第d维求中位数 
		int id = newNode();
		t[id].point = p[mid]; //id取中位数对应的节点
		t[id].lson = rebuild(L, mid - 1, (d + 1) % K); //递归左子，注意是 mid - 1，同时轮转用来分割的维度
		t[id].rson = rebuild(mid + 1, R, (d + 1) % K); //递归左子，同时轮转用来分割的维度
		update(id); //更新id
		return id;
	}
	int cnt;
	void callback(int id){
		if (!id)
			return;
		trash[++tp] = id; //回收id节点
		p[++cnt] = t[id].point; //将id对应的节点暂时存在p中，待会rebuild用
		callback(t[id].lson); //递归左右子
		callback(t[id].rson);
	}
	int check(int id, int d){
		if (t[t[id].lson].size >= alpha * t[id].size || t[t[id].rson].size >= alpha * t[id].size){ //如果id的子树不平衡
			cnt = 0;
			callback(id);
			id = rebuild(1, cnt, d); //将id的子树rebuild
		}
		return id;
	}
	void insert(int &id, Node p, int d){
		if (!id){ //如果id没有值，就直接新建节点，并且赋值后return
			id = newNode();
			t[id].point = p;
			update(id);
			return; 
		}
		if (t[id].point.pos[0] == p.pos[0] && t[id].point.pos[1] == p.pos[1]) //加的点正好是id，只需要累加id对应节点的val
			t[id].point.val += p.val;
		else if (p.pos[d] <= t[id].point.pos[d]) //加的点在id的左子
			insert(t[id].lson, p, (d + 1) % K);
		else 
			insert(t[id].rson, p, (d + 1) % K) ;
		update(id);
		id = check(id, d);
	}
	int query(int id, int x1, int y1, int x2, int y2){
		if (!id)
			return 0;
		if (t[id].minpos[0] > x2 || t[id].minpos[1] > y2 || t[id].maxpos[0] < x1 || t[id].maxpos[1] < y1) //id对应的区间完全不在查询区间内 
			return 0;
		if (t[id].minpos[0] >= x1 && t[id].minpos[1] >= y1 && t[id].maxpos[0] <= x2 && t[id].maxpos[1] <= y2) //id对应的区间全部在查询区间内 
			return t[id].sum;
		int sum = query(t[id].lson, x1, y1, x2, y2) + query(t[id].rson, x1, y1, x2, y2);
		if (x1 <= t[id].point.pos[0] && t[id].point.pos[0] <= x2 && y1 <= t[id].point.pos[1] && t[id].point.pos[1] <= y2) //id对应的点在查询区间内 
			sum += t[id].point.val; 
		return sum; 
	}
}KDT;
int main(){
	int n;
	cin >> n;
	int last_ans = 0;
	int op = -1, x1, y1, x2, y2, val;
	int rt = 0;
	while (op != 3){
		cin >> op;
		if (op == 1){
			cin >> x1 >> y1 >> val;
			x1 ^= last_ans, y1 ^= last_ans, val ^= last_ans;
			KDT.insert(rt, {{x1, y1}, val}, 0);
		}else if (op == 2){
			cin >> x1 >> y1 >> x2 >> y2;
			x1 ^= last_ans, y1 ^= last_ans, x2 ^= last_ans, y2 ^= last_ans;
			last_ans = KDT.query(rt, x1, y1, x2, y2);
			cout << last_ans << endl; 
		}
	}
	return 0; 
}