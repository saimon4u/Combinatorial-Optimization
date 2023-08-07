#include<bits/stdc++.h>
using namespace std;
int cutPrice[1000];
int store[1000];
int revenue(int len_to_cut,int *prices,int n){
    if(cutPrice[len_to_cut]!=-1)return cutPrice[len_to_cut];
    int rev;
    if(len_to_cut==0)rev=0;
    else rev = -1;
    for(int i=1; i<=n; i++){
        if(len_to_cut-i >=0){
            int x;
            x = revenue(len_to_cut-i,prices,n) + prices[i];
            // rev = max(rev,revenue(len_to_cut-i,prices,n) + prices[i]);
            if(rev<=x){
                store[len_to_cut] = i;
                rev = x;
            }
        }
        else{
            cutPrice[len_to_cut]=prices[len_to_cut];
        }
    }
    cutPrice[len_to_cut] = rev;
    return cutPrice[len_to_cut];
}
int main(){
    memset(cutPrice,-1,sizeof(cutPrice));
    freopen("greaterRod.txt","r",stdin);
    int n;
    // cout << "Enter the size: ";
    cin >> n;
    int prices[n+1];
    // cout << "Enter the price of each length: ";
    for(int i=1; i<=n; i++)cin >> prices[i];
    int len;
    // cout << "Enter the length you want to cut: ";
    cin >> len;
    cout << "Maximum revenue is: " <<  revenue(len,prices,n) << endl;
    cout << "You have cut the rod in: ";
    while(len>0){
        cout << store[len] << " ";
        len =  len - store[len];
    }
    cout << endl;
    return 0;
}