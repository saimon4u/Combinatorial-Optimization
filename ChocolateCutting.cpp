//Incomplete solution problem with the recursive algorithm

#include<bits/stdc++.h>
using namespace std;
int prices[1000][1000];

int revenue(int m,int n){
    if(n==0 || m==0)return 0;
    int profit;
    for(int row=1; row<=m; row++){
        for(int col=1; col<=n; col++){
            profit = max(max(profit,revenue(m-row,n) + prices[row][n]),max(profit,revenue(m,n-col)+prices[m][col]));
        }
    }
    return profit;
}

int main(){
    int n,m;
    cout << "Ente m and n: ";
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> prices[i][j];
        }
    }
    cout << revenue(m,n) << endl;
}