#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso=0, n, c ;

    cin >> t;
    while(t--){
        cin >> n >> c;
        int mn=n-1, mx=0;
        for(int i=2;i<=n;i++)
            mx+=i;
        cout << "Case #" << ++caso << ": ";
        if(c<mn || mx<c){
            cout << "IMPOSSIBLE\n";
        }
        else{
            vector<int> p(n,0);
            for(int i=0;i<n;i++)
                p[i] = i+1;
            int l = 0, r = n-1, ptr=0, curr = mn, inc = 1;
            for(int iter=0;iter<c-curr;iter++){
                if(inc==1)
                    for(int i=ptr;i>=l;i--)
                        swap(p[i],p[i+1]);
                else
                    for(int i=ptr;i<=r;i++)
                        swap(p[i],p[i-1]);
                ptr+=inc;
                if(inc==1 && ptr==r){
                    inc = -1;
                    r--;
                    ptr--;
                }
                if(inc==-1 && ptr==l){
                    inc = 1;
                    l++;
                    ptr++;
                }
            }
            for(int i=0;i<n;i++)
                cout << p[i] << " ";
            cout<<'\n';
        }
    }
    return 0;
}