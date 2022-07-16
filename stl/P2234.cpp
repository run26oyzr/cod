#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id, val;
    bool operator < (const Node T)const{
        // cout << "T.val=" << T.val << "; val=" << val << endl;
        if(val == T.val) reuturn id < T.id;
        return val < T.val;
    }
};
set <Node> s;
set <Node>::iterator it;
int main(){
    int t;
    cin >> t;
    Node n;
    int val;
    int ans;
    int res = 0;
    cin >> val;
    res += val;
    n.val = val;
    n.id = 1;
    s.insert(n);
    t--;
    for(int j = 2; j <= t; j++){
        int delta = 1e9 + 5;
        cin >> val;
        n.id = j;
        n.val = val;
        s.insert(n);
        it = s.lower_bound(n);
        if(it != s.begin()){
            it--;
            // cout << "lower " << (*it).val << endl;
            if (delta > n.val - (*it).val){
                delta = n.val - (*it).val;
                ans = delta;
            }
        }
        it = s.upper_bound(n);
        if(it != s.end()){
            if ((*--it).val == val &&(*it).id != j){
                continue;
            }
            else it++;
            // cout << "upper " << (*it).val << endl;
            if (delta > (*it).val - n.val){
                delta = (*it).val - n.val;
                ans = delta;
            }
        }
        for(it = s.begin();it!=s.end();it++){
            // cout << "id=" << (*it).id <<"; val = " << (*it).val << endl; 
        }
        cout << " ------------------------------------------ans="<< ans << endl;
        res += ans;
    }
    cout << res;
    system("Pause");
    return 0;
}