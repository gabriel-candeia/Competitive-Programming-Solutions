#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ return (b ? gcd(b,a%b) : a);}

pair<int,int> formar(int a, int b){
    
    if(b==0){
        a = 1;
    }
    if(a==0){
        b = 1;
    }
    else{
        int temp = gcd(abs(a),abs(b));
        a /=temp;
        b /= temp;
    }

    if(b<0){
        a*=-1;
        b*=-1;
    }
    return {a,b};
}

int main(){
    int n, x0, y0, x1, y1;
    map<pair<int,int>,int> cnt;
    int answ=0;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x0 >> y0 >> x1 >> y1;
        cnt[formar(x1-x0,y1-y0)]++;
    }

    for(auto& z:cnt){
        pair<int,int> p = z.first, inv;
        if(p.first==0){
            inv = {1,0};
        }
        else if(p.second==0){
            inv = {0,1};
        }
        else if(p.first>0){
            inv = {-p.second,p.first};
        }
        else{
            inv = {p.second,-p.first};
        }
        answ += max(z.second,cnt[inv]);
        z.second = 0;
        cnt[inv] = 0;
    }

    cout << answ << '\n';

    return 0;
}

// (x0,y0) e (x1,y1), m-(y1-y0)/(x1-x0), -(x1-x0)/(y1-y0) -1/m
// 2/4 1/2