/*
��������ϲ����K������
������ֱ���Ϲ鲢����ĺϲ����̣�ע�⵽��k���˳�
	  ����������1.���Ʋ������򣬶��ֵõ�����㣬ͳ�Ƹ���
	  			2.����һ�������е�һ���㣬ʹ�����������һ�������е�λ��+�ڴ������е�λ��=k 
*/ 
#include<iostream>
using namespace std;
const int MAXN=1000000;
int a[MAXN+3],b[MAXN+3],n,m,k,T,l=1,r=1;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	while(l<=n&&r<=m&&--k>=0)
		T=(a[l]<b[r])?a[l++]:b[r++];
	while(l<=n&&--k>=0)T=a[l++];
	while(r<=m&&--k>=0)T=b[r++];
	cout<<T;
	return 0;
}
