#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn int(1e5)+10

typedef pair<ll,ll> ii;
ll n;
ii v[maxn];
bool visited[maxn];
double d[maxn];

double dist(ii a, ii b){
    return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}

bool menor(ii a, ii b, ii c){
    return ((a.first-b.first)*(c.first-b.first) + (a.second-b.second)*(c.second-b.second))>=0;
}

int tan(ii b, ii c){
    ii aux = (b.first-c.first,b.second-c.second);
    return ((aux.second==0) ? 0 : (aux.second*aux.first>0 ? 1 : -1));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> v[i].first >> v[i].second;

    for(int i = 0; i < n; i++)
        d[i] = dist(v[i],v[(i+1)%n]);

    for(int i=0;i<n;i++){
        int l=1, r=n-1, med, answ=i;
        while(l<=r){
            med = l + (r-l)/2;
            menor(v[i],v[(i+1)%n],v[(i+med)%n]);
        }
    }

    for(int i=0;i<n;i++){
        cout << fixed << setprecision(10) << d[i] <<"\n";
    }
    
    return 0;
}