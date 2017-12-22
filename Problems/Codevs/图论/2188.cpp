/*
最长上升子序列
分析：注意n较大，要用nlogn的方法，好像还可以树状数组，要学习一下
	  LIS的nlogn方法（本质是决策单调性，这里可以不维护决策表）：维护一个栈，栈中元素递增
	  对每个要加入的元素，若比栈顶大，放到栈顶上方
	  否则，将栈中比这个数大的第一个数替换为这个数，这样整个序列的大小没变，但潜力更大了
	  注意此方法不能输出方案，栈中所存的元素可能并不满足顺序先后，只满足个数是正确的
	  另外如何一定选一个数呢？
	  只要将他之前比它大的数都删掉，他之后比它小的数都删掉即可 
*/
#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
const int MAXN=200000;
int n,k,sta[MAXN+3],a[MAXN+3],top=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<k;i++)if(a[i]>a[k])a[i]=-1;
	for(int i=k+1;i<=n;i++)if(a[i]<a[k])a[i]=-1;
	sta[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==-1)continue;
		if(a[i]>sta[top]){
			sta[++top]=a[i];continue;
		}
		int p=lower_bound(sta+1,sta+top+1,a[i])-sta;
		sta[p]=a[i];
	}
	cout<<top;
	return 0;
}
