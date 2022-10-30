#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,lim;
    cin>>n>>lim;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    int mask=1<<n;
    vector<vector<int>>dp(mask,vector<int>(25));
    dp[0]={0,lim};
    vector<bool>ok(mask,0);
    sort(x.begin(),x.end());
    for(int i=1;i<mask;i++){
        dp[i]={25,0};
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                int c=dp[i^(1<<j)][0];
                int w=dp[i^(1<<j)][1];
                if(x[j]+w>lim){
                    c++;
                    w=x[j];
                }
                else w+=x[j];
                dp[i]=min(dp[i],{c,w});
            }

        }
    }
    cout<<dp[mask-1][0];
    return 0;
}