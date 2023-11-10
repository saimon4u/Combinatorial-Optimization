#include<bits/stdc++.h>
#include<math.h>
using namespace std;

set<pair<double,pair <double,double>>> Q;
vector <pair<double,double>> S;
int mark = -1;
pair<double,double> getMin(vector < pair<double,double> > &points){
    pair <double,double> point;
    point.first = numeric_limits<double>::max();
    point.second = numeric_limits<double>::max();
    for(auto p: points){
        if(p.second < point.second){
            point.first = p.first;
            point.second = p.second;
        }
    }
    auto it = points.begin();
    while(it<points.end()){
        if((*it).first == point.first and (*it).second == point.second){
            points.erase(it);
            break;
        }
        it++;
    }
    return point;
}


double Angle(pair<double,double> p1,pair<double,double> p2){
    pair <double,double> point;
    point.first = p2.first - p1.first;
    point.second = p2.second - p1.second;
    double theta = abs(point.second)/abs(point.first);
    if(point.first > 0 and point.second > 0) return atan(theta)*(180/M_PI);
    else if(point.first > 0 and point.second < 0) return 360 - atan(theta)*(180/M_PI);
    else if(point.first < 0 and point.second > 0) return 180 - atan(theta)*(180/M_PI);
    else if(point.first < 0 and point.second < 0) return 180 + atan(theta)*(180/M_PI);
    return 0.0;
}

bool NonLeftTurn(pair <double,double> p0,pair <double,double> p1,pair <double,double> p2){
    pair <double,double> line1,line2;
    line1.first = p1.first - p0.first;
    line1.second = p1.second - p0.second;
    line2.first = p2.first - p0.first;
    line2.second = p2.second - p0.second;
    double crossProduct = ((line2.first*line1.second) - (line1.first*line2.second));
    if(crossProduct < 0) return false;
    return true;
}


void GScan(pair<double,double> p0){
    S.push_back(p0);
    mark++;
    pair <double,double> point,top,topNext;
    point = (*Q.begin()).second;
    S.push_back(point);
    mark++;
    Q.erase(Q.begin());
    while(!Q.empty()){
        top = S[mark];
        topNext = S[mark-1];
        point = (*Q.begin()).second;
        while(NonLeftTurn(topNext,top,point)){
            S.erase(S.end()-1);
            mark--;
            if(mark < 1)break;
            top = S[mark];
            topNext = S[mark-1];
        }
        S.push_back(point);
        mark++;
        Q.erase(Q.begin());
    }
}
int main(){
    freopen("Graham.txt","r",stdin);
    int numPoint;
    cin >> numPoint;
    vector < pair<double,double> > points(numPoint);
    for(int i=0; i<numPoint; i++) cin >> points[i].first >> points[i].second;
    pair <double,double> p0 = getMin(points);
    for(auto p: points){
        Q.insert({Angle(p0,p),p});
    }
    GScan(p0);
    for(auto s: S){
        cout << s.first << " " << s.second << endl;
    }
}