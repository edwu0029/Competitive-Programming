/*
Tiles
DMOPC '14 Contest 1 P2
https://dmoj.ca/problem/dmopc14c1p2
*/

#include <bits/stdc++.h>
using namespace std;
int R, C, F;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> R >> C >> F;
    cout << ((int)(R/F))*((int)(C/F)) << endl;
}