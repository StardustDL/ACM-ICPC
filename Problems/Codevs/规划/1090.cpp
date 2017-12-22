/*
�ӷֶ�����
������ע�⵽��������ǹ̶��ģ�����������DP����������������
	  ���仯���������뵽�ͱ�д��Ҫ��¼���Ž�͸���λ�ã�ע�����ʱҲ�еݹ顣 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=33;
int n,a[MAXN],opt[MAXN][MAXN],R[MAXN][MAXN],l,r;
int dfs(int l,int r){
	if(l>r)return 1;
	if(r-l+1==1)return a[l];
	if(opt[l][r]!=-1)return opt[l][r];
	int ans=0,p=0;
	for(int i=l;i<=r;i++){
		int cl=dfs(l,i-1),cr=dfs(i+1,r);
		if(cl*cr+a[i]>ans){
			ans=cl*cr+a[i];
			p=i;
		}
	}
	opt[l][r]=ans;R[l][r]=p;
	return opt[l][r];
}
void output(int l,int r){
	if(l>r)return;
	else if(l==r){
		cout<<l<<" ";return;
	}
	int k=R[l][r];
	cout<<k<<" ";
	output(l,k-1);
	output(k+1,r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(opt,-1,sizeof(opt));
	cout<<dfs(1,n)<<endl;
	output(1,n);
	return 0;
} 
