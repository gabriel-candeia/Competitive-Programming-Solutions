#include<bits/stdc++.h>
#define int long long
#define maxn int32_t(2e6+5)
using namespace std;

const int inf = 1e17;
int freq[maxn], answ[maxn], pai[maxn];

int32_t main(){
    int p;
    ifstream rd;
    rd.open("tests.in",std::ifstream::in); 
    rd >> p;

    while(p--){
        int t, n, ac=0;
        rd >> t >> n;

        for(int i=0;i<(1<<t);i++)
            freq[i] = answ[i] = pai[i] = 0;
        
        for(int i=0;i<n;i++){
            string s;
            rd >> s;
            bool zero = false;
            int acm = 0;
            //reverse(s.begin(),s.end());
            for(auto c:s){
                zero = zero || c=='0';
                acm = 2*acm + (c-'0');
            }
            if(!zero){
                ac++;
            }
            else{
                freq[acm]++;
            }
        }
        if(t==1){
            cout << n << "\n";
            cout << 1 <<"\n";
            continue;
        }

        if(ac==n){
            cout << t*ac <<"\n";
            for(int i=1;i<=t;i++)
                cout << i << " ";
            cout<<"\n";
            continue;
        }

        for(int i=0;i<t;i++){
            for(int msk=0;msk<(1<<t);msk++){
                freq[msk] = freq[msk];
                if((msk&(1<<i))==0 && (msk^(1<<i))<maxn){
                    freq[msk] += freq[msk^(1<<i)];
                }
            }
        }
        
        int limite = (1<<t)-1;
        //cerr <<">> " <<limite << " " <<answ[limite] << "\n";
        for(int msk=1;msk<=limite;msk++)
            answ[msk] = inf, pai[msk] = 0;
        //cerr <<">> " <<limite << " " <<answ[limite] << "\n";
        answ[0] = 0;

        for(int msk=1;msk<=limite;msk++){            
            for(int i=0;i<t;i++){
                if((msk&(1<<i))){
                    int qtd = __builtin_popcountll((msk^(1<<i)))+1;
                    int cmp = answ[msk^(1<<i)]+qtd*(freq[(msk^(1<<i))]-freq[msk]);
                    /*if(msk==1){
                        cout << (msk^(1<<i)) << " " << msk << " "<<qtd << " "<<freq[0] << " "<<freq[1] << "\n";
                        cout << answ[msk] << " " << cmp << " " << qtd <<"\n";
                        cout<<"\n";
                    }*/
                    
                    if(cmp<answ[msk]){
                        answ[msk] = cmp;
                        pai[msk] = i;
                    }
                }
            }
        }
        //cerr <<">> " <<limite << " " <<answ[limite] << "\n";

        int iter = 0;
        cout << answ[limite] + t*ac << '\n';

        vector<int> aux;
        for(int msk=limite,iter=t;iter;iter--){
            //cout << msk << " " << pai[msk] <<"\n";
            aux.push_back(t-pai[msk]);
            //cout << t-pai[msk] << " ";
            msk = msk^(1<<pai[msk]);
        }
        reverse(aux.begin(),aux.end());
        for(auto x:aux)
            cout << x <<" ";
        cout<<"\n";

    }


    return 0;
}