/*
xth ��õ�廨
��������Ŀ�ܳ������ľ��ǣ���·���ܽ��棬�����������һ���򵥵�״̬��
	  opt[i][j]��ʾ����i�У��Ҹ����ϲ�j�����������������ֵ�����̺��ŵ�j+1..m�����������䣬��Ϊֻ�����������������䣬��Ȼ��������
	  ����opt[i][j]=max(opt[i-1][k])k<=j 
	  ���������Ӷ�̫�ߣ����Ǻܶ���Ϣ��û�г�����ã�����ǰ׺�ͣ���ά��g[i][j]��ʾmax(opt[i][k]|k<=j)��g������ѭ����O(1)ά����g[i][j]=max(opt[i][j],g[i][j-1])
	  ��һ��ѹ���ռ䣺ȥ����һά 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int n,m,a[MAXN+3][MAXN+3],b[MAXN+3][MAXN+3],opt[MAXN+3],g[MAXN+3],s[MAXN+3];//sά��a�����i�еĺ�׺�� 
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j]; 
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>b[i][j]; 
}
int dp(){
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=n;j>=1;j--)s[j]=s[j+1]+a[j][i];//ά��a�����i�к�׺�� 
		g[0]=opt[0]=g[0]+s[1];//��ʼ��g��opt��ȫ���������䣩 
		for(int j=1;j<=n;j++){
			sum+=b[j][i];//ά��b����ǰ׺�� 
			opt[j]=g[j]+sum+s[j+1];//ֱ�Ӹ��£���Ϊg�������� 
			g[j]=max(opt[j],g[j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,opt[i]);//Ѱ�����Ž� 
	return ans;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
