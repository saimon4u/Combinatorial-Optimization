#include<bits/stdc++.h>
using namespace std;
int main(){
    pair <int,int> point0,point1,point2;
    cout << "Enter coordinate for 3 point respectedly: " << endl;
    cin >> point0.first >> point0.second >> point1.first >> point1.second >> point2.first >> point2.second;
    pair <int,int> line1,line2;
    line1.first = point1.first - point0.first;
    line1.second = point1.second - point0.second;
    line2.first = point2.first - point0.first;
    line2.second = point2.second - point0.second;
    int crossProduct = ((line2.first*line1.second) - (line1.first*line2.second));
    if(crossProduct > 0) cout << "We make a right turn at point1." << endl;
    else if(crossProduct < 0) cout << "We make a left turn at point1" << endl;
    else cout << "We do not make a turn." << endl;
    return 0;
}