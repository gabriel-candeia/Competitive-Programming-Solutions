#include<bits/stdc++.h>
#define N 100000 + 5
using namespace std;

long long int n, c, T;
long long int mint, maxt, answer;
long long int arr[N];

bool daPraPartcionar(int t){
    long long int soma=0, partes=1;
    for(int i=0;i<n;i++){
        if(soma+arr[i]<= t*T){
            soma+=arr[i];
        }
        else{
            partes++;
            soma = arr[i];
        }
    }
    return partes<=c;
}


int main(){
    

    cin >> n >> c >> T;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    long long int soma=0;
    for(int i=0;i<n;i++){
        mint = max(mint,arr[i]);
        maxt += arr[i];
    }
    mint = mint/(T*1.0);
    maxt += 1000;
    /*
    for(int i=mint;i<=maxt;i++){
        if(daPraPartcionar(i)){
            answer = i;
            break;
        }
    }*/

    long long int l=mint, r=maxt, med;
    bool flag;
    while(l<r){
        med = l+ (r-l)/2;
        if(daPraPartcionar(med)){
            r = med;
        }
        else{
            l = med+1;
        }
    }
    
    if(daPraPartcionar(med-1)){
        answer = med-1;
    }
    else if(daPraPartcionar(med)){
        answer = med;
    }
    else if(daPraPartcionar(med+1)){
        answer = med+1;
    }

    cout << answer << '\n';

    return 0;
}
