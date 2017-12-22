/*
Running
���⣺��ţBessie��N����ʱ���ܲ���ÿ�����������ܲ�������Ϣ�������ڵ�i�����ܲ��������ܳ�D_i�ף�ͬʱƣ��̶�����1����ʼΪ0���������ڵ�i������Ϣ����ƣ��̶ȼ���1�����ۺ�ʱ��ƣ��̶ȶ����ܳ���M�����⣬һ������ʼ��Ϣ��ֻ�е�ƣ���̶ȼ�Ϊ0ʱ�������¿�ʼ�ܲ����ڵ�N���Ӻ�����ƣ��̶ȱ���Ϊ0�� 
������״̬��Ϊopt[i][j]��ʾ��i���ӣ�ƣ��ֵΪjʱ����Զ���룬
	  ת���е�࣬Ҫ�ú��룺
	  	1.0<j<=mʱ������ǰ����opt[i-1][j-1]+d[i]
	  	2.j=0ʱ��
			a)���ϴ���Ϣǰ����opt[i-j][j]�����״̬�����ǵ�opt[i][j]����һ��Ϳ���ǰ���� 
	  		b)������Ϣ��opt[i-1][0]
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000,MAXM=500;
int n,m,d[MAXN+3],opt[MAXN+3][MAXM+3];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>d[i];
	memset(opt,0,sizeof(opt));
}
int dp(){
	for(int i=1;i<=n;i++){
		opt[i][0]=max(opt[i][0],opt[i-1][0]);
		for(int j=1;j<=m;j++){
			opt[i][j]=max(opt[i][j],opt[i-1][j-1]+d[i]);
			if(i>=j)opt[i][0]=max(opt[i][0],opt[i-j][j]);
		}
	}
	return opt[n][0];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<dp()<<endl;
	return 0;
} 
