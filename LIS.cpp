#include<bits/stdc++.h>
using namespace std;
#define MAX 500
vector<int> L;
vector<int> pre(MAX);
vector<int> len;
void LIS_FAST(int *arr,int n){
    L.push_back(INT_MIN);
    len.push_back(-1);
    pre[0] = -1;
    for(int i=1; i<=n; i++){
        if(L[L.size()-1] < arr[i]){
            L.push_back(arr[i]);
            len[L.size()-1] = i;
            pre[i] = len[L.size()-2];
        }
        else{
            int s = 0;
            int h = L.size();
            while(s<h){
                int mid = (s+h)/2;
                if(L[mid] < arr[i])s = mid+1;
                else h = mid;
            }
            L[s] = arr[i];
            len[s] = i;
            pre[i] = len[s-1];
        }
    }
}
void printLIS(int *arr,int index){
    if(index==-1)return;
    printLIS(arr,pre[index]);
    cout << arr[index] << " ";
}
int main(){
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int arr[n+1];
    cout << "Enter all the values: ";
    for(int i=1; i<=n; i++)cin >> arr[i];
    LIS_FAST(arr,n);
    cout << L.size()-1 << endl;
    printLIS(arr,len[L.size()-1]);
    cout << endl;
    return 0;
}