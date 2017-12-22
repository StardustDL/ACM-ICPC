#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=100,INF=1<<20;
int n,m,r,rmb[MAXN+3],time[MAXN+3],rp[MAXN+3];
int mxp[MAXN+3][MAXN+3],mxt[MAXN+3][MAXN+3];
//��¼����iԪ������jRP�����ܵõ�����������mxp[i][j]���ʹﵽ�����������Сʱ��mxt[i][j] 
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>rmb[i]>>rp[i]>>time[i];
	}
	cin>>m>>r;
	/*memset(mxp,0,sizeof(mxp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mxt[i][j]=INF;
		}
	}*/
}
int solve(){
	for(int i=1;i<=n;i++){
		for(int j=m;j>=rmb[i];j--){
			for(int k=r;k>=rp[i];k--){
				int ep=mxp[j-rmb[i]][k-rp[i]]+1,
				    et=mxt[j-rmb[i]][k-rp[i]]+time[i];
				if(mxp[j][k]<ep){//���Ż����� 
					mxp[j][k]=ep;
					mxt[j][k]=et;
				}
				if(mxp[j][k]==ep&&mxt[j][k]>et){//��������ʱ�Ż�ʱ�� 
					mxt[j][k]=et;
				}
			}
		}
	}
	return mxt[m][r];
}
int main(){
	init();
	cout<<solve();
	return 0;
}
