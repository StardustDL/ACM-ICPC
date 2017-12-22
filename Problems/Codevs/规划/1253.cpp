/*
�����г�
������ע�������˵���������ģ�����opt[i][j]��ʾ�г���ǰi�ֲˣ��Ѿ�����ǰj�ֲ˵����Ž⣬
	  ��ÿ��������Ͳ������֣��������������ģ��պ��ǵ�ǰҪ��Ĳˡ�
	  ��д������opt[i][j]ת�Ƶ�opt[i+1][j]��opt[i+1][j+1]�ķ��̣���������������Ʊ߽� 
	  ���Ը���һ�·��̣��߽���opt[0][0]=0,opt[0][1..m]=INF 
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=100000,MAXM=100,INF=0x3f3f3f3f;
struct vegt{
	int k;double p;
};
bitset<MAXN+3> exi;
int m,n,x[MAXM+3];
double opt[MAXN+3][MAXM+3];
vector<vegt> vs;
void input(){
	cin>>m>>n;exi=0;int k;double p;
	for(int i=1;i<=m;i++){
		cin>>x[i];exi[x[i]]=1;
	}
	vs.push_back((vegt){0,0});bool flg=true;
	for(int i=1;i<=n;i++){
		cin>>k>>p;
		if(flg&&k!=x[1])continue;
		else flg=false;
		if(exi[k])vs.push_back((vegt){k,p});
	}
}
double dp(){
	opt[0][0]=0;
	for(int i=0;i<vs.size();i++)for(int j=1;j<=m;j++)opt[i][j]=INF;
	for(int i=1;i<vs.size();i++){
		for(int j=1;j<=min(i,m);j++){
			opt[i][j]=min(opt[i-1][j],vs[i].k==x[j]?(opt[i-1][j-1]+vs[i].p):INF);
			/*opt[i+1][j+1]=min(opt[i+1][j+1],opt[i][j]+vs[i].p);
			opt[i+1][j]=min(opt[i+1][j],opt[i][j]);*/
		}
	}
	double ans=INF;
	for(int i=m;i<vs.size();i++)
		ans=min(ans,opt[i][m]);
	return ans;
}
int main(){
	input();
	double ans=dp();
	if(ans==INF)printf("Impossible");
	else printf("%.2lf",ans);
	return 0;
}
