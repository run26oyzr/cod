#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int rnd(int l, int r){
    return mt_rand() % (r - l + 1) + l;
}
string exepos = "D:\\app\\exe\\";
string nowpos = "D:\\0_OI\\own_contest\\term2\\B\\data\\";
int main(){
    for (int i = 1; i <= 22; i++){
        if (i <= 10){
            system((exepos + "generator.exe " + to_string(rnd(5 * 1e3 - 100, 5 * 1e3)) + " " + to_string(rnd(5 * 1e3 - 100, 5 * 1e3)) + " > " + nowpos + to_string(i) + ".in").c_str());
        }else if(i > 20){
            if(i == 21) system((exepos + "generator.exe " + to_string(rnd(5 * 1e3 - 100, 5 * 1e3)) + " " + to_string(rnd(5 * 1e3 - 100, 5 * 1e3)) + " > " + nowpos + to_string(i) + ".in").c_str());
            if(i == 22) system((exepos + "generator.exe " + to_string(rnd(1e5 - 100, 1e5)) + " " + to_string(rnd(5 * 1e5 - 100, 5 * 1e5)) + " > " + nowpos + to_string(i) + ".in").c_str());
        }else{
            system((exepos + "generator.exe " + to_string(rnd(1e5 - 100, 1e5)) + " " + to_string(rnd(5 * 1e5 - 100, 5 * 1e5)) + " > " + nowpos + to_string(i) + ".in").c_str());
        }
        system((exepos + "std.exe < " + nowpos + to_string(i) + ".in" + " > " + nowpos + to_string(i) + ".ans").c_str());
    }
    return 0;
}