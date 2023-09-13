#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
int w[SIZE][SIZE],d[SIZE],pre[SIZE];
int n = 0;
bool flag[SIZE];
string name[SIZE];
void initialization(int source){
    for(int v=0; v<n; v++){
        d[v] = INT_MAX;
        pre[v] = -1;
    }
    d[source] = 0;
}
void relax(int u,int v){
    if(d[v] > d[u] + w[u][v]){
        d[v] = d[u] + w[u][v];
        pre[v] = u;
    }
}
int mini(){
    int m = INT_MAX,index;
    for(int i=0; i<n; i++){
        if(flag[i] && m > d[i]){
            m = d[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int source){
    initialization(source);
    for(int i=0; i<n; i++){
        flag[i] = true;
    }
    int qSize = n;
    while(qSize--){
        int u = mini();
        for(int v=0; v<n; v++){
            if(w[u][v] > 0){
                relax(u,v);
            }
        }
    }
}
void readInput(){
    string s;
    int u,v;
    while((cin >> s)){
        if(s == "END")break;
        for(u=0; u<n; u++){
            if(name[u] == s){
                break;
            }
        }
        if(u==n)name[n++] = s;
        cin >> s;
        for(v=0; v<n; v++){
            if(name[v] == s){
                break;
            }
        }
        if(v==n)name[n++] = s;
        cin >> w[u][v];
    }
}
void printGraph(){
    int u,v;
    for(u=0; u<n; u++){
        for(v=0; v<n; v++){
            cout << w[u][v] << " ";
        }
        cout << endl;
    }
}
void printPath(int destination){
    if(destination = -1)return;
    printPath(pre[destination]);
    cout << destination << endl;
}
int main(){
    freopen("dijkstra_input.txt","r",stdin);
    readInput();
    printGraph();
    cout << endl;
    dijkstra(0);
    printPath(2);
    return 0;
}