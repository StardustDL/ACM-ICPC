/*
Best Sequence
分析：先求出每两个字符串重合部分长度，然后状压DP即可，但就是WA。。。可能是状压DP的状态顺序无法实现 
	  无语，改成全排列，其实也可以DFS+剪枝 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int LEN=20,MAXN=10,INF=0x3f3f3f3f;
typedef char str[LEN+3];
/*int n,len[MAXN+3],a[MAXN+3][MAXN+3],opt[(1<<MAXN)+3][MAXN+3];
str S[MAXN+3];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>S[i];len[i-1]=strlen(S[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int st=len[i-1]-1,k;
			while(S[i][st]!=S[j][0]&&st>=0)st--;
			a[i-1][j-1]=0;
			if(st>=0){
				for(k=st;k<len[i-1];k++){
					if(S[i][k]!=S[j][k-st]){
						k=-1;break;
					}
				}
				if(k!=-1)a[i-1][j-1]=len[i-1]-st;
			}
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
}
int dp(){//样例已过 
	memset(opt,INF,sizeof(opt));
	for(int i=0;i<n;i++)opt[1<<i][i]=len[i];
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			//opt[i][j]=INF;
			if(i&(1<<j)){
				for(int k=0;k<n;k++){
					if(i&(1<<k))continue;
					opt[i|(1<<k)][k]=min(opt[i|(1<<k)][k],opt[i][j]+len[k]-a[j][k]);
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++)ans=min(opt[(1<<n)-1][i],ans);
	return ans;
}
int dp(int x){//样例没过 
	//for(int i=0;i<n;i++)opt[1<<i][i]=len[i];
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			opt[i][j]=INF;
			if(i&(1<<j)){
				if(i^(1<<j)==0)opt[i][j]=len[j];
				else for(int k=0;k<n;k++){
					if((i&(1<<k))&&k!=j)
						opt[i][j]=min(opt[i][j],opt[i^(1<<j)][k]+len[j]-a[k][j]);
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++)ans=min(opt[(1<<n)-1][i],ans);
	return ans;
}
int main(){
	int T;cin>>T;
	while(T-->0){
		input();
		cout<<dp()<<endl;
	}
	return 0;
}*/
str gene[MAXN+3];
int cost[MAXN+3][MAXN+3],f[MAXN+3],n;
void input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",gene[i]);
}
int cal(str st1,str st2){
    int len1=strlen(st1),len2=strlen(st2);
    for(int i=len1-len2;i<len1;i++){
        bool ok=true;
        for(int j=i;j<len1;j++)
            if(st1[j]!=st2[j-i]){ok=false;break;}
        if(ok)return len2+i-len1;
    }
    return len2;
}
void make(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j]=cal(gene[i],gene[j]);
}
void work(){
    for(int i=0;i<n;i++)f[i]=i;
    int ans=INF;
    do{
        int temp=strlen(gene[f[0]]);
        for(int i=0;i<n-1;i++){
			temp+=cost[f[i]][f[i+1]];
			if(temp>ans)break; 
		}
        ans=min(ans,temp);
    }while(next_permutation(f,f+n));
    printf("%d\n",ans);
}
int main(){
	int t;
    scanf("%d", &t);
    while (t--){
        input();make();
        work();
    }
    return 0;
}
