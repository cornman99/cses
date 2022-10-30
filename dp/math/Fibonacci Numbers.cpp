#include <iostream>
#include <vector>

using namespace std;
long long mod=1e9+7;
vector<vector<long long>>matrix_pow(vector<vector<long long>>&mat,long long  n);
vector<vector<long long>>mul(vector<vector<long long>>a,vector<vector<long long>>b);
int main(){
    long long  n;
    cin>>n;
    if(n<=1){
        cout<<n;
        return 0;
    }
    
    vector<vector<long long>>mat={{1,1},{1,0}};
    long long res=matrix_pow(mat,n-1)[0][0];
    cout<<res;
    return 0;
}
vector<vector<long long>>matrix_pow(vector<vector<long long>>&mat,long long  n){
    if(n==1)return mat;
    vector<vector<long long>>e={{1,0},{0,1}};
    for(long long i=1;i<=n;i<<=1){
        if(n&i){
            e=mul(e,mat);
        }
        mat=mul(mat,mat);
    }
    return e;
}
vector<vector<long long>>mul(vector<vector<long long>>a,vector<vector<long long>>b){
    vector<vector<long long>>res={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=mod;
            }
        }
    }
    return res;
}