//Problem: https://dmoj.ca/problem/ccc11s4

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
int uOn, uOp, uAn, uAp, uBn, uBp, uABn, uABp;
int On, Op, An, Ap, Bn, Bp, ABn, ABp;
int ans, t;
int fu(int v, int l){
   if(v>l) return l;
   else return v;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> uOn >> uOp >> uAn >> uAp >> uBn >> uBp >> uABn >> uABp;
    cin >> On >> Op >> An >> Ap >> Bn >> Bp >> ABn >> ABp;
	//O
    t = fu(uOn, On);
    ans+=t; uOn-=t; On-=t;
    
    t = fu(uOp, Op);
    ans+=t; uOp-=t; Op-=t;
    t = fu(uOn, Op);
    ans+=t; uOn-=t; Op-=t;
    //A
    t = fu(uAn, An);
    ans+=t; uAn-=t; An-=t;
    t = fu(uOn, An);
    ans+=t; uOn-=t; An-=t;
    
    t = fu(uAp, Ap);
    ans+=t; uAp-=t; Ap-=t;
    t = fu(uOp, Ap);
    ans+=t; uOp-=t; Ap-=t;
    t = fu(uAn, Ap);
    ans+=t; uAn-=t; Ap-=t;
    t = fu(uOn, Ap);
    ans+=t; uOn-=t; Ap-=t;
    //B
    t = fu(uBn, Bn);
    ans+=t; uBn-=t; Bn-=t;
    t = fu(uOn, Bn);
    ans+=t; uOn-=t; Bn-=t;
    
    t = fu(uBp, Bp);
    ans+=t; uBp-=t; Bp-=t;
    t = fu(uOp, Bp);
    ans+=t; uOp-=t; Bp-=t;
    t = fu(uBn, Bp);
    ans+=t; uBn-=t; Bp-=t;
    t = fu(uOn, Bp);
    ans+=t; uOn-=t; Bp-=t;
    //AB
    t = fu(uABn, ABn);
    ans+=t; uABn-=t; ABn-=t;
    t = fu(uBn, ABn);
    ans+=t; Bn-=t; ABn-=t;
    t = fu(uAn, ABn);
    ans+=t; uAn-=t; ABn-=t;
    t = fu(uOn, ABn);
    ans+=fu(uOn, ABn); uOn-=fu(uOn, ABn); ABn-=t;
    
    t = fu(uABp, ABp);
    ans+=t; uABp-=t; ABp-=t;
    t = fu(uBp, ABp);
    ans+=t; uBp-=t; ABp-=t;
    t = fu(uAp, ABp);
    ans+=t; uAp-=t; ABp-=t;
    t = fu(uOp, ABp);
    ans+=t; uOp-=t; ABp-=t;
    t = fu(uOn, ABp);
    ans+=t; uOn-=t; ABp-=t;
    t = fu(uAn, ABp);
    ans+=t; uAn-=t; ABp-=t;
    t = fu(uBn, ABp);
    ans+=t; uBn-=t; ABp-=t;
    t = fu(uABn, ABp);
    ans+=t; uABn-=t; ABp-=t;
    cout << ans << nl;
    return 0;
}