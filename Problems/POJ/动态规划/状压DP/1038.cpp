/*
Bugs Integrated, Inc.
���⣺�� 2*3 ��оƬǶ�� n��m�� �ĵ�λ�ߴ�ģ���У�ģ��������һЩ���㽫����ǳ���������оƬ������m<=10
������ע��ÿһ�е���Ϣ���������йأ��������Ʊ�ʾ״̬��
	  	1.a[x] = 0  ��ʾ����x-1,y�����У�����x-2,y������
		2.a[x] = 1  ��ʾ����x-1,y�����У�����x-2,y����ռ��
		3.a[x] = 2, ��ʾ����x-1,y����ռ�� 
	  �����Ϳ���ת���ˣ�ע�⻵�㣺dfsʱͬʱ��¼��һ�е�״̬����ʵ�����������е���Ϣ��������һ�е�ʲô��û��״̬����������һ�еĻ������һ�е����Ϣ��
	  ���������֣����ŷţ����ŷ� 
	  ������״̬ѹ����ʵ�֣��޷���λ���㣬��Ԥ����3���ݣ�Ȼ��ģ�⼴�ɣ�ע��Ҫ��״̬��Ϣ�Ľ�ѹ��ѹ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f;
int tpow[15],opt[2][60003],p[15],q[12],mp[150+3][15],ans=0,m,n,cur;
void loadtpow(){tpow[0]=1;for(int i=1;i<=11;i++)tpow[i]=tpow[i-1]*3;}
int qstate(int *p,int *q,int i,int j){
	//cout<<j<<":"<<endl;
	int res=0;memset(p,0,sizeof(p));memset(q,0,sizeof(q));
	/*for(int k=1,t=j;k<=m&&t;k++,t/=3)cout<<(p[k]=t%3)<<" ";//������д����ʲô�������������ֱ��WA 
	puts("");
	for(int k=1;k<=m;k++,j/=3)cout<<(p[k]=j%3)<<" ";
	puts("");*/
	for(int k=1;k<=m;k++,j/=3)p[k]=j%3;
	for(int k=1;k<=m;k++){
		if(mp[i][k])q[k]=2;
		else if(p[k]==2)q[k]=1;
		else if(p[k]<2)q[k]=0;
		res+=tpow[k-1]*q[k];
	}
	//cout<<res<<endl;
	return res;
}
void dfs(int now,int y,int r){
	ans=max(now,ans);
	if(y+1<=m&&p[y]+p[y+1]+q[y]+q[y+1]==0){//����3��2�е� 
		q[y]=q[y+1]=2;
		int nxt=r+tpow[y-1]*2+tpow[y]*2;
		opt[cur][nxt]=max(opt[cur][nxt],now+1);
		dfs(now+1,y+2,nxt);
		q[y]=q[y+1]=0;
	}
	if(y+2<=m&&q[y]+q[y+1]+q[y+2]==0){//����2��3�е�
		q[y]=q[y+1]=q[y+2]=2;
		int nxt=r+tpow[y-1]*2+tpow[y]*2+tpow[y+1]*2;
		opt[cur][nxt]=max(opt[cur][nxt],now+1);
		dfs(now+1,y+3,nxt);
		q[y]=q[y+1]=q[y+2]=0;
	}
	opt[cur][r]=max(opt[cur][r],now);
	if(y+1<=m)dfs(now,y+1,r);
}
int main(){
	int T;scanf("%d",&T);loadtpow();//cout<<tpow[4]<<endl;
	while(T--){
		int k,a,b,st=0;memset(mp,0,sizeof(mp));
		scanf("%d%d%d",&n,&m,&k);
		while(k--){
			scanf("%d%d",&a,&b);mp[a][b]=1;
		}
		//cout<<mp[1][m]<<endl;
		for(int i=0;i<m;i++)if(mp[1][i+1])st+=tpow[i]*2;else st+=tpow[i];
		//cout<<st<<endl;
		cur=0;memset(opt,-1,sizeof(opt));ans=0;opt[cur][st]=0;
		for(int i=2;i<=n;i++){
			cur^=1;memset(opt[cur],-1,sizeof(opt[cur]));
			for(int j=0;j<tpow[m];j++){
				if(opt[cur^1][j]==-1)continue;
				dfs(opt[cur^1][j],1,qstate(p,q,i,j));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

