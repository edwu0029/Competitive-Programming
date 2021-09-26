/*
Grumpy Dwarf
DMOPC '15 Contest 2 P1
https://dmoj.ca/problem/dmopc15c2p1
*/

#include <bits/stdc++.h>
using namespace std;
int bars, sword, K, sum, extrabars;
int main(){
    scanf("%d%d",&bars,&K);
    while(bars>0){
        bars--; sword++; sum++;
        if(sword==K){
            sword-=K; bars++;
        }
    }
    cout << sum << '\n';
}