/*
������
��������Ϊд�ĵ�һ��״ѹDP�����̿�ν���ѣ������ȽϺ��룬���������������·��Ȼ��DP
	  ��Ҫע��ϸ�ڣ�
	  	��opt[i][j]��ʾ��״̬i��λ��jʱ�����Ž� 
	  	����Ҫ����ֵopt[1<<i][i]=mp[0][i],else opt[x][y]=INF
	  	Ȼ��ҪԤ���������i��1��״̬���ϣ�state[i]={״̬1��״̬2��...}
		��һ������Ҫ����Ϊ֮���DP����Ҫ��1�ٵ�ת�Ƶ�1��ģ�����������ת�ơ�
		��һ��д�������ˣ�
	for(int u=1;u<=n;u++){//������� 
		for(int i=0;i<mx;i++){
			for(int v=1;v<=n;v++){
				if(u==v)continue;
				if((i&(1<<(u-1))==0)||(i&(1<<(v-1))==1))continue;
				opt[i|(1<<(v-1))][v]=min(opt[i|(1<<(v-1))][v],opt[i][u]+mp[u][v]);
			}
		}
	}
		Ȼ��ö��1�ĸ�����ö�����������״̬��ö����㣬�յ㣬ע��״̬�����������ѵ�������δ�����յ㡣 
		ת�ƾͺܼ��ˣ�opt[״̬i�ȵ�v][v]=min{opt[״̬i][u]+mp[u][v]}
		�������Ҫ�ص���㣬��Ҫ��ö��������״̬�е����Ž⡣ 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15,INF=1<<30;
int mp[MAXN+3][MAXN+3],n,opt[1<<17][MAXN+3],state[MAXN+3][1<<17],num[MAXN+3];
void floyd(){
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
int dp(){
	int mx=1<<n;
	for(int i=0;i<=(1<<(n+1));i++)  
            for(int j=0;j<=n+1;j++)  
                  opt[i][j]=INF;  
    for(int i=0;i<mx;i++)  
    {  
		int tot=0;  
        for(int j=0;j<n;j++)if((1<<j)&i)tot++;  
        state[tot][++num[tot]]=i;              
    } 
	for(int i=1;i<=n;i++)opt[1<<(i-1)][i]=mp[0][i];
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
		ans=min(ans,opt[mx-1][i]+mp[i][0]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)cin>>mp[i][j];
	}
	floyd();
	cout<<dp();
	return 0;
} 
