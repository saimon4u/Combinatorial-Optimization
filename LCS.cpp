#include<bits/stdc++.h>
using namespace std;
#define UP 1
#define SIDE 2
#define DIAG 3
int arrow[100][100];
void printLCS(char first[],int i,int j){
    if(i==0 || j==0)return;
    if(arrow[i][j]==DIAG){
        printLCS(first,i-1,j-1);
        printf("%c ",first[i]);
    }
    else if(arrow[i][j]==UP)printLCS(first,i-1,j);
    else printLCS(first,i,j-1);
}
int main(){
    string f,s;
    cout << "Enter first string: ";
    cin >> f;
    cout << "Enter second string: ";
    cin >> s;
    char first[f.size()+1],second[s.size()+1];
    for(int i=0; i<f.size(); i++)first[i+1] = f[i];
    for(int i=0; i<s.size(); i++)second[i+1] = s[i];
    int c[f.size()+1][s.size()+1];
    for(int i=0; i<=f.size(); i++)c[i][0] = 0;
    for(int i=0; i<=s.size(); i++)c[0][i] = 0;
    for(int i=1; i<=f.size(); i++){
        for(int j=1; j<=s.size(); j++){
            // cout << first[i] << " " << second[j] << endl;
            if(first[i]==second[j]){
                c[i][j] = c[i-1][j-1] + 1;
                arrow[i][j] = DIAG;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                arrow[i][j] = UP;
            }
            else{
                c[i][j] = c[i][j-1];
                arrow[i][j] = SIDE;
            }
        }
    }
    for(int i=0; i<=f.size(); i++){
        for(int j=0; j<=s.size(); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << "LCS of this two string is: " << c[f.size()][s.size()] << endl;
    cout << "LCS is: ";
    printLCS(first,f.size(),s.size());
    cout << endl;
    return 0;
}