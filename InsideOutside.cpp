#include<bits/stdc++.h>
using namespace std;
pair <double,double> ExtendedPoint(vector <pair <double,double>> &polygon,pair <double,double> &point){
    pair <double,double> extended;
    double minX = numeric_limits<double>::max();
    for(auto p: polygon){
        if(p.first < minX) minX = p.first;
    }
    extended.first = minX - 5;
    extended.second = point.second;
    return extended;
}


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
    freopen("polygon.txt","r",stdin);
    int numPoint;
    cin >> numPoint;
    vector <pair <double,double>> polygon(numPoint);
    for(int i=0; i<numPoint; i++){
        cin >> polygon[i].first >> polygon[i].second;
    }
    pair <double,double> point;
    cin >> point.first >> point.second;
    pair <double,double> extendedPoint = ExtendedPoint(polygon,point);
    int intersectCount = 0;
    for(int i=0; i<numPoint; i++){
        if(i==numPoint-1 and LineIntersect(polygon[i],polygon[0],point,extendedPoint)){
            intersectCount++;
        }
        else if(LineIntersect(polygon[i],polygon[i+1],point,extendedPoint)) intersectCount++;
    }
    if(intersectCount == 1) cout << "Given point is inside of the Polygon." << endl;
    else cout << "Given point is outside of the Polygon." << endl;
    return 0;
}