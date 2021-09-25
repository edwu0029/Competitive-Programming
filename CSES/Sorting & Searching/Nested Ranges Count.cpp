/*
Nested Ranges Count
https://cses.fi/problemset/task/2169/
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
const int MAXN = 2e5+5, MAXS = 4e5+5;
int N, ans[2][MAXN], bit[MAXS];
array<int, 3> ranges[MAXN];
set<int>vals;
map<int, int>cord_com;
void upd(int idx, int val){
    for(int i = idx;i<MAXS;i+=(i&-i)){
        bit[i]+=val;
    }
}
int qry(int idx){
    int res = 0;
    for(int i = idx;i>0;i-=(i&-i)){
        res+=bit[i];
    }
    return res;
}
bool cmp(const array<int, 3> &a, const array<int,3> &b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
        vals.insert(ranges[i][0]);
        vals.insert(ranges[i][1]);
    }
    sort(ranges, ranges+N, cmp);
    int t = 1;
    for(int i:vals) cord_com[i] = t++;
    for(int i = N-1;i>=0;i--){
        int y = cord_com[ranges[i][1]], idx = ranges[i][2];
        ans[0][idx] = qry(y);
        upd(y, 1);
    }
    //Reset BIT
    memset(bit, 0, sizeof(bit));
    for(int i = 0;i<N;i++){
        int y = cord_com[ranges[i][1]], idx = ranges[i][2];
        ans[1][idx] = i-qry(y-1);
        upd(y, 1);
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<N;j++){
            cout << ans[i][j] << sp;
        }
        cout << nl;
    }
    return 0;
}