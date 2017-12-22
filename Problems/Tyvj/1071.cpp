/*
LCIS 
分析：f[i]代表到a串的第i个数为止, 包括a[i]在内的并以a[i]为结尾的，与整个b串的最长公共上升子序列，
	  其中max记录在a[i]>b[j]时a串的前i位与b串的前j位的LCIS，以便于下一个搜索到a[i]=b[j]时使用，
	  此时使用的max时j之前的LCIS，把f[j]更新为max+1，这里的上一次求出的max为什么在a[i]=b[j]时也能使用呢？
	  因为他们是相对于同一个a[i]来说的。因为a[i]<b[j]时，包括a[i]在内的LCIS不可能形成，所以不需要处理。 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3000;
int f[MAXN+3],n;
int a[MAXN+3],b[MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1,mx=0;j<=n;j++){
			if(a[i]>b[j])mx=max(mx,f[j]);
			else if(a[i]==b[j])f[j]=max(f[j],mx+1);
		}
	}
	for(int i=1;i<=n;i++)f[0]=max(f[i],f[0]);
	cout<<f[0]<<endl;
	return 0;
}
