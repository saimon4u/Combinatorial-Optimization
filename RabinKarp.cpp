#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("Rabin.txt","r",stdin);
    string pattern,text;
    cin >> pattern >> text;
    int p=0;
    for(int i=0; i<pattern.size(); i++){
        p = 2*p + (pattern[i]-'0');
    }
    int count = 0;
    int t[text.size()];
    for(int s=0; s<=text.size()-pattern.size(); s++){
        t[s] = 0;
        for(int i=0; i<pattern.size(); i++){
            t[s] = 2*t[s] + (text[s+i]-'0');
        }
        if(t[s]==p){
            cout << "Pattern matches at " << s << " index." << endl;
            count++;
        }
    }
    // t[0] = 0;
    // int offset = 1;
    // for(int i=0; i<pattern.size(); i++) offset = 2*offset;
    // for(int i=0; i<pattern.size(); i++) t[0] = 2*t[0] + (text[i]-'0');
    // if(t[0]==p){
    //     cout << "Pattern matches at " << 0 << " index." << endl;
    //     count++;
    // }
    // for(int i=1; i<=text.size()-pattern.size(); i++){
    //     t[i] = (2*(t[i-1] - (offset*(text[i-1]-'0'))) + (text[i+pattern.size()-1]-'0'));
    //     cout << t[i] << endl;
    //     if(t[i]==p){
    //         cout << "Pattern matches at " << i << " index." << endl;
    //         count++;
    //     }
    // }
    cout << "Total matches: " << count << " times." << endl;
    return 0;
}