#include <iostream>
#include <vector>

using namespace std;
int main(){
    int t;
    cin>>t;

    vector<vector<long long>>dp(1e6+1,vector<long long>(2));
    dp[1][0]=1;
    dp[1][1]=1;
    long long mod=1e9+7;
    for(int i=2;i<=1e6;i++){

        dp[i][0]+=dp[i-1][0]*4+dp[i-1][1];
        dp[i][0]%=mod;


        dp[i][1]+=dp[i-1][1]*2+dp[i-1][0];
        dp[i][1]%=mod;

    }

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][0])%mod<<endl;
    }
    return 0;
}