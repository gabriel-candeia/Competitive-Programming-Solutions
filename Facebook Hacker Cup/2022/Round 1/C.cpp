#include<bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef POINT_DOUBLE
  typedef double ftype;
  typedef long double ftLong;
  const double EPS = 1e-9;
  #define eq(a, b) (abs((a) - (b)) < EPS)
  #define lt(a, b) (((a) + EPS) < (b))
  #define gt(a, b) ((a) > ((b) + EPS))
  #define le(a, b) ((a) < ((b) + EPS))
  #define ge(a, b) (((a) + EPS) > (b))
#else
  typedef int32_t ftype;
  typedef int64_t ftLong;
  #define eq(a, b) ((a) == (b))
  #define lt(a, b) ((a) < (b))
  #define gt(a, b) ((a) > (b))
  #define le(a, b) ((a) <= (b))
  #define ge(a, b) ((a) >= (b))
#endif

struct Point2d{
  ftype x, y;
  Point2d() {}
  Point2d(ftype x1, ftype y1) : x(x1), y(y1) {}
  Point2d operator+(const Point2d &t){
    return Point2d(x + t.x, y + t.y);
  }
  Point2d operator-(const Point2d &t){
    return Point2d(x - t.x, y - t.y);
  }
  Point2d operator*(ftype t){
    return Point2d(x * t, y * t);
  }
  Point2d operator/(ftype t){
    return Point2d(x / t, y / t);
  }
  bool operator<(const Point2d &o) const{
    return lt(x, o.x) or (eq(x, o.x) and lt(y, o.y));
  }
  bool operator==(const Point2d &o) const{
    return eq(x, o.x) and eq(y, o.y);
  }
  friend std::istream& operator >> (std::istream &is, Point2d &p) {
    return is >> p.x >> p.y;
  }  
  friend std::ostream& operator << (std::ostream &os, const Point2d &p) {
    return os << p.x << ' ' << p.y;
  }
};
//Squared distance
ll dist(Point2d a, Point2d b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
//Vector product
ftLong cross(Point2d a, Point2d b){
  return a.x * (ftLong)b.y - a.y * (ftLong)b.x;
}
//If accept collinear points then change for <=
bool cw(Point2d a, Point2d b, Point2d c) {
  return lt(cross(b - a, c - b), 0);
}
//If accept collinear points then change for >=
bool ccw(Point2d a, Point2d b, Point2d c) {
  return gt(cross(b - a, c - b), 0);
}
// Returns the points clockwise
vector<Point2d> convex_hull(vector<Point2d> a){
  if (a.size() == 1)
    return a;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  vector<Point2d> up, down;
  Point2d p1 = a[0], p2 = a.back();
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++){
    if ((i == int(a.size() - 1)) || cw(p1, a[i], p2)){
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if ((i == int(a.size() - 1)) || ccw(p1, a[i], p2)){
      while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);  
  for (int i = down.size() - 2; i > 0; i--)
    a.push_back(down[i]);  
  return a;
}

bool contem(int x, int y, int z){
    if(x<y){
        return x<=z && z<=y;
    }
    else{
        return y<=z || z<=x;
    }
}

int main(){
    int t, caso = 0;

    cin >> t;
    while(t--){
        ll n, k, d;
        vector<Point2d> arr;

        cin >> n >> k >> d;
        for(int i=0;i<n;i++){
            ll x, y;
            cin >> x >> y;
            arr.push_back(Point2d(x,y));
        }

        Point2d fst = arr[0], lst = arr[n-1];
        auto hull = convex_hull(arr);

        int u=-1, v=-1;
        for(int i=0;i<hull.size();i++){
            if(hull[i]==fst)
                u = i;
            if(hull[i]==lst)
                v = i;
        }

        for(auto p:hull){
            cout << p <<", ";
        }cout<<"\n";
        cout << u << " " << v <<"\n";

        ll answ = -1;
        if(u!=-1 && v!=-1){
            int siz = hull.size();
            for(int iter=0;iter<2;iter++){
                bool ok = true;
                ll tenta = 0;
                if((u+1)%siz==v){
                    ll peso = dist(hull[u],hull[v]);
                    if(peso > d*d) ok = false;
                    tenta = max(k,peso);    
                }
                else{
                    int base = u;
                    for(int i=(u+1)%siz;i!=v;i = (i+1)%siz){
                        cout << base <<" ";
                        int nxt = (i+1)%siz;
                        ll op1 = dist(hull[base],hull[i]) + dist(hull[i],hull[nxt]);
                        bool okOp1 = dist(hull[i],hull[nxt])<=d*d;

                        ll op2 = dist(hull[base],hull[nxt]);
                        bool okOp2 = op2<=d*d;

                        ll inc = -1;
                        
                        if(okOp2 || (inc==-1 || inc<op2))        
                            inc = op2;

                        if(okOp1 || (inc==-1 || inc<op1))        
                            inc = dist(hull[base],hull[i]), base = i;

                        if(inc==-1){ ok = false; break;}
                        tenta += inc;
                    }
                    cout <<"\n";
                }

                if(ok || (answ==-1 || answ<tenta))
                    answ = tenta;

                swap(u,v);
            }
        }
        else{
            answ = -1;
        }

        cout << "Case #" << ++caso << ": " << answ << "\n";
    }


    return 0;
}