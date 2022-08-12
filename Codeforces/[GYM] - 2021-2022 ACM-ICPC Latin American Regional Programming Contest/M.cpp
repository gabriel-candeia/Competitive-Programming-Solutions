#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;

int main(){
    int n;
    vector<array<ll,3>> arr;
    vector<ll> slack;

    cin >> n;
    for(int i=0;i<n;i++){
        int d, t;
        cin >> t >> d;
        arr.push_back({d,t,i+1});
    }

    slack.assign(n,0);
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        ll tempo = 0;
        sort(arr.begin()+i,arr.end());
        for(int j=0;j<n;j++){
            tempo += arr[j][1];
            slack[j] = arr[j][0]-tempo;
            if(slack[j]<0){
                assert(i==0);
                cout << "*\n";
                return 0;
            }
        }
        
        int best = i;
        ll menor = slack[i];
        for(int j=i+1;j<n;j++){
            if(arr[j][2]<arr[best][2])
                if(menor-arr[j][1] >= 0)
                    best = j;
            menor = min(menor,slack[j]);
        }

        while(best!=i){
            swap(arr[best],arr[best-1]);
            best--;
        }
        
    }   

    for(int i=0;i<n;i++){
        cout << arr[i][2] << " ";
    }
    cout<<"\n";

    return 0;
}