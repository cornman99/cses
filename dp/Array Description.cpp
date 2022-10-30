#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    long long mod=1e9+7;
    vector<vector<long long>>dp(n,vector<long long>(m+1,0));
    if(x[0]==0){
        for(int j=1;j<=m;j++)dp[0][j]=1;
    }
    else dp[0][x[0]]=1;
    for(int i=1;i<n;i++){
        if(x[i]!=0){
            dp[i][x[i]]=dp[i-1][x[i]];
            dp[i][x[i]]+=x[i]>1?dp[i-1][x[i]-1]:0;
            dp[i][x[i]]+=x[i]<m?dp[i-1][x[i]+1]:0;
            dp[i][x[i]]%=mod;
            continue;
        }
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]+=j>1?dp[i-1][j-1]:0;
            dp[i][j]+=j<m?dp[i-1][j+1]:0;
            dp[i][j]%=mod;
        }
    }
    int t=(accumulate(dp[n-1].begin(),dp[n-1].end(),0LL)%mod);
    cout<<t;
    return 0;
}