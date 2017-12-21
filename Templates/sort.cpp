/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
void quick_sort(int l,int r,int *a){
	if(l>=r)return;
	int h=l,t=r,key=a[h];
	while(h<t){
		while(h<t&&a[t]>=key)t--;
		a[h]=a[t];
		while(h<t&&a[h]<=key)h++;
		a[t]=a[h];
	}
	a[h]=key;
	quick_sort(l,h,a);
	quick_sort(h+1,r,a);
}
void merge_sort(int l,int r,int *a){
	static int temp[MAXN+3]; 
	if(l>=r)return;
	int mid=(l+r)>>1;
	merge_sort(l,mid,a);
	merge_sort(mid+1,r,a);
	int ll=l,rr=mid+1,cur=l;
	while(ll<=mid&&rr<=r){
		if(a[ll]<=a[rr])temp[cur++]=a[ll++];
		else{
			//pair+=mid-ll+1;//逆序对 
			temp[cur++]=a[rr++];
		}
	}
	while(ll<=mid)temp[cur++]=a[ll++];
	while(rr<=r)temp[cur++]=a[rr++];
	for(int i=l;i<=r;i++)a[i]=temp[i];
}
void radix_sort(int n,int mx_radix,int *a){
	static int cnt[10+3],temp[MAXN+3];
	int rad=1;
	for(int i=1;i<=mx_radix;i++){
		for(int j=0;j<10;j++)cnt[j]=0;
		for(int j=0;j<n;j++)
			cnt[(a[j]/rad)%10]++;
		for(int j=1;j<10;j++)cnt[j]+=cnt[j-1];
		for(int j=n-1;j>=0;j--){
			int k=(a[j]/rad)%10;
			temp[--cnt[k]]=a[j];
		}
		for(int j=0;j<n;j++)a[j]=temp[j];
		rad*=10;
	}
}
int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	radix_sort(n,5,a+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" "; 
	return 0;
}

