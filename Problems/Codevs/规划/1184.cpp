/*
��ש����
������״̬ѹ��DP 
	  ��2���Ƶ�01��ʾ���Ż��Ƿţ���i��ֻ��i-1���йأ�ö��i-1�е�ÿ��״̬���Ƴ��ɴ�״̬�ܴﵽ��i��״̬��
	  ���i-1�еĳ���״̬ĳ��δ�ţ���ȻҪ��i�з�һ�����ķ��飬���Զ���һ��״̬��λȡ��֮���״̬���Ƿ������������״̬��
	  Ȼ����dfs������i�зź��ŵķ�������п��ܣ����Ұ���Щ״̬�ۼ���i-1�ĳ���״̬�ķ�����������÷�����Ϊ0��ֱ��continue��
	  �������λ���㼼�� 
*/ 
#include<iostream>
#include<cstring>
using namespace std;
typedef int LL; 
const int MOD=100003;
int n,m;
LL dp[50000+3][1<<6+1];
void dfs(int row,int state,int pos,LL pre_num){//pos:�����שλ�� 
	if(pos==m){
		dp[row][state]=(dp[row][state]+pre_num)%MOD;
		return;
	}
	dfs(row,state,pos+1,pre_num);//����
	if((pos<=m-2)&&!(state&(1<<pos))&&!(state&(1<<(pos+1))))//���к���һ�з���һ�����Ĵ�ש
		dfs(row,state|(1<<pos)|(1<<(pos+1)),pos+2,pre_num);
}
int main(){	
	while(cin>>n>>m){
		if(n<m){//��С��������״ѹ 
			swap(n,m);
		}
		memset(dp,0,sizeof(dp));
		dfs(1,0,0,1);//��ʼ����һ��
		for(int i=2;i<=n;i++) 
			for(int j=0;j<(1<<m);j++){
				if(dp[i-1][j]){
					//���i-1�еĳ���״̬ĳ��δ�ţ���ȻҪ��i�з�һ�����ķ��飬���Զ���һ��״̬��λȡ��֮���״̬���Ƿ������������״̬
					dfs(i,(~j)&((1<<m)-1),0,dp[i-1][j]);
				}
				else continue;
			}

		/** ע�Ⲣ����ѭ��i ��� dp[n][i]�е����ֵ */
		cout<<dp[n][(1<<m)-1]; 
		break;
	}
	return 0;
}
