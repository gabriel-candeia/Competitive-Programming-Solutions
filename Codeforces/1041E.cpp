#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    vector<int> marked, end;
    set<int> s;
    vector<pair<int,int>> edges;
    bool poss=true;

    cin >> n;
    marked.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        if((a!=n && b!=n) || (a==n && b==n)){
            poss = false;
        }
        marked[a]++;
        marked[b]++;
    }

    poss *= (marked[n]&&marked[n-1]);

    for(int i=1;i<n;i++){
        if(!marked[i]){
            s.insert(i);
        }
        else{
            int last = n;
            while(marked[i]>1 && s.size() && *(s.begin())<i){
                edges.push_back({last,*(s.begin())});
                last = *(s.begin());
                s.erase(s.begin());
                marked[i]--;
            }
            edges.push_back({last,i});
            if(marked[i]!=1){
                poss = false;
            }
        }
    }

    if(poss){
        cout << "YES\n";
        for(auto p:edges){
            cout << p.first << " " << p.second << '\n';
        }   
    }
    else{
        cout << "NO\n";
    }

    return 0;
}