#include<bits/stdc++.h>
using namespace std;
bool BoxCollide(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3,pair<double,double> p4){
    return ((p4.first < p1.first) or (p3.first > p2.first) or (p4.second < p1.second) or (p3.second > p2.second));
}
int Direction(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3){
    pair <double,double> line1,line2;
    line1.first = p3.first - p1.first;
    line1.second = p3.second - p1.second;
    line2.first = p2.first - p1.first;
    line2.second = p2.second - p1.second;
    int crossProduct = ((line1.first*line2.second) - (line2.first*line1.second));
    return crossProduct;
}
bool OnSegment(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3){
    return (min(p1.first,p2.first) <= p3.first and max(p1.first,p2.first) >= p3.first)
            and (min(p1.second,p2.second) <= p3.second and max(p1.second,p2.second) >= p3.second);
}
bool LineIntersect(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3,pair<double,double> p4){
    int d1,d2,d3,d4;
    d1 = Direction(p3,p4,p1);
    d2 = Direction(p3,p4,p2);
    d3 = Direction(p1,p2,p3);
    d4 = Direction(p1,p2,p4);
    if(((d1>0 and d2<0) or (d1<0 and d2>0)) and ((d3>0 and d4<0) or (d3<0 and d4>0))) return true;
    if(d1==0 and OnSegment(p3,p4,p1)) return true;
    if(d2==0 and OnSegment(p3,p4,p2)) return true;
    if(d3==0 and OnSegment(p1,p2,p3)) return true;
    if(d4==0 and OnSegment(p1,p2,p4)) return true;
    return false;
}
int main(){
    pair <double,double> p1,p2,p3,p4;
    cout << "Enter coordinate of 2 points of line 1: " << endl;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cout << "Enter coordinate of 2 points of line 2: " << endl;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    if(BoxCollide(p1,p2,p3,p4)){
        cout << "This two line segment don't intersect." << endl;
        return 0;
    }
    if(LineIntersect(p1,p2,p3,p4)) cout << "This two line intersect each other." << endl;
    else cout << "This two line don't intersect each other." << endl;
    return 0;
}