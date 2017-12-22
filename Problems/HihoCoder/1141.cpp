#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int a[MAXN+3],n;
long long ans=0;
void merge_sort(int l,int r){
	static int tmp[MAXN+3];
	if(l>=r)return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int p1=l,p2=mid+1,p=l;
	while(p1<=mid&&p2<=r){
		if(a[p1]<=a[p2]){
			tmp[p++]=a[p1++];
		}
		else{
			ans+=mid-p1+1;
			tmp[p++]=a[p2++];
		}
	}
	while(p1<=mid)tmp[p++]=a[p1++];
	while(p2<=r)tmp[p++]=a[p2++];
	for(int i=l;i<=r;i++)a[i]=tmp[i];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	merge_sort(1,n);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	printf("%lld\n",ans);
	return 0;
}