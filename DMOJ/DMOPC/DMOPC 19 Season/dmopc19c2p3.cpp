/*
Selection
DMOPC '19 Contest 2 P3
https://dmoj.ca/problem/dmopc19c2p3
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, k, bit1[21][300001], F[300001];
void update(int r, int index, int val){
    for(int i = index;i<300001;i+=(i&-i)){
        bit1[r][i]+=val;
    }
}
int sum(int r, int index){
    int s = 0;
    for(int i = index;i>0;i-=(i&-i)){
        s+=bit1[r][i];
    }
    return s;
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 1;i<=N;i++){
        scanf("%d", &F[i]);
        update(F[i], i, 1);
    }
    for(int i = 0;i<M;i++){
        scanf("%d", &k);
        if(k==1){
            int a, b; scanf("%d%d", &a, &b);
            update(F[a], a, -1);
            update(b, a, 1);
            F[a] = b;
        }else{
            int l, r, c, cnt = 0; scanf("%d%d%d", &l, &r, &c);
            for(int j = 20;j>=0;j--){
                cnt+=(sum(j, r)-sum(j, l-1));
                if(cnt>=c){
                    printf("%d\n", j); break;
                }
            }
        }
    }
    return 0;
}