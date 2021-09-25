/*
Canadian Calorie Counting
Canadian Computing Competition: 2006 Stage 1, Junior #1
https://dmoj.ca/problem/ccc06j1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
int burger, side, drink, dessert;
vector<int>burgers = {461, 431, 420, 0};
vector<int>sides = {100, 57, 70, 0};
vector<int>drinks = {130, 160, 118, 0};
vector<int>desserts = {167, 266, 75, 0};
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> burger >> side >> drink >> dessert;
    int sum = burgers[burger-1]+sides[side-1]+drinks[drink-1]+desserts[dessert-1];
    cout << "Your total Calorie count is " << sum << "." << nl;
    return 0;
}