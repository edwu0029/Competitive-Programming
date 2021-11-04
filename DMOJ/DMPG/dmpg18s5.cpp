/*
Mimi and Division
DMPG '18 S5
https://dmoj.ca/problem/dmpg18s5
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
const int MAXN = 2e5+5, blk = 500;
int N, Q, A[MAXN], cnt[MAXN][blk];
vector<int>factors[MAXN];
void upd(int num, int pos, int v){
    for(int x:factors[num]) cnt[x][pos/blk]+=v;
}
int qry(int l, int r, int x){
    int lft = l/blk, rht = r/blk, ret = 0;
    if(lft==rht){
        for(int i = l;i<=r;i++){
            if(A[i]%x==0) ret++;
        }
    }else{
        for(int i = l;i<=(lft+1)*blk-1;i++){
            if(A[i]%x==0) ret++;
        }
        for(int i = lft+1;i<rht;i++) ret+=cnt[x][i];
        for(int i = rht*blk;i<=r;i++){
            if(A[i]%x==0) ret++;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1;i<MAXN;i++){
        for(int j = 1;j*j<=i;j++){
            if(i%j) continue;
            factors[i].push_back(j);
            if(j*j!=i) factors[i].push_back(i/j);
        }
    }
    for(int i = 1;i<=N;i++){
        cin >> A[i];
        upd(A[i], i, 1);
    }
    for(int i = 1, op, a, b, c;i<=Q;i++){
        cin >> op;
        if(op==1){
            cin >> a >> b >> c;
            cout << qry(a, b, c) << nl;
        }else{
            cin >> a >> b;
            upd(A[a], a, -1);
            upd(b, a, 1);
            A[a] = b;
        }
    }
    return 0;
}