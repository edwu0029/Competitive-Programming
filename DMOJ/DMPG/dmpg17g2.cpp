/*
Holy Grail War
DMPG '17 G2
https://dmoj.ca/problem/dmpg17g2
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
    ll pre, suf, sum, best;
}seg[3*MAXN];
int N, Q, F[MAXN];
void push_up(int i){
    seg[i].pre = max(seg[2*i].pre, seg[2*i].sum + seg[2*i+1].pre);
    seg[i].suf = max(seg[2*i].suf+seg[2*i+1].sum, seg[2*i+1].suf);
    seg[i].sum = seg[2*i].sum + seg[2*i+1].sum;
    seg[i].best = max(max(seg[2*i].best, seg[2*i+1].best), seg[2*i].suf + seg[2*i+1].pre);
}
void build_tree(int l, int r, int i){
    seg[i].l = l; seg[i].r = r;
    if(l==r){
        seg[i].sum = seg[i].pre = seg[i].suf = seg[i].best = F[l];
        return;
    }
    int mid = (l+r)/2;
    build_tree(l, mid, i*2); build_tree(mid+1, r, 2*i+1);
    push_up(i);
}
void update(int p, int val, int i){
    if(seg[i].l==p&&seg[i].r==p){
        seg[i].pre=seg[i].suf =seg[i].sum=seg[i].best=val;
        return;
    }
    int mid = (seg[i].l+seg[i].r)/2;
    if(p<=mid){
        update(p, val, 2*i);
    }else{
        update(p, val, 2*i+1);
    }
    push_up(i);
}
node query(int l, int r, int i){
    if(seg[i].l==l&&seg[i].r==r)return seg[i];
    int mid = (seg[i].l+seg[i].r)/2;
    if(r<=mid)return query(l, r, 2*i);
    else if(l>mid)return query(l, r, 2*i+1);
    else {
        node tmp=query(l, mid, 2*i), tmp2=query(mid+1, r, 2*i+1), ans;
        ans.pre = max(tmp.pre, tmp2.pre+tmp.sum);
        ans.suf = max(tmp.suf+tmp2.sum, tmp2.suf);
        ans.sum = tmp.sum + tmp2.sum;
        ans.best = max(max(tmp.best, tmp2.best), tmp.suf+tmp2.pre);
        return ans;
    }
}
int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1;i<=N;i++)scanf("%d", &F[i]);
    build_tree(1, N, 1);
    for(int i = 0, a, b;i<Q;i++){
        char k; scanf(" %c %d %d", &k, &a, &b);
        if(k=='S'){
            update(a, b, 1); 
        }else{
            printf("%lld\n", query(a, b, 1).best);
        }
    }
    return 0;
}