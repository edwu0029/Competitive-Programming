//Problem: https://dmoj.ca/problem/dmopc19c7p0

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
double A, B, C, D;
double tmp = 0;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B >> C >> D;
    tmp = (double)(A+B)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+C)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+D)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(B+C)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(B+D)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(C+D)/2.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+B+C)/3.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+B+D)/3.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+C+D)/3.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(B+C+D)/3.0;
    cout << fixed << setprecision(6) << tmp << nl;
    tmp = (double)(A+B+C+D)/4.0;
    cout << fixed << setprecision(6) << tmp << nl;
    return 0;
}
