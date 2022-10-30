#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp;
    vector<int>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        auto p=lower_bound(dp.begin(),dp.end(),x[i]);
        if(p==dp.end())dp.push_back(x[i]);
        else *p=x[i];
    }
    cout<<dp.size();
    return 0;
}