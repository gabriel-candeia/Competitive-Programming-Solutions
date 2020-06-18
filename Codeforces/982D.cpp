#include<bits/stdc++.h>
using namespace std;

class dsu{
    private:
        vector<int> parent, rank, size;
    public:
        dsu(int n){
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            size.assign(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        
        int find(int x){
            return ((parent[x]==x) ? x : parent[x] = find(parent[x]));
        }

        int uniao(int x, int y){
            x = find(x);
            y = find(y);
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y] = parent[x];
                    size[x]+=size[y];
                }
                else{
                    parent[x] = parent[y];
                    size[y]+=size[x];
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }

        int len(int x){
            return size[find(x)];
        }
};



int main(){
    int n, a;
    vector<pair<int,int>> arr;
    vector<int> color;

    cin >> n;
    color.assign(n+2,0);
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back({a,i+1});
    }

    sort(arr.begin(),arr.end());
    int cnt=0, max_cnt=0, l=0, max_l=0, answ = 1, answ_cnt=0;
    dsu alg(n+2);
    
    for(int i=0;i<n;i++){
        int j = arr[i].second;
        color[j] = arr[i].first;
        if(color[j-1]==0 && color[j+1]==0){
            cnt++;
        }
        else if(color[j-1]!=0 && color[j+1]!=0){
            cnt--;
        }
        if(color[j-1]!=0){
            alg.uniao(j-1,j);
        }
        if(color[j+1]!=0){
            alg.uniao(j+1,j);
        }

        l = alg.len(j);
        if(l>max_l){
            max_cnt = 1;
            max_l = l;
        }
        else if(l==max_l){
            max_cnt++;
        }

        if(cnt==max_cnt && cnt>answ_cnt){
            answ_cnt = cnt;
            answ = arr[i].first+1;
        }
    }

    cout << answ << '\n';

    return 0;
}