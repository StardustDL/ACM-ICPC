/*
��ӹ֮��
���������ݲ�̫�󣬲�Ȼ��Ҫ�������ˣ������߶���+Ȩֵ�߶�������¼һ����Χ�����ĳ��ִ�����
	  ֻ���������k�󼴿ɣ��������ƿ��ŵ�˼�� 
*/ 
#include<iostream>
#include<cstring> 
using namespace std;
const int MAXN=1000;
int ans[MAXN+3][MAXN+3],a[MAXN+3],d[MAXN+3],n;
int P(int l,int r){
	int k=a[l],i=l,j=r;
	while(i<j){
		while(a[j]>k&&j>i)j--;
		a[i]=a[j];
		while(a[i]<k&&j>i)i++;
		a[j]=a[i];
	}
	a[i]=k;
	return i;
}
int geti(int l,int r,int ind){
	if(l==r)return a[l];
	int p=P(l,r),len=p-l+1;
	if(ind==len)return a[l+ind-1];
	else if(ind<len)return geti(l,l+len-2,ind);
	else return geti(l+len,r,ind-len); 
}
int main(){
	int q,l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	memcpy(d,a,sizeof(a));
	while(q-->0){
		cin>>l>>r;
		cout<<geti(l,r,(r-l+2)>>1)<<endl;
		memcpy(a,d,sizeof(d));
	}
	return 0;
}
