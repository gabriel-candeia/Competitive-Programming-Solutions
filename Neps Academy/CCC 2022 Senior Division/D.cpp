#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e4+5)
using namespace std;

ll n, c;
ll freq[maxn], pref[maxn];

ll query(int l, int r){
    return pref[r] - ((l==0) ? 0 : pref[l-1]);
}

int main(){
    cin >> n >> c;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    if(c>maxn){
        ll answ = 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(arr[i]!=arr[j] && arr[j]!=arr[k] && arr[i]!=arr[k]){
                        ll a, b;
                        a = arr[i] + c/2 + 1;
                        b = arr[j] + c/2 + c%2 - 1;
                        answ += (arr[k]<=b && arr[k]>=a);
                    }
                }
            }
        }
        cout << answ <<"\n";
    }
    else{
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=0;i<2*c;i++){
            pref[i] = freq[i%c]; 
            if(i!=0) pref[i] += pref[i-1];
        }

        ll answ = 0;
        for(int i=0;i<c;i++){
            ll a; a = i + c/2 + 1;
            ll lim = i + c/2-1+c%2;
            //cout << a << " " << x <<"\n";

            for(int j=i+1;j<=min(lim,c-1);j++){
                int b;
                b = j + c/2 + c%2 - 1;
                if(a<=b){
                    answ += freq[i]*freq[j]*query(a,b);
                }
            }
        }

        cout << answ/2 << "\n";
    }
    
    return 0;
}