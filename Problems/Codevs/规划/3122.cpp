/*
длеё╢ЗюМил VIII
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15,INF=1<<30;
int mp[MAXN+3][MAXN+3],n,opt[1<<17][MAXN+3],state[MAXN+3][1<<17],num[MAXN+3];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
int dp(){
	int mx=1<<n;
	for(int i=1;i<=(1<<(n+1));i++)  
            for(int j=1;j<=n+1;j++)  
                  opt[i][j]=INF;  
    for(int i=1;i<mx;i++)  
    {  
		int tot=0;  
        for(int j=0;j<n;j++)if((1<<j)&i)tot++;  
        state[tot][++num[tot]]=i;              
    } 
	for(int i=1;i<=n;i++)opt[1<<(i-1)][i]=mp[1][i];
	for(int i=1;i<n;i++)  
        for(int l=1;l<=num[i];l++)  
			for(int j=1;j<=n;j++)  
            {
                if(!((1<<(j-1))&state[i][l]))continue;
                for(int k=1;k<=n;k++)  
                {
					if(!((1<<(k-1))&state[i][l]))  
						opt[(state[i][l]+(1<<(k-1)))][k]=min(opt[(state[i][l]+(1<<(k-1)))][k],opt[state[i][l]][j]+mp[j][k]);  
				}
            }
	int ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,opt[mx-1][i]+mp[i][1]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>mp[i][j];
	}
	floyd();
	cout<<dp();
	return 0;
} 
