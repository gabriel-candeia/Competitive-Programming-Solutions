#include<bits/stdc++.h>
#define LOG 6
using namespace std;

vector<int> ord; 
int query(int a, int b, int c){
    int answ = 0;
    cout << a <<" " << b << " "<< c << endl;
    cin >> answ;
    return answ;
}

void insere(int x, int pos){
    ord.push_back(0);
    for(int i=ord.size()-1;i>pos;i--){
        ord[i] = ord[i-1];
    }
    ord[pos] = x;
}

int main(){
    int t, n, q, x;
    cin >> t >> n >> q;
    while(t--){
        ord = {1,2,3};
        x = query(1,2,3);
        swap(ord[x-1],ord[1]);

        for(int i=4;i<=n;i++){
            x = query(ord[0],i,ord[ord.size()-1]);
            if(x==ord[0]){
                insere(i,0);
            }
            else if(x==ord[ord.size()-1]){
                insere(i,ord.size());
            }
            else{
                int l=1, r=ord.size()-1, med, answ=-1;
                while(l<=r){
                    med = l + (r-l)/2;
                    if(med==0) med++;
                    x = query(ord[0],i,ord[med]);
                    if(x==i){
                        answ = med;
                        r = med-1;
                    }
                    else{
                        l = med+1;
                    }
                }
                insere(i,answ);
            }
        }

        int answ;
        for(int i=0;i<n;i++)
            cout << ord[i] << " ";
        cout<<endl;

        cin >> answ;
        /*if(answ==0){
            cout << "WA" << endl;
            return 0;
        }*/
    }
    return 0;
}