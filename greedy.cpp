#include<bits/stdc++.h>
using namespace std;
struct Course{
    string name;
    int startTime;
    int finishTime;
    bool isConflict;
}courses[100];
int numOfCourse;
void Sort(){
    for(int i=0; i<numOfCourse; i++){
        for(int j=i+1; j<numOfCourse; j++){
            if(courses[i].finishTime > courses[j].finishTime){
                swap(courses[i],courses[j]);
            }
        }
    }
}
vector<vector<string>> result;
void scheduleCourse(int index,vector<string> res){
    if(index>numOfCourse-1){
        courses[index].isConflict = false;
    }
    res.push_back(courses[index].name);
    int i;
    for(i=index+1; i<numOfCourse; i++){
        if(courses[i].startTime >= courses[index].finishTime){
            scheduleCourse(i,res);
        }
        courses[i].isConflict = true;
    }
    result.push_back(res);
}
int max(int a,int b){
    return a>b ? a : b;
}
int main(){
    freopen("input.txt","r",stdin);
    cin >> numOfCourse;
    for(int i=0; i<numOfCourse; i++){
        cin >> courses[i].name >> courses[i].startTime >> courses[i].finishTime;
        courses[i].isConflict = false;
    }
    Sort();
    scheduleCourse(0,{});
    int maxSize = 0;
    for(auto it: result){
        maxSize = max(maxSize,it.size());
    }
    for(auto it: result){
        if(it.size()==maxSize){
            for(auto i: it){
                cout << i << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}