#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id, val;
    bool operator < (const Node T)const{
        // cout << "T.val=" << T.val << "; val=" << val << endl;
        return T.val > val;
    }
};
set <Node> s;
set <Node>::iterator it;
int main(){
    int t;
    cin >> t;
    Node n;
    n.val = 1000000000;
    n.id = 1;
    s.insert(n);
    int id, val;
    int ans;
    while(t--){
        int delta = 1e9 + 5;
        cin >> id >> val;
        n.id = id;
        n.val = val;
        s.insert(n);
        it = s.lower_bound(n);
        if(it != s.begin()){
            it--;
            // cout << "lower " << (*it).val << endl;
            if (delta > n.val - (*it).val){
                delta = n.val - (*it).val;
                ans = (*it).id;
            }
        }
        it = s.upper_bound(n);
        if(it != s.end()){
            // cout << "upper " << (*it).val << endl;
            if (delta > (*it).val - n.val){
                delta = (*it).val - n.val;
                ans = (*it).id;
            }
        }
        for(it = s.begin();it!=s.end();it++){
            cout << "id=" << (*it).id <<"; val = " << (*it).val << endl; 
        }
        cout << id << ' ' << ans << endl;
    }
    // system("Pause");
    return 0;
}