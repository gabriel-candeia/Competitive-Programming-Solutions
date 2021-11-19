#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    
    while(t--){
        int n, m, k;
        vector<int> a;
        cin >> n >> k >> m;
        a.assign(n,0);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<int> h(n,0), ing(k+1,0), answ(n,0);
        int quebrado = (m%(2*n)), ciclos = m/(2*n);
        
        for(int t=0;t<2*n;t++){
            int pessoa = t%n;
            if(ing[a[pessoa]]){
                ing[a[pessoa]]--;
                h[pessoa]++;
                if(t<quebrado) 
                    answ[pessoa]++;
            }
            else{
                ing[a[pessoa]]++;
            }
        }

        for(int i=0;i<n-1;i++){
            cout << h[i]*ciclos + answ[i] << " ";
        }
        cout << h[n-1]*ciclos + answ[n-1] << "\n";
    }
    
    return 0;
}