#include<bits/stdc++.h>
using namespace std;
void ComputePrefixFunction(string pattern,vector<int> &prefix){
    int m = pattern.size();
    prefix[0] = 0;
    int k=0;
    for(int q=1; q<=m; q++){
        while(k>0 and pattern[k] != pattern[q]){
            k = prefix[k];
        }
        if(pattern[k] == pattern[q]){
            k++;
        }
        prefix[q] = k;
    }
}
void KmpMatcher(string text,string pattern,vector<int> &prefix){
    int n = text.size();
    int m = pattern.size();
    ComputePrefixFunction(pattern,prefix);
    int q = 0;
    for(int i=0; i<n; i++){
        // cout << text[i] << " " << pattern[q] << endl;
        while(q>0 and pattern[q] != text[i])
            q = prefix[q-1];
        if(pattern[q] == text[i]) q++;
        if(q==m){
            cout << "Pattern occurs with shift " << (i-m+1) << endl;
            q = prefix[q];
        }
    }
}
int main(){
    freopen("kmp.txt","r",stdin);
    string pattern,text;
    cin >> pattern >> text;
    vector<int> prefix(pattern.size());
    KmpMatcher(text,pattern,prefix);
}