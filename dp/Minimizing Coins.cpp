#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>dp(x+1,1e9);
    vector<int>coins(n);
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=0;
    for(int j=1;j<=x;++j){
        for(int i=0;i<n;i++){
            if(j>=coins[i])
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
    }
    if(dp[x]==1e9)cout<<-1;
    else cout<<dp[x];
    return 0;
}