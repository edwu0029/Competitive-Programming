/*
Range Xor Query
AtCoder Beginner Contest 185, Problem F
https://atcoder.jp/contests/abc185/tasks/abc185_f
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
const int MAXN = 300005;
struct node{
    int l, r, val;
}seg[4*MAXN];
int N, Q, F[MAXN];
void build_seg(int i, int l, int r){
    seg[i].l = l; seg[i].r = r;
    if(l==r){
        cin >> F[l];
        seg[i].val = F[l];
        return;
    }
    int mid = (l+r)/2;
    build_seg(2*i, l, mid);
    build_seg(2*i+1, mid+1, r);
    seg[i].val = seg[2*i].val^seg[2*i+1].val;
}
void upd(int i, int pos, int v){
    if(seg[i].l==seg[i].r&&seg[i].l==pos){
        seg[i].val = v;
        return;
    }
    int mid = (seg[i].l+seg[i].r)/2;
    if(pos<=mid) upd(2*i, pos, v);
    else upd(2*i+1, pos, v);
    seg[i].val = seg[2*i].val^seg[2*i+1].val;
}
int qry(int i, int x, int y){
    if(seg[i].l==x&&seg[i].r==y) return seg[i].val;
    int mid = (seg[i].l+seg[i].r)/2;
    if(y<=mid) return qry(2*i, x, y);
    else if(x>mid) return qry(2*i+1, x, y);
    else return qry(2*i, x, mid)^qry(2*i+1, mid+1, y);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    build_seg(1, 1, N);
    for(int i = 0, t, x, y;i<Q;i++){
        cin >> t >> x >> y;
        if(t==1){
            upd(1, x, F[x]^y);
            F[x]^=y;
        }else cout << qry(1, x, y) << nl;
    }
    return 0;
} 