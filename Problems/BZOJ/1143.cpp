/*
[CTSC2008]����river
�������ȴ��ݱհ���Ȼ��ת��ѡ���ĵ㣬ʹ�û����ɴ���ö���ͼ���������(n-���ƥ��)�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
bitset<MAXN+3> mp[MAXN+3],vis;
int match[MAXN+3],n,m,cnt=0;
bool hungary(int x){
	for(int i=1;i<=n;i++){
		if(mp[x][i]&&vis[i]==0){
			vis[i]=1;
			if(match[i]==0||hungary(match[i])){
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int a,b,i=1;i<=m;i++)
		scanf("%d%d",&a,&b),mp[a][b]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[j][i])mp[j]|=mp[i];
	for(int i=1;i<=n;i++){
		vis=0;
		if(hungary(i))cnt++;
	}
	printf("%d\n",n-cnt);
	return 0;
}

