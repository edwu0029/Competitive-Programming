/*
Hydrocarbons
DMOPC '19 Contest 7 P1
https://dmoj.ca/problem/dmopc19c7p1
*/

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
int a, b, c, d;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    int spots = 2*a+4*b+6*c;
    if(4*(a+b+c+1)-spots==d){
        cout << "C" << (a+b+c+1) << "H" << d << nl;
    }else{
        cout << "invalid" << nl;
    }
    return 0;
}