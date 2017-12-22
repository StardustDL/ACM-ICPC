#include<iostream>
using namespace std;
const int MOD=32768;
int mr[2][2]={{1,1},{1,0}},mt[2][2],ans[2]={1,1},at[2];
long n;
void cheng(){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			int &t=mt[i][j];t=0;
			for(int k=0;k<2;k++){
				t+=mr[i][k]*mr[k][j];
			}
			t%=MOD;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			mr[i][j]=mt[i][j];
		}
	}
}
void qans(){
	at[0]=(ans[0]*mr[0][0]+ans[1]*mr[1][0])%MOD;
	at[1]=(ans[0]*mr[0][1]+ans[1]*mr[1][1])%MOD;
	ans[0]=at[0];ans[1]=at[1];
}
int ksm(){
	while(n|0){
		if(n&1)qans();
		cheng();n>>=1;
	}
	return ans[0];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;n-=2;
	if(n==-1)cout<<1;
	else cout<<ksm();
	return 0;
}
