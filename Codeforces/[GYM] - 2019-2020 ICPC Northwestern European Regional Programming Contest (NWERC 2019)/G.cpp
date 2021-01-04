#include<bits/stdc++.h>
#define ld long double
using namespace std;

vector<ld> arr, mult;
int n, k;
void precomp(){
    mult.assign(n+10,0);
    for(int i=2;n-i>=k-2;i++){
        mult[i] = k*(k-1);
        for(int j=0;j<i;j++){
            mult[i] *= 1.0/(n-j);
            if(j<i-2)
                mult[i] *= (n-k-j);
        }
            
        //cout << mult[i] << " ";
    }
}

ld teste(int x){
    int ptr = x;
    ld acm = 0, soma = 0;//, mult;
    for(int i=2;n-i>=k-2;i++){
        soma+=arr[ptr];
        /*mult = k*(k-1);
        for(int j=0;j<i;j++)
            mult *= 1.0/(n-j);
        for(int j=0;j<i-2;j++)
            mult *= (n-k-j);*/
        //cout << fixed << setprecision(6) << mult << " ";
        acm += soma*mult[i];
        ptr = ((ptr-1)%n+n)%n;
    }//cout<<'\n';
    return acm;
}

int main(){
    cin >> n >> k;
    arr.assign(n,0);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    precomp();
    for(int i=0;i<n;i++)
        if(k!=1)
            cout << fixed << setprecision(10) << teste(i) << ' ';
        else
            cout << fixed << setprecision(10) << 100*(1.0)/n << ' ';
    cout<<'\n';

    return 0;
}