/*
最大全0子矩阵
分析：经典问题：
	  可以一行一行的求。
	  比如第一行 1 1 0 1 1 1 0 1
	  那么我们求和b[]={1,1,0,1,1,1,0,1}
	  比如第二行为1 1 0 0 0 0 1 1
	  那么我们继续求和b[]={2,2,0,0,0,0,0,2}......
	  这样得到了了一个直方图，题目转化为不同高度的直方图，求这个直方图最大的矩形面积。 
	  比如直方图高度为 1 2 3 2，那么最大面积是？
	  当以第一个为基准的时候高度为1，后面的大于都可以组成矩形，所以面积为4.当以第二个为基准，那么只有后三个可以，面积为6.同理。。。。最大面积为6.
	  这里也是一样，当求得了第一行到当前行的高度后，可以求出目前的最大面积。
	  我们设立两个数组l[],r[]分别表示以b[j]为基准时候的左右边界，那么以b[j]为基准的面积就变成了b[j]*(r[j]-l[j]+1)，然后枚举出最大的即可。 
	  如何快速求出l和r，见代码 
*/
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=2000;
bitset<MAXN+3> mp[MAXN+3];
int n,h[MAXN+3],l[MAXN+3],r[MAXN+3];
void input(){
	cin>>n;
	int t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t;
			mp[i][j]=t;
		}
	}
}
int dp(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(!mp[i][j])h[j]++;else h[j]=0;
		for(int j=1;j<=n;j++){//快速求出l，类似于递推，注意j=1..n 
			l[j]=j;
			while(l[j]-1>=1&&h[j]<=h[l[j]-1])l[j]=l[l[j]-1];
		}
		for(int j=n;j>=1;j--){//快速求出r，注意j=n..1 
			r[j]=j;
			while(r[j]+1<=n&&h[j]<=h[r[j]+1])r[j]=r[r[j]+1];
		}
		for(int j=1;j<=n;j++)
			ans=max(ans,h[j]*(r[j]-l[j]+1));
	}
	return ans;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
