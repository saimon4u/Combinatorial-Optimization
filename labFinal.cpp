#include<bits/stdc++.h>
using namespace std;
#define SIZE 50
int graph[SIZE][SIZE];
int dist[SIZE][SIZE];
int parent[SIZE][SIZE];
vector<string> name;
int indexof(string a){
    for(int i=0; i<name.size(); i++){
        if(name[i]==a)return i;
    }
    return -1;
}
vector < set<string> > make;
set<pair<int,pair<int,int>>> A;
int findSet(int u){
    for(int i=0; i<name.size(); i++){
        if(make[i].find(name[u]) != make[i].end()){
            return i;
        }
    }
    return -1;
}
void kruskal(){
    for(int i=0; i<name.size(); i++){
        set<string> x;
        x.insert(name[i]);
        make.push_back(x);
    }
    set<pair<int,pair<int,int>>> st;
    for(int i=0; i<name.size(); i++){
        for(int j=0; j<name.size(); j++){
            if(graph[i][j] < INT_MAX){
                st.insert({graph[i][j],{i,j}});
            }
        }
    }
    while(make.size()!=1){
        auto edge = (*st.begin()).second;
        auto edge_w = (*st.begin()).first;
        st.erase(st.begin());
        if(findSet(edge.first) != findSet(edge.second)){
            A.insert({edge_w,edge});
            int index_u = findSet(edge.first);
            int index_v = findSet(edge.second);
            for(auto v: make[index_v]){
                make[index_u].insert(v);
            }
            auto it = make.begin() + index_v;
            make.erase(it);
        }
    }
}
int main(){
    freopen("labFinal.txt","r",stdin);
    int num_vertex,num_edge,from,to,dis,totalCost = 0;
    cin >> num_vertex >> num_edge;
    for(int i=0;i<=SIZE;i++){
        for(int j=0;j<=SIZE;j++){
            graph[i][j]=INT_MAX;
        }
    }
    string one,two;
    for(int i=0;i<num_edge;i++){
        cin >> one >> two >> dis;
        if(find(name.begin(),name.end(),one) == name.end())name.push_back(one);
        if(find(name.begin(),name.end(),two) == name.end())name.push_back(two);
        from = indexof(one);
        to = indexof(two);
        totalCost += dis;
        graph[from][to] = dis;
        graph[to][from] = dis;
    }
    kruskal();
    int minVal = 0;
    for(auto a: A){
        minVal += a.first;
        cout << name[a.second.first] << "->" << name[a.second.second] << " " << a.first << endl;
    }
    // cout << "Minimum cost is: " << minVal << endl;
    cout << "Maximum " << totalCost-minVal << " rupee can be saved" << endl;
}