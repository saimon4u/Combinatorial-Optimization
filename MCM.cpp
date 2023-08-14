#include<bits/stdc++.h>
using namespace std;
int m[100][100];
int s[100][100];
void fill(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            m[i][j] = INT_MAX;
        }
    }
}
int RMC(int *p,int i,int j){
    if(m[i][j]<INT_MAX){
        return m[i][j];
    }
    if(i==j){
        m[i][j] = 0;
        return m[i][j];
    }
    int min;
    for(int k=i; k<j; k++){
        min = RMC(p,i,k) + RMC(p,k+1,j) + (p[i-1]*p[k]*p[j]);
        if(min < m[i][j]){
            m[i][j] = min;
            s[i][j] = k;
        }
    }
    return m[i][j];
}
void printParenthesis(int i,int j){
    if(i==j)cout << "A" << i;
    else{
        cout << "(";
        printParenthesis(i,s[i][j]);
        printParenthesis(s[i][j]+1,j);
        cout << ")";
    }
}
int main(){
    int n;
    cout << "Enter the number of matrix: ";
    cin >> n;
    int p[n+1];
    cout << "Enter all the dimension: ";
    for(int i=0; i<=n; i++)cin >> p[i];
    fill();
    int min = RMC(p,1,n);
    cout << "Minimum operation need: " << m[1][n] << endl;
    printParenthesis(1,n);
}