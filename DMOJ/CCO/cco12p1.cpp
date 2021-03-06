/*
Choose Your Own Arithmetic
Canadian Computing Olympiad: 2012 Day 1, Problem 1
https://dmoj.ca/problem/cco12p1
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
// #define sp ' '
// #define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e4+5, LOG = 16;
int W, D, V, buttons[10];
bool check[6][5000001];
set<int>f;
void rec(int curval, int cnt){
    if(cnt==W){
        f.insert(curval);
        return;
    }
    if(!check[cnt][curval]){
        check[cnt][curval]=true;
    }else return;
    for(int i = 0;i<D;i++){
        rec(curval+buttons[i], cnt+1);
        rec(curval*buttons[i], cnt+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> W >> D;
    for(int i = 0;i<D;i++) cin >> buttons[i];
    for(int i = 0;i<D;i++) rec(buttons[i], 0);
    cin >> V;
    for(int i = 0;i<V;i++){
        int tmp; cin >> tmp;
        if(f.count(tmp)) cout << "Y" << '\n';
        else cout << "N" << '\n';
    }
}