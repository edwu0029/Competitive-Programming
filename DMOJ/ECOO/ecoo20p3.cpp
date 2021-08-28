//Problem: https://dmoj.ca/problem/ecoo20p3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
int T, N, h, w;
string cap[502], newcap[502];
void prune(int H, int W){
    int hmin = 0, hmax = H-1, wmin = 0, wmax = W-1;
    h = H; w = W;
    for(int i = 0;i<H;i++){
        int cnt = 0;
        for(int j = 0;j<W;j++){
            if(cap[i][j]=='*') cnt++;
        }
        if(cnt==0) hmin++;
        else break;
    }
    for(int i = H-1;i>=0;i--){
        int cnt = 0;
        for(int j = 0;j<W;j++){
            if(cap[i][j]=='*') cnt++;
        }
        if(cnt==0) hmax--;
        else break;
    }
    for(int i = 0;i<W;i++){
        int cnt = 0;
        for(int j = hmin;j<=hmax;j++){
            if(cap[j][i]=='*') cnt++;
        }
        if(cnt==0) wmin++;
        else break;
    }
    for(int i = W-1;i>=0;i--){
        int cnt = 0;
        for(int j = hmin;j<=hmax;j++){
            if(cap[j][i]=='*') cnt++;
        }
        if(cnt==0) wmax--;
        else break;
    }
    for(int i = hmin;i<=hmax;i++){
        newcap[i-hmin] = "";
        for(int j = wmin;j<=wmax;j++){
            newcap[i-hmin]+=cap[i][j];
        }
    }
    h = hmax-hmin+1; w = wmax-wmin+1;
}
void print017(){
    int cnt = 0;
    for(int i = 0;i<h;i++){
        if(newcap[i][w-1]=='*')cnt++;
    }
    if(cnt==h-1){cout << "1"; return;}
    cnt=0;
    for(int i = 0;i<h;i++){
        if(newcap[i][0]=='*')cnt++;
    }
    if(cnt==1){cout << "7"; return;}
    cout << "0";
    return;
}
void print389(){
    int cnt = 0;
    for(int i = 0;i<h;i++){
        if(newcap[i][0]=='*')cnt++;
    }
    if(cnt==3&&newcap[h-1][0]=='*'){
        cout << "3";
    }else if(cnt*2+3==h){
        cout << "9";
    }else{
        cout << "8";
    }
}
void print4(){
    cout << "4";
}
void print256(){
    int cntL = 0;
    for(int i = 0;i<h;i++){
        if(newcap[i][0]=='*')cntL++;
    }
    if(cntL==h-3){
        cout << "6";
    }else if(newcap[1][0]=='*'){
        cout << "5";
    }else{
        cout << "2";
    }
}
void solve(){
    int H, W; cin >> H >> W;
    for(int i = 0;i<H;i++){
        cin >> cap[i];
    }
    prune(H, W);
    bool is017 = false;
    int cnt = 0;
    for(int i = 0;i<h;i++){
        cnt = 0;
        for(int j = 0;j<w;j++){
            if(newcap[i][j]=='*')cnt++;
        }
        if(cnt==0){is017 = true; break;}
    }
    if(is017){print017(); return;}
    cnt = 0;
    for(int i = 0;i<h;i++){
        if(newcap[i][w-1]=='*')cnt++;
    }
    if(cnt==h-3){print389(); return;}
    if(cnt==h-1){print4(); return;}
    print256();
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    for(int t = 1;t<=T;t++){
        cin >> N;
        for(int n = 1;n<=N;n++){
            solve();
        }
        cout << nl;
    }
    return 0;
}