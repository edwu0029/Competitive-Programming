//Problem: https://dmoj.ca/problem/dmopc14c2p1

#include <bits/stdc++.h>
using namespace std;
int D, T, G;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> D;
    int F[D]{};
    for(int i = 0;i<D;i++){
        cin >> T;
        for(int j = 0;j<T;j++){
            cin >> G; F[i]+=G;
        }
        if(F[i]){
            cout<<"Day "<<i+1<<": "<< F[i]<< '\n';
        }else{
            cout << "Weekend";
        }
    }
}