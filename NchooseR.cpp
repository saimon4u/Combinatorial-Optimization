#include<bits/stdc++.h>
using namespace std;

int C[10000][10000];
int Combination(int n,int r){
    if(C[n][r]!=-1)return C[n][r];
    if(r==1)return C[n][r] = n;
    else if(n==r || r==0)return C[n][r] = 1;
    return C[n][r] = Combination(n-1,r-1) + Combination(n-1,r);
}

int main(){
    memset(C,-1,sizeof(C));
    int n,r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    cout << Combination(n,r) << endl;
    return 0;
}