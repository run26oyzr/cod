#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int rnd(int l, int r){
    return mt_rand() % (r - l + 1) + l;
}
string exepos = "D:\\app\\exe\\";
string nowpos = "D:\\0_OI\\own_contest\\term2\\D\\data\\";
int main(){
    for (int i = 1; i <= 20; i++){
        if (i <= 4){
            system((exepos + "generator.exe " + to_string(rnd(4 * 1e4 - 100, 4 * 1e4)) + " " + to_string(rnd(3 * 1e4 - 100, 3 * 1e4)) + " 0 1 > " + nowpos + to_string(i) + ".in").c_str());
        }else if(i > 20){
            if(i == 21) system((exepos + "generator.exe " + to_string(rnd(4 * 1e4 - 100, 4 * 1e4)) + " " + to_string(rnd(3 * 1e4 - 100, 3 * 1e4)) + " 0 1 > " + nowpos + to_string(i) + ".in").c_str());
            if(i == 22) system((exepos + "generator.exe " + to_string(rnd(1e5 - 100, 1e5)) + " " + to_string(rnd(3 * 1e4 - 100, 3 * 1e4)) + " 0 " + to_string(rnd(5, 15)) + " > " + nowpos + to_string(i) + ".in").c_str());
        }else{
            system((exepos + "generator.exe " + to_string(rnd(1e5 - 100, 1e5)) + " " + to_string(rnd(3 * 1e4 - 100, 3 * 1e4)) + " 0 " + to_string(rnd(5, 15)) + " > " + nowpos + to_string(i) + ".in").c_str());
        }
        system((exepos + "std.exe < " + nowpos + to_string(i) + ".in" + " > " + nowpos + to_string(i) + ".ans").c_str());
    }
    return 0;
}