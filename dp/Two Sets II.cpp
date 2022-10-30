#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    int t=(n+1)*n/2;
    if(t&1){
        cout<<0;
        return 0;
    }
    t/=2;
    int mod=1e9+7;
    vector<int>dp(t+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=t;j>0;--j){
            dp[j]+=j>=i?dp[j-i]:0;
            dp[j]%=mod;
        }
    }
    long long ans=dp[t];
    ans *= 500000004;
    ans %= mod;
    cout << ans << "\n";

    return 0;
}

//除2等於乘2的inverse