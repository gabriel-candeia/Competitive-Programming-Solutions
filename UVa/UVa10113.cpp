#include<bits/stdc++.h>
using namespace std;

int acmX, acmY;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

bool alg(vector<vector<pair<int,pair<int,int>>>>& adj, int u, int v, vector<bool>& visited){
    if(u==v){
        acmX = 1; acmY = 1;
        return true;
    }
    visited[u] = true;
    for(auto i: adj[u]){
        if(!visited[i.first] && alg(adj,i.first,v,visited)){
            acmX*=i.second.first;
            acmY*=i.second.second;
            int acm = gcd(acmX,acmY);
            acmX/=acm;
            acmY/=acm;
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<pair<int,pair<int,int>>>> adj; adj.assign(100,vector<pair<int,pair<int,int>>>());
    vector<bool> visited;
    map<string, int> f;
    string input;
    char s1[100], s2[100];
    int q1, q2, n=0, x, y, acm;

    while(getline(cin, input) && input!="."){
        if(sscanf(input.c_str(),"! %d %s = %d %s",&q1,s1,&q2,s2)){
            if(!f[s1]){
                f[s1] = ++n;
            }
            if(!f[s2]){
                f[s2] = ++n;
            }
            x = f[s1]; y = f[s2];
            acm = gcd(q1,q2);
            q1 = q1/acm;
            q2 = q2/acm;
            adj[x].push_back(make_pair(y,make_pair(q1,q2)));
            adj[y].push_back(make_pair(x,make_pair(q2,q1)));
        }
        else if(sscanf(input.c_str(),"? %s = %s",s1,s2)){
            visited.assign(n+3,false);
            acmX = -1; acmY = -1;
            alg(adj,f[s1],f[s2],visited);
            if(acmX!=-1){
                printf("%d %s = %d %s\n",acmX, s1, acmY, s2);
            }
            else{
                printf("? %s = ? %s\n",s1, s2);
            }
    }
        }

    return 0;
}