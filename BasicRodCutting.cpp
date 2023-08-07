#include<bits/stdc++.h>
using namespace std;

int store[1000];
int cutPrice[100000];
int maxRevenue(int len,int *prices){
    if(cutPrice[len]!=-1)return cutPrice[len];
    int profit;
    if(len==0)profit = 0;
    else profit = -1;
    for(int i=1; i<=len; i++){
        int x = maxRevenue(len-i,prices) + prices[i];
        // profit = max(profit,maxRevenue(len-i,prices) + prices[i]);
        if(profit<=x){
            store[len] = i;
            profit = x;
        }
    }
    cutPrice[len] = profit;
    return profit;
}
// int maxRevenue(int len,int *prices){
//     int cutPrice[len+1];
//     cutPrice[0] = 0;
//     int profit;
//     for(int i=1; i<=len; i++){
//         profit = -1;
//         for(int j=1; j<=i; j++){
//             if(profit<prices[j] + cutPrice[i-j]){
//                 profit = prices[j] + cutPrice[i-j];
//                 store[i] =j;
//             }
//         }
//         cutPrice[i] = profit;
//     }
//     return cutPrice[len];
// }
int main(){
    memset(cutPrice,-1,sizeof(cutPrice));
    freopen("basicRod.txt","r",stdin);
    int len;
    // cout << "Enter the length of rod: ";
    cin >> len;
    int prices[len];
    // cout << "Enter all the prices: ";
    for(int i=1; i<=len; i++)cin >> prices[i];
    int n;
    cin >> n;
    cout << "Maximum Revenue is: " << " " << maxRevenue(n,prices) << endl;
    cout << "You have cut the rod in: ";
    while(n>0){
        cout << store[n] << " ";
        n =  n - store[n];
    }
    cout << endl;
    return 0;
}