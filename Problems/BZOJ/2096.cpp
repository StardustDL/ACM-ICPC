/*
[Poi2010]Pilots
������������������ ά��������С 
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
			if(q1[l1]<q2[l2])t=q1[l1]+1,l1++;//ע������ǲ��Ϸ���λ��+1������һ���ܵõ�һ���Ϸ������ 
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

