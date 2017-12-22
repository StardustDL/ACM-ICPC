/*
超级书架
分析：显然贪心，排个序即可，但有没有O(n)的方法呢？ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=20000,INF=0x3f3f3f3f;
int a[MAXN+3],n,b;
int cl(int *a,int l,int r){
	if(l>=r)return l;
	int key=a[l],i=l,j=r;
	while(i<j){
		while((j>i)&&(a[j]>=key))j--;
		a[i]=a[j];
		while((i<j)&&(a[i]<=key))i++;
		a[j]=a[i];
	}
	a[i]=key;
	return i;
}
int solve(int *a,int l,int r,int sum){
	int ans=-1;
	while(l<r){
		int q=cl(a,l,r);
		cout<<q<<endl;
		int t=0;
		for(int i=q+1;i<=r;i++){
			t+=a[i];
		}
		//cout<<t<<endl;
		if(t==sum)return r-q+1;
		else if(t<sum)return ans;
		else ans=r-q+1,l=q+1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n,sum=0;i>=1;i--){
		if((sum+=a[i])>=b){
			printf("%d\n",n-i+1);
			break;
		}
	}
	//printf("%d\n",solve(a,1,n,b));
	return 0;
}

