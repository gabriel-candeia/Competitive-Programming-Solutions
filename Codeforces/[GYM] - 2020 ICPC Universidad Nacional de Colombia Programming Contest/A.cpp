#include<bits/stdc++.h>
#define ld double
#define ll long long
using namespace std;

ld euclidian_distance(pair<ld,ld> p1, pair<ld,ld> p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int cmp(ld a, ld b){
    const ld eps = 1e-7;
    return (b-a>eps) ? -1 : (b-a<-eps) ? 1 : 0;
}

ld segment_point_distance(pair<ld,ld> a, pair<ld,ld> b, pair<ld,ld> x){
    pair<ld,ld> target;
    if(cmp(a.first,b.first)==0){
        target = {a.first,x.second};
    }
    else{
        ld r, r1;
        r = (a.second-b.second)/(a.first-b.first);
        r1 = -1/r;
        ld encontro =  (x.second-r1*x.first-a.second+r*a.first)/(r-r1);
        target = {encontro,r1*encontro-r1*x.first+x.second};
    }
    if(cmp(min(a.first,b.first),target.first)==-1 && cmp(target.first,max(b.first,a.first))==-1)
        return euclidian_distance(x,target);
    return min(euclidian_distance(x,a),euclidian_distance(x,b));
}

int main(){
    vector<pair<ld,ld>> p[2];
    vector<ld> dist, dx, dy, vx, vy;
    ld t, dvx, dvy;
    ll x, y;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> x >> y;
            p[i].push_back({x,y});
        }
        dist.push_back(euclidian_distance(p[i][0],p[i][1]));
    }
    
    if(dist[0]>dist[1]){
        for(int i=0;i<1;i++){
            for(int j=0;j<2;j++){
                swap(p[i][j].first,p[(i+1)][j].first);
                swap(p[i][j].second,p[(i+1)][j].second);
            }
            swap(dist[i],dist[i+1]);
        }   
    }

    for(int i=0;i<2;i++){
        dx.push_back(p[i][1].first-p[i][0].first);
        dy.push_back(p[i][1].second-p[i][0].second);
        vx.push_back(dx[i]/(dist[i]));
        vy.push_back(dy[i]/(dist[i]));
    }
    dvx = vx[0]-vx[1]; dvy = vy[0]-vy[1];

    t = (-(p[0][0].first-p[1][0].first)*dvx -(p[0][0].second-p[1][0].second)*dvy)/(dvx*dvx+dvy*dvy);
    ld answ=1ll<<40;
    //cout << vy[0] << " "<<vy[1] << '\n';
    if(cmp(dvx,0)==0 && cmp(dvy,0)==0){
        pair<ld,ld> a = {p[1][0].first+dist[0]*vx[1],p[1][0].second+dist[0]*vy[1]};
        answ = min(answ,segment_point_distance(a,p[1][1],p[0][1]));
    }
    else if(cmp(t,dist[0])==-1 && cmp(t,dist[1])==-1){
        //cout << p[0][0].first <<"+"<< vx[0] << "*k, " << p[0][0].second<<"+"<< vy[0] <<  "*k" << '\n';
        //cout << p[1][0].first <<"+"<< vx[1] << "*k, " << p[1][0].second<<"+"<< vy[1] <<  "*k" << '\n';
        answ = euclidian_distance({p[0][0].first + vx[0]*t,p[0][0].second + vy[0]*t},{p[1][0].first + vx[1]*t,p[1][0].second + vy[1]*t});
        pair<ld,ld> a = {p[1][0].first+dist[0]*vx[1],p[1][0].second+dist[0]*vy[1]};
        //cout << a.first << " " << a.second << '\n';
        //cout << p[1][1].first << " " << p[1][1].second << '\n';
        answ = min(answ,segment_point_distance(a,p[1][1],p[0][1]));
    }
    else{
        pair<ld,ld> a = {p[1][0].first+dist[0]*vx[1],p[1][0].second+dist[0]*vy[1]};
        //cout << a.first << " " << a.second << '\n';
        //cout << p[1][1].first << " " << p[1][1].second << '\n';
        answ = min(answ,segment_point_distance(a,p[1][1],p[0][1]));
    }
    cout << fixed << setprecision(10) << answ << '\n';
    return 0;
}