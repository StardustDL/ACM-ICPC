/*
[ZJOI2008]泡泡堂BNB
分析：排序，贪心，两个指针扫，注意两个问题的关系 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,a[MAXN+3],b[MAXN+3];
int solve(int *a,int *b){
	int la=1,ra=n,lb=1,rb=n,ans=0;
	while(la<=ra&&lb<=rb){
		if(a[la]>b[lb])ans+=2,la++,lb++;
		else if(a[ra]>b[rb])ans+=2,ra--,rb--;
		else ans+=(a[la]==b[rb]),la++,rb--;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	printf("%d %d\n",solve(a,b),2*n-solve(b,a));
	return 0;
}

