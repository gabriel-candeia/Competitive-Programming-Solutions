#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int w, h, n;
vector<array<int,3>> pts;

bool naborda(int a, int b){
    return (a==0 || a==w || b==0 || b==h);

}

int grupo(int a, int b){
    return ((b==h) ? 1 : ((a==w) ? 2 : ((b==0) ? 3 : 4)));
}

bool cmp(const array<int,3>& a, const array<int,3>& b){
    int ga = grupo(a[0],a[1]), gb = grupo(b[0],b[1]);

    if(ga!=gb){
        return ga < gb;
    }
    else if(ga==1){
        return a[0] < b[0];
    }
    else if(ga==2){
        return a[1] > b[1];
    }
    else if(ga==3){
        return a[0] > b[0];
    }
    else{
        return a[1] < b[1];
    }
}

int main(){
    fastio();
    cin >> w >> h >> n;

    for(int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(naborda(a,b) && naborda(c,d)){
            pts.push_back({a,b,i});
            pts.push_back({c,d,i});
        }
    }

    sort(pts.begin(),pts.end(),cmp);
    stack<int> st;

    for(auto pt:pts){
        if(st.size()==0 || st.top()!=pt[2]){
            st.push(pt[2]);
        }
        else{
            st.pop();
        }
    }

    cout << ((st.size()==0) ? "Y" : "N") <<"\n";

    return 0;
}