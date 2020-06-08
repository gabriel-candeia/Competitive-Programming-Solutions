#include<bits/stdc++.h>
using namespace std;

int select(int a, int k, int m, int last){
    if(a<=(a+k)%m){
        if(last>(a+k)%m){
            return (a+k)%m;
        }
        else if(last>=a){
            return last;
        }
        else{
            return a;
        }
    }
    else{ 
        if((a+k)%m>=last || last>=a){
            return last;
        }
        else if(last<a){
           return a;
        }
    }
}

bool cond(vector<int>& a, int med, int m){
    int last, next;

    if(a[0]<=(a[0]+med)%m){
        last = a[0];
    }
    else{
        last = 0;
    }

    for(int i=1;i<a.size();i++){
        next = select(a[i],med,m,last);
        //cout << last << " " << next << '\n';
        if(next>=last){
            last = next;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    vector<int> a;

    cin >> n >> m;

    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int l=0, r=m-1, med, answ=m;
    while(l<=r){
        med = l + (r-l)/2;
        if(cond(a,med,m)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << answ << '\n';
    return 0;
}