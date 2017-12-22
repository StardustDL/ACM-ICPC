/*
Jury Compromise
���⣺��n������ѡ��m����ÿ�����й̶���pֵ��dֵ��Ҫ��ʹm���˵�p�ܺͺ�d�ܺ͵Ĳ�ľ���ֵ��С�����ж����ȡ���ߺ����ġ�
������f[i][j]��ʾ��ѡm�����еĵ�i���˵�ʱ��ʹ������ѡ�е��˵�p,d��Ϊjʱ�����ܻ�õ�p,d���͡�
	  f[i + 1][j + p[k] - d[k]] = f[i][j] + p[k] + d[k];(Ҫ��k֮ǰû��ѡ����Ҫ�鿴f[i][j]������·����ȷ����k)
	  ��д��ɺ󣬹۲�f[m]�ҵ���С��ֵ�����͡�֪���Ͳ���Ȼ��������ܵ�p,d�� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[21][801],path[21][801];
int D[201],J[201],res[21];
int cmp(const void *a,const void *b){return *(int*)a-*(int*)b;}
bool select(int a,int b,int i){
	while(a>0 && path[a][b]!=i){
		b-=D[path[a][b]]-J[path[a][b]];
		a--;
	}
	return (a!=0)?true:false;//i��û�б��ù���
}
int main(){
	int i,j,k,r,n,m,cnt=1,a,b;
	while(scanf("%d%d",&n,&m),n||m){
		for(i=1;i<=n;i++)scanf("%d%d",&D[i],&J[i]);
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		r=m*20;
		dp[0][r]=0;
		for(j=0;j<m;j++)
  			for(k=0;k<=r*2;k++)
				if(dp[j][k]>=0)
					for(i=1;i<=n;i++)
						if(dp[j+1][k+D[i]-J[i]]<dp[j][k]+D[i]+J[i]){//״̬����
							a=j;b=k;
							if(!select(a,b,i)){
								dp[j+1][k+D[i]-J[i]]=dp[j][k]+D[i]+J[i];
								path[j+1][k+D[i]-J[i]]=i;
							}
						}
		for(i=r,j=0;dp[m][i+j]<0&&dp[m][i-j]<0;j++);//Ѱ�Ҿ���ֵ��С��
			k=dp[m][i+j]>dp[m][i-j]?i+j:i-j;//Ѱ�Ҿ���ֵ��С�ĺ�����
		printf("Jury #%d\n",cnt++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[m][k]+k-r)/2, (dp[m][k]-k+r)/2);
		for(i=1;i<=m;i++){
			res[i]=path[m-i+1][k];
			k-=D[res[i]]-J[res[i]];
		}
		qsort(res+1,m,sizeof(res[0]),cmp);
		for(i=1;i<=m;i++)printf(" %d",res[i]);
		puts("\n"); 
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200,R=100;
int opt[MAXN+3][MAXN+3][R+MAXN*10+3],p[MAXN+3],d[MAXN+3],n,m;
bool input(){
	scanf("%d%d",&n,&m);
	if(n+m==0)return false;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i],&d[i]);
	}
	return true;
}
int dp(){
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=-R+1;k<=R;k++){
				opt[i][j][R+k]=max(opt[i-1][j][R+k],opt[i-1][j-1][R+k-p[i]+d[i]]+p[i]+d[i]); 
			}
		}
	}
	int ans=0;
	for(int i=1;i<=R;i++)ans=max(ans,opt[n][m][i]);
	return ans;
}
int main(){
	while(input()){
		cout<<dp()<<endl;;
	}
	return 0;
}
*/
