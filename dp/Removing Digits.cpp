#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int t=i;
        for(int j=0;j<=6;j++){
            int t2=t%10;
            dp[i]=min(dp[i],dp[i-t2]+1);
            t/=10;
        }
    }
    cout<<dp[n];
    return 0;
}