//Problem: https://dmoj.ca/problem/dwite08c3p3

#include <bits/stdc++.h>
using namespace std;
double F[5][5] = {{1,0.2,0.05,0.025,0.00625},
                 {5,1,0.25,0.125,0.03125,},
                 {20,4,1,0.5,0.125},
                 {40,8,2,1,0.25},
                 {160,32,8,4,1}};
int N, con1, con2;
string s, tmp, s2;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0;i<5;i++){
        cin >> N >> s >> tmp >> s2;
        if(s=="oz"){
            con1=0;
        }else if(s=="gill"){
            con1=1;
        }else if(s=="pt"){
            con1=2;
        }else if(s=="qt"){
            con1=3;
        }else if(s=="gal"){
            con1=4;
        }

        if(s2=="oz"){
            con2=0;
        }else if(s2=="gill"){
            con2=1;
        }else if(s2=="pt"){
            con2=2;
        }else if(s2=="qt"){
            con2=3;
        }else if(s2=="gal"){
            con2=4;
        }
        cout << N*F[con1][con2] << '\n';
    }
}