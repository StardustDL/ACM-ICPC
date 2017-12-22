/*
�������
����������+ (ans+=mid-i+1;)��ע�⼸��ϸ�ڣ�ans��int�ᱬ�� 
*/
#include<iostream>
using namespace std;
const int MAXN=100003;
int n,a[MAXN],t[MAXN];
long long ans=0;
void merge(int l,int mid,int r){
	int i=l,j=mid+1,cur=0;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){//ע������Ҫ�еȺţ���Ҳ�ܹؼ� 
			t[cur++]=a[i++];
		}
		else{
			t[cur++]=a[j++];
			ans+=mid-i+1;//���� 
		}
	}
	while(i<=mid)t[cur++]=a[i++];
	while(j<=r)t[cur++]=a[j++];
	for(int i=0;i<cur;i++)
		a[l+i]=t[i];
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
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	merge_sort(1,n);
	cout<<ans;
	return 0;
} 
