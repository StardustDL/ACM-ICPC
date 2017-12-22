/*
Tiling Up Blocks
���⣺Michael The Kid��n���ľ��ÿ���ľ����ͼ��������l��͹�ڣ�������w��͹�ڣ�������l�����ڣ�������w�����ڡ���l >= l'����m >= m'ʱ��ľ��'�ɰ�װ����һ�����档������ܵ������ľ��
������ǰ���䶼�Ƿϻ��� ����l >= l'����m >= m'ʱ����������֪������������LIS�ķ�������ά����������N^2�ģ���˵�¶�άLIS���Ȱ���һά�����ٶԵڶ�ά��LIS
	  ������l,m��Χ��С��ֱ����opt[i][j]��ʾ����<=i,<=j�Ļ�ľ���������ɡ�opt[i][j]=(i,j)���ִ���+max(opt[i-1][j],opt[i][j-1]) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
int opt[MAXN+3][MAXN+3];
bool input(){
	int n,l,r;
	cin>>n;
	if(n==0)return false;
	memset(opt,0,sizeof(opt));
	while(n-->0){
		cin>>l>>r;opt[l][r]++;
	}
	return true;
}
int dp(){
	int ans=0;
	for(int i=1;i<=MAXN;i++){
		for(int j=1;j<=MAXN;j++)
			opt[i][j]+=max(opt[i-1][j],opt[i][j-1]);
	}
	return opt[MAXN][MAXN];
}
int main(){
	while(input())cout<<dp()<<endl;
	cout<<'*';
	return 0;
}
