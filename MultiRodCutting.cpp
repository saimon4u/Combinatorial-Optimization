#include<bits/stdc++.h>
using namespace std;
int cutPrice[1000];
int generateRevenue(int len,int *prices){
    if(cutPrice[len]!=-1)return cutPrice[len];
    int profit;
    if(len==0)profit = 0;
    else profit = -1;
    for(int i=1; i<=len; i++){
        profit = max(profit,generateRevenue(len-i,prices)+prices[i]);
    }
    cutPrice[len] = profit;
    return cutPrice[len];
}
int main(){
    memset(cutPrice,-1,sizeof(cutPrice));
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int prices[n+1];
    cout << "Enter the cut prices: ";
    for(int i=1; i<=n; i++)cin >> prices[i];
    int number;
    cout << "Enter the number of Rod you have: ";
    cin >> number;
    int rodLength[number+1];
    rodLength[0] = 0;
    cout << "Enter the length of all rod: ";
    for(int i=1; i<=number; i++)cin >> rodLength[i];
    int max = *max_element(rodLength,rodLength+number);
    generateRevenue(max,prices);
    int sum = 0;
    for(int i=1; i<=number; i++){
        sum += cutPrice[rodLength[i]];
    }
    cout << "maximum revenue is: " << sum << endl;
    return 0;
}