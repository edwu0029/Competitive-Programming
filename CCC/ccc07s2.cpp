//Problem: https://dmoj.ca/problem/ccc07s2

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
const int MAXN = 1005;
struct box{
    int l, w, h;
    friend bool operator<(const box &a, const box &b){
        return a.l*a.w*a.h<b.l*b.w*b.h;
    }
}boxes[MAXN];
int N, M;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        vector<int>F(3);
        for(int j = 0;j<3;j++) cin >> F[j];
        sort(F.begin(), F.end());
        boxes[i] = {F[0], F[1], F[2]};
    }
    sort(boxes, boxes+N);
    cin >> M;
    for(int i = 0;i<M;i++){
        vector<int>F(3);
        for(int j = 0;j<3;j++) cin >> F[j];
        sort(F.begin(), F.end());
        bool f = false;
        for(int j = 0;j<N;j++){
            if(boxes[j].l>=F[0]&&boxes[j].w>=F[1]&&boxes[j].h>=F[2]){
                cout << boxes[j].l*boxes[j].w*boxes[j].h << nl;
                f = true;
                break;
            }
        }
        if(!f) cout << "Item does not fit." << nl;
    }
    return 0;
}