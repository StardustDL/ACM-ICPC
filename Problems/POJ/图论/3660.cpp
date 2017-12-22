/*
Cow Contest
���⣺��nֻ��ţ����n��������ʵ�������u��ʵ������v��ʵ�������ܴ�Ӯ����Ȼ�����m�ֹ�ϵ���������ȷ������������ţ������ 
������������ݱհ���ͳ��ÿ����ı�����ĵ�+����С�ĵ��������=n-1���������λ��ȷ��
	  �о�Ҳ����dfs������ֵ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
bool mp[MAXN+3][MAXN+3];
int n,m,x,y,ans=0;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]|=mp[i][k]&mp[k][j];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=mp[i][j]+mp[j][i];
		if(cnt==n-1)ans++;
	}
	printf("%d",ans);
	return 0;
}

