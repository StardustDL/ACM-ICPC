/*
����
����������ܼ򵥣���˼·�����ص� 
	  �Ȱ���Ԥ����������׿������Ȼ���������м���
	  opt[i][j]��ʾÿһ��λ����[i][j]Ϊ���½ǵľ��θ���
	  ö��j֮ǰ���У����֮ǰ�еİ׿�������ڵ��ڵ�ǰ�ģ���Ϊcnt������ô���ֿ�����cnt������
	  ������С�ڵ�������ͽ��Ǹ�λ�õĴ𰸼ӵ�opt[i][j]�ϣ�����λ�õ�opt[i][j]֮�ͼ�Ϊ�� 
*/
#include<iostream>
using namespace std;
const int MAXN=150;
int n,mp[MAXN+3][MAXN+3],up[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
void input(){
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			switch(ch){
				case 'W':mp[i][j]=1;break;
				case 'B':mp[i][j]=0;break;
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j])up[i][j]=up[i-1][j]+1;
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!mp[i][j])continue;
			int cnt=opt[i][j]=up[i][j],t=j-1;
			while(mp[i][t]&&up[i][t]>=cnt){
				opt[i][j]+=cnt;t--;
			}
			opt[i][j]+=opt[i][t];
			ans+=opt[i][j];
		}
	}
	return ans;
}
int main(){
	input();init();
	cout<<solve();
	return 0;
}
