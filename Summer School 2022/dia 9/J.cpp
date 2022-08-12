#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int main(){
    ifstream rd;
    int t;
    rd.open("clar.in",std::ifstream::in); 
    rd >> t;
    while(t--){
        int m, n, k;
        rd >> m >> n >> k;
        
        vector<vector<int>> arr(m+n+10,vector<int>());
        vector<int> used(k+1,0), waiting(k+1,0);
        for(int i=0;i<n;i++){
            int t, k;
            rd >> t >> k;
            arr[t].push_back(k);
        }

        /*for(int i=1;i<=m;i++){
            for(auto x:arr[i]){
                cout << x << " ";
            }
            cout<<"\n";
        }*/
        //cout << arr.size() <<"\n";
        int apagados=0, pessoa2 = 0, dia;
        set<int> options;
        for(dia=1;apagados!=n;dia++){
            bool flag = false;
            for(auto x:arr[dia]){
                if(!used[x] && options.find(x)!=options.end()){
                    used[x] = 1;
                    pessoa2+=waiting[x]-1;
                    options.erase(options.find(x));
                    flag = true;
                    apagados++;
                    break;
                }
            }

            if(flag==false){
                for(auto x:options){
                    if(waiting[x]){
                        used[x] = 1;
                        pessoa2+=waiting[x]-1;
                        options.erase(options.find(x));
                        flag = true;
                        apagados++;
                        break;
                    }
                }
            }

            if(flag==false && (options.size() || pessoa2))
                n--;
            //cout << apagados << " " << n <<" "<<pessoa2 << " "<< options.size() <<  "\n";

            if(apagados>=n){
                dia--;
                break;
            }

            for(auto x:arr[dia]){
                if(used[x]){
                    pessoa2++;
                }
                else{
                    options.insert(x);
                    waiting[x]++;
                }
            }
            if(pessoa2){
                pessoa2--;
                apagados++;
            }

            if(apagados>=n){
                break;
            }
    
        }

        cout << dia <<"\n";
    }



    return 0;
}