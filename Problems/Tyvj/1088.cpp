#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000;
int n,a[MAXN+3],s[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
void read(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[i][j]=s[i][j-1]+a[j];//��������[i,j]������ͣ�ע��ֻ����j>=i����� 
		}
	}
}
//ע�⵽ÿȡһ������ʣ�µ����˵�ϵ����+1�����Կ���������� 
int solve(){
	memset(opt,0,sizeof(opt));
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			opt[i][j]=max(opt[i+1][j],opt[i][j-1])+s[i][j];
		}
	}
	return opt[1][n];
}
void test(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<opt[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	read();
	cout<<solve()<<endl;
	//test();
	return 0;
}
