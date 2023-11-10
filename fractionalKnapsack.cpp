#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_item,totalWeight,maxEarn = 0,itemGet = 0;
    cin >> num_item;
    vector <int> weight(num_item),benefit(num_item);
    for(int i=0; i<num_item; i++) cin >> weight[i] >> benefit[i];
    cin >> totalWeight;
    vector <int> amount(num_item,0);
    vector <int> unitPrice(num_item);
    for(int i=0; i<num_item; i++) unitPrice[i] = benefit[i]/weight[i];
    while(itemGet < totalWeight){
        auto it = max_element(unitPrice.begin(),unitPrice.end());
        
    }
}