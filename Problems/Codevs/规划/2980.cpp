/*
买帽子
分析：此题可以认为是自己和自己匹配的最长公共子序列，字典序要用strcmp，不能直接比较字符数组 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
typedef char str[503];
int n,l[MAXN+3],r[MAXN+3],opt[503][503];
str strs[MAXN+3];
int lcs(str a){
	memset(opt,0,sizeof(opt));
	int len=strlen(a);
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++){
			//cout<<a[i-1]<<a[len-j]<<endl;
			if(a[i-1]==a[len-j]){
				opt[i][j]=opt[i-1][j-1]+1;
			}
			else opt[i][j]=max(opt[i-1][j],opt[i][j-1]);
		}
	}
	return opt[len][len];
} 
bool cmp(const int i,const int j){
	return l[i]>l[j]||(l[i]==l[j]&&strcmp(strs[i],strs[j])<0);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>strs[i];r[i]=i;l[i]=lcs(strs[i]);
		//cout<<l[i]<<endl;
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<strs[r[i]]<<endl;
	return 0;
}
