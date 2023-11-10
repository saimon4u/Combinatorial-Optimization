#include<bits/stdc++.h>
using namespace std;
int main(){
    pair <int,int> line1,line2;
    cout << "Enter x & y cordinate for line1: ";
    cin >> line1.first >> line1.second;
    cout << "Enter x & y cordinate for line2: ";
    cin >> line2.first >> line2.second;
    int crossProduct = ((line1.first*line2.second) - (line2.first*line1.second));
    if(crossProduct > 0) cout << "Line2 is counterclockwise from line1." << endl;
    else if(crossProduct < 0) cout << "Line2 is clockwise from line1." << endl;
    else cout << "Line1 and line2 both are same line." << endl;
    return 0;
}