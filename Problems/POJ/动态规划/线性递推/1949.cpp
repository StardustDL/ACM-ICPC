/*
Chores
题意：有n个任务，第i个任务需要时间xi来完成，并且第i个任务必须在它 “前面的” 某些任务完成之后才能开始。
	  给你任务信息，问你最短需要多少时间来完成任务。 
分析：“前面的”，知道这些任务已经是top排序好的了。dp[i] = 完成第i个任务时所需的最短的时间。dp[i]=max(dp[j])+xi，j是需要在它前面完成的任务的序号。
	  max(dp[i])就是答案。
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
int dp[10001],n,ans=0,j,k,t,p;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>j>>k;
        p=0;
        for(int s=1;s<=k;s++){
            cin>>t;
            p=max(p,dp[t]);
        }
        dp[i]=p+j;
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
