#include<bits/stdc++.h>
using namespace std;

struct pt{
    double x, y;

    pt(double x, double y) : x(x), y(y){

    }

    pt operator+(const pt& o){
        return pt(o.x+x,o.y+y);
    }
    pt operator-(const pt& o){
        return pt(x-o.x,y-o.y);
    }
    pt operator*(double a){
        return pt(x*a,y*a);
    }
    double operator*(const pt& o){
        return x*o.x + y*o.y;
    }
    pt operator/(double a){
        return pt(x/a,y/a);
    }
    double operator!(){
        return sqrt(x*x+y*y);
    }
    double operator&(){
        return x*x+y*y;
    }

};

double dist(pt v, pt w, pt p) {
  const double l2 = &(w-v);  
  if (l2 == 0.0) return !(p-v); 
  const double t = max(0.0, min(1.0, (p - v)*(w - v)/l2));
  pt projection = v + (w - v)*t;
  return !(p-projection);
}

int main(){
    int n, m;
    vector<pt> a, b;

    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        a.push_back(pt(x,y));
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        b.push_back(pt(x,y));
    }

    for(int i=n-1;i>=0;i--)
        a[i] = a[i]-b[0];

    for(int i=m-1;i>=0;i--)
        b[i] = b[i]-b[0];

    int i = 0, j = 0;
    pt p1 = a[0], p2 = b[0];
    vector<pt> deslocamentos;
    while(i+1<n && j+1<m){
        if(!(b[j+1]-p2) < !(a[i+1]-p1)){
            double t =  !(b[j+1]-p2);
            pt temp = ((a[i+1]-p1)*t/!(a[i+1]-p1));
            deslocamentos.push_back(p2+temp-b[j+1]);
            p2 = b[j+1];
            p1 = p1 + temp;
            j++;
        }
        else{
            double t =  !(a[i+1]-p1);
            pt temp = ((b[j+1]-p2)*t/!(b[j+1]-p2));
            deslocamentos.push_back(a[i+1]-p1-temp);
            p1 = a[i+1];
            p2 = p2+temp;
            i++;
        }
    }

    while(j+1<m){
        deslocamentos.push_back(b[j+1]-p2);
        p2 = b[j+1];
        j++;
    }

    while(i+1<n){
        deslocamentos.push_back(p1-a[i+1]);
        p1 = a[i+1];
        i++;
    }
    //cout << deslocamentos.size() <<"\n";
    //cout << i << " " << j <<"\n";
    double answ = 1e15;

    pt origin(0,0);
    p1 = a[0];
    for(int i=0;i<deslocamentos.size();i++){
        //cout << p1.x << " " << p1.y << " " << deslocamentos[i].x << " " << deslocamentos[i].y <<"\n";
        answ = min(answ,dist(p1,p1+deslocamentos[i],origin));
        //cout << answ <<"\n";
        p1 = p1 + deslocamentos[i];
    }
    
    cout << fixed << setprecision(16) << answ <<"\n";

    return 0;
}