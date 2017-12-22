/*
[JSOI2007]�ı�������
���⣺�������������͹̶������³���M��������ٰ�������һ�����ʵĿ�������������
������ע�������٣���ô����ת��ans=26^m-�������κε��ʵ����¸���
	  �������κε��ʣ���ƥ�䲻���κ�һ������ô��AC�Զ�������ǳɹ�ƥ���״̬��������DP��ÿ��ֻ���߲������ƥ�����ĸ��
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=60,MAXM=100,INF=0x3f3f3f3f,MOD=10007;
int ch[MAXN*MAXM+3][26],opt[100+3][MAXN*MAXM+3],tot=0,fail[MAXN*MAXM+3],val[MAXN*MAXM+3];
void insert(char *s){
	int l=strlen(s),cur=0;
	for(int i=0;i<l;i++){
		int t=s[i]-'A';
		if(ch[cur][t]==0)ch[cur][t]=++tot;
		cur=ch[cur][t];
	}
	val[cur]=1;
}
queue<int> q;
void build(){
	while(!q.empty())q.pop();
	for(int i=0;i<26;i++){
		if(ch[0][i]){fail[ch[0][i]]=0;q.push(ch[0][i]);}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(ch[u][i]==0){
				ch[u][i]=ch[fail[u]][i];continue;
			}
			q.push(ch[u][i]);
			int v=fail[u];
			while(v && ch[v][i]==0)v=fail[v];
			fail[ch[u][i]]=ch[v][i];
			if(val[ch[v][i]])val[ch[u][i]]=1;//ע��Ҫ����䣬ʹ�������Ҳ���Ϊƥ�� 
		}
	} 
}
int n,m;char s[MAXM+3];
void dp(){
	opt[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=tot;j++){
			if(val[j] || opt[i][j]==0)continue;
			for(int k=0;k<26;k++){
				if(val[ch[j][k]])continue;
				(opt[i+1][ch[j][k]]+=opt[i][j])%=MOD;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%s",s);insert(s);}
	build();
	int ans=1;
	for(int i=1;i<=m;i++)(ans*=26)%=MOD;
	dp();
	for(int i=0;i<=tot;i++)if(!val[i])ans=(ans-opt[m][i]+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}

