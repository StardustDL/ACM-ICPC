/*
��˹ŵ��
���⣺��һ���������ҳ���>=1������һ�Σ�ʹ����ƽ��������M
����������ǰ׺���ȼ򻯣�������Ϊ
	  (sum[j]-sum[i-1])/(j-i+1)>M
	  => M*(j-i+1)<sum[j]-sum[i-1]
	  => M*j-M*(i-1)<sum[j]-sum[i-1]
	  => M*j-sum[j]<M*(i-1)-sum[i-1]
	  ��A[i]=M*i-sum[i]���� 
	  => A[j]<A[i-1]
	  ע������i<j�����Ϊ��������� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000,MAXM=10000;
int n,m,a[MAXN+3],sum[MAXN+3],A[MAXN+3],t[MAXN+3];
long long ans=0;
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		A[i]=m*i-sum[i];
	}
}
void merge(int l,int mid,int r){
	int i=l,j=mid+1,cur=0;
	while(i<=mid&&j<=r){
		if(A[i]<=A[j]){
			t[cur++]=A[i++];
		}
		else{
			t[cur++]=A[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid)t[cur++]=A[i++];
	while(j<=r)t[cur++]=A[j++];
	for(int i=0;i<cur;i++)
		A[l+i]=t[i];
}
void merge_sort(int l,int r){
	if(l>=r)return;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m+1,r);
	merge(l,m,r);
} 
int main(){
	ios::sync_with_stdio(false);
	input();
	merge_sort(1,n);
	cout<<ans;
	return 0;
}
