//Problem: https://dmoj.ca/problem/dmopc15c1p6

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
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e5+5, LOG = 16;
struct node{
	int l, r;
	ll lazy, sum;
}seg[3*MAXN];
int M, N, Q, F[MAXN];
void build_tree(int l, int r, int i){
	seg[i].l = l; seg[i].r = r;
	if(l==r){seg[i].lazy = 0; seg[i].sum = F[l]; return;}
	int mid = (l+r)/2;
	build_tree(l, mid, 2*i); build_tree(mid+1, r, 2*i+1);
	seg[i].sum = seg[2*i].sum+seg[2*i+1].sum;
}
void update(int l, int r, int val, int i){
	if(seg[i].l==l&&seg[i].r==r){
		seg[i].lazy+=val; seg[i].sum+=(ll)val*(r-l+1);
		return;
	}
	if(seg[i].lazy!=0){
		seg[2*i].lazy+=seg[i].lazy; seg[2*i+1].lazy+=seg[i].lazy;
		seg[2*i].sum+=(seg[i].lazy*(seg[2*i].r-seg[2*i].l+1));
		seg[2*i+1].sum+=(seg[i].lazy*(seg[2*i+1].r-seg[2*i+1].l+1));
		seg[i].lazy = 0;
	}
	int mid = (seg[i].l+seg[i].r)/2;
	if(r<=mid){
		update(l, r, val, 2*i);
	}else if(l>mid){
		update(l, r, val, 2*i+1);
	}else{
		update(l, mid, val, 2*i); update(mid+1, r, val, 2*i+1);
	}
	seg[i].sum = seg[2*i].sum+seg[2*i+1].sum;
}
ll query(int l, int r, int i){
	if(seg[i].l==l&&seg[i].r==r)return seg[i].sum;
	if(seg[i].lazy!=0){
		seg[2*i].lazy+=seg[i].lazy; seg[2*i+1].lazy+=seg[i].lazy;
		seg[2*i].sum+=(seg[i].lazy*(seg[2*i].r-seg[2*i].l+1));
		seg[2*i+1].sum+=(seg[i].lazy*(seg[2*i+1].r-seg[2*i+1].l+1));
		seg[i].lazy = 0;
	}
	int mid = (seg[i].l+seg[i].r)/2;
	if(r<=mid){
		return query(l, r, 2*i);
	}else if(l>mid){
		return query(l, r, 2*i+1);
	}else{
		return query(l, mid, 2*i)+query(mid+1, r, 2*i+1);
	}
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> M >> N >> Q;
    for(int i = 1;i<=N;i++){cin >> F[i];}
    build_tree(1, N,1);
    for(int i = 0, op, l, r, x;i<Q;i++){
        cin >> op >> l >> r;
        if(op==1){
            cin >> x;
            update(l, r, x, 1);
        }else{
            cout << query(l ,r ,1)%M << '\n';
        }
    }
    return 0;
}