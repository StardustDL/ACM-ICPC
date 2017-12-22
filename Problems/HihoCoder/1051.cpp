#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=100;
int T,N,M;
int a[MAXN+3];
inline int test(int l){
    int r=min(N,l+M-1);
    return (a[r+1]-1)-(a[l-1]+1)+1;
}
int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=1;i<=N;i++)cin>>a[i];
        a[N+1]=N+1;
        int ans=(N<=M)?100:0;
        for(int i=1;i<=N-M;i++)ans=max(ans,test(i));
        cout<<ans<<endl;
    }
    return 0;
}