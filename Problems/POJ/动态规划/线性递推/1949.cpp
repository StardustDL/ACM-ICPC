/*
Chores
���⣺��n�����񣬵�i��������Ҫʱ��xi����ɣ����ҵ�i������������� ��ǰ��ġ� ĳЩ�������֮����ܿ�ʼ��
	  ����������Ϣ�����������Ҫ����ʱ����������� 
��������ǰ��ġ���֪����Щ�����Ѿ���top����õ��ˡ�dp[i] = ��ɵ�i������ʱ�������̵�ʱ�䡣dp[i]=max(dp[j])+xi��j����Ҫ����ǰ����ɵ��������š�
	  max(dp[i])���Ǵ𰸡�
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
