#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    dp[0][1]=1;
    int mod=1e9+7;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='*')
                continue;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][n];
    return 0;
}