#include<bits/stdc++.h>
#define maxn int(5e5+5)
using namespace std;

const int block = sqrt(maxn)+1;
int n, q;

int cnt(vector<pair<int,int>> &arr, int v){
    int l=0, r=arr.size()-1, answ = -1, med;
    while(l<=r){
        med = l+(r-l)/2;
        if(arr[med].first>=v){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ+1;
}

int main(){
    cin >> n;
    vector<vector<pair<int,int>>> arr(sqrt(maxn)+1);

    for(int i=0,x;i<n;i++){
        cin >> x;
        arr[i/block].push_back({x,i});
    }
    
    for(auto &x:arr)
        sort(x.rbegin(),x.rend());

    cin >> q;
    int op, a, b, c;
    for(int i=0;i<q;i++){
        cin >> op;
        if(op==0){
            cin >> a >> b >> c;
            a--, b--;
            int l = a/block, r = b/block, acm = 0;
            for(auto p:arr[l])
                acm += (p.second>=a && p.first>=c && p.second<=b);
            for(int i=l+1;i<=r-1;i++)
                acm += cnt(arr[i],c);
            if(l!=r)
                for(auto p:arr[r])
                    acm += (p.second<=b && p.first>=c);
            cout << acm << '\n';
        }
        else{
            cin >> a >> b; a--;
            for(auto &p:arr[a/block]){
                if(p.second==a){
                    p.first = b;
                    break;
                }
            }
            sort(arr[a/block].rbegin(),arr[a/block].rend());
        }
    }   
    
    return 0;
}