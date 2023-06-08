#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int rnd(int l, int r){
    return mt_rand() % (r - l + 1) + l;
}
string exepos = "D:\\app\\exe\\";
string nowpos = "D:\\0_OI\\own_contest\\term2\\B\\check\\";
int main(){
    for (int i = 1; i <= 3; i++){
        system((exepos + "std.exe < " + nowpos + to_string(i) + ".in" + " > " + nowpos + to_string(i) + ".out").c_str());
        if (system(("fc " + nowpos + to_string(i) + ".out " + nowpos + to_string(i) + ".ans").c_str())){
            cout << "error";
        }
    }
    return 0;
}