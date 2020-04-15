#include<bits/stdc++.h>
using namespace std;

int men(vector<int>& v, int l, int r){
    int answer = l;
    for(int i=l;i<=r;i++){
        if(v[i]<v[answer]){
            answer = i;
        }
    }
    return answer;
}

void alg(vector<int>& v, int l, int r){
    if(r-l>1){
        int med = l +(r-l)/2;
        int mindex = men(v,l,r);

        if(mindex-1-l > r-(mindex+1)){
            for(int i=mindex;i<=r;i++){
                v[i] = v[mindex];
            }
            alg(v,l,mindex-1);
        }
        else if(mindex-1-l == r-(mindex+1)){
            int a = men(v,l,mindex-1), b = men(v,mindex+1,r);
            if(v[b]<v[a]){
                for(int i=mindex;i<=r;i++){
                    v[i] = v[mindex];
                }
                alg(v,l,mindex-1);
            }
            else{
                for(int i=l;i<=mindex;i++){
                    v[i] = v[mindex];
                }
                alg(v,mindex+1,r);    
                }
        }
        else{
            for(int i=l;i<=mindex;i++){
                v[i] = v[mindex];
            }
            alg(v,mindex+1,r);
        }
    }
}

int main(){
    int n, x;
    vector<int> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        arr.push_back(x);
    }
    alg(arr,0,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}