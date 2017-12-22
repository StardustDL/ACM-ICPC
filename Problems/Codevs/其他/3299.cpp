/*
有序数组合并求第K大问题
分析：直接上归并排序的合并过程，注意到了k就退出
	  其他方法：1.类似插入排序，二分得到插入点，统计个数
	  			2.二分一个序列中的一个点，使得这个点在另一个序列中的位置+在此序列中的位置=k 
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
