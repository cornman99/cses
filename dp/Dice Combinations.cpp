#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<int>dp(n+1);
    int mod=1e9+7;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]+=i-j>=0?dp[i-j]:0;
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
    return 0;
}