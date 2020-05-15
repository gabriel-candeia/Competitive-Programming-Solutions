    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
        int t, n, k;
        vector<int> a;
     
        cin >> t;
        while(t--){
            cin >> n >> k;
            a.assign(n+1,0);
            bool poss = false, thereIsZero = false, thereIsTwo=false;
            for(int i=1;i<=n;i++){
                cin >> a[i];
                a[i] = ((a[i]==k) ? 0 : ((a[i]>k) ?  1 : -1));
                if(i>1 && ((a[i]+a[i-1]==1) || (a[i]==0 && a[i-1]==0))){
                    poss = true;
                }
                if(a[i]==0){
                    thereIsZero = true;
                }
                if(i>1 && a[i]+a[i-1]==2){
                    thereIsTwo = true;
                }
            }
            if(n==1 && a[1]==0){
                poss = true;
            }
            if(thereIsZero){
                for(int i=1;i+2<=n;i++){
                    if((a[i]>=0 && a[i+2]>=0)){
                        poss = true;
                    }
                }
            }
            if(thereIsTwo && thereIsZero){
                poss = true;
            }
            /*if(!poss){
                vector<int> cnt0(n+1,0);
                map<int,int> last;
                last.clear();
                for(int i=1;i<=n;i++){
                    cnt0[i] = cnt0[i-1]+(a[i]==0);
                }
                
                int sum=a[1];
                last[0] = 0;
                if(sum!=0){
                    last[sum] = 1;
                }
                for(int i=2;i<=n;i++){
                    sum+=a[i];
                    //cout << i << " " << sum << endl;
                    if(sum==0){
                        if(cnt0[i]!=0){
                            poss = true;
                            break;
                        }
                    }
                    else if(last.find(sum)!=last.end() && (cnt0[i]-cnt0[last[sum]-1])!=0 && i-last[sum]>2){
                        cout << i << '\n';
                        poss = true;
                    }
                    if(last.find(sum)==last.end()){
                        last[sum] = i;
                    }
                }
            }*/
     
            if(poss){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
     
        return 0;
    }