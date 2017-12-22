/*
[Poi2010]Pilots
分析：两个单调队列 维护最大和最小 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3000000;
int K,n,ans=1;
int a[MAXN+3],q1[MAXN+3],q2[MAXN+3];
void solve(){
    int l1=1,l2=1,r1=0,r2=0,t=1;
    for(int i=1;i<=n;i++){
		while(l1<=r1&&a[i]>=a[q1[r1]])r1--;
        while(l2<=r2&&a[i]<=a[q2[r2]])r2--;
        q1[++r1]=i;q2[++r2]=i;
		while(a[q1[l1]]-a[q2[l2]]>K)
			if(q1[l1]<q2[l2])t=q1[l1]+1,l1++;//注意这里，是不合法的位置+1，这样一定能得到一个合法的最长的 
			else t=q2[l2]+1,l2++;
		ans=max(ans,i-t+1);
	}
}
int main(){
    scanf("%d%d",&K,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
    solve();
    printf("%d\n",ans);
    return 0;
}

