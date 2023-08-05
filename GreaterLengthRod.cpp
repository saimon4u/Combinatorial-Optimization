#include<bits/stdc++.h>
using namespace std;
int cutPrice[1000];
int revenue(int len_to_cut,int *prices,int n){
    if(cutPrice[len_to_cut]!=-1)return cutPrice[len_to_cut];
    int rev;
    if(len_to_cut==0)rev=0;
    else rev = -1;
    for(int i=1; i<=n; i++){
        if(len_to_cut-i >=0){
            rev = max(rev,revenue(len_to_cut-i,prices,n) + prices[i]);
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
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int prices[n+1];
    cout << "Enter the price of each length: ";
    for(int i=1; i<=n; i++)cin >> prices[i];
    int len;
    cout << "Enter the length you want to cut: ";
    cin >> len;
    cout << revenue(len,prices,n) << endl;
    return 0;
}