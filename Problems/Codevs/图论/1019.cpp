/*
��������ͼ��
�������տ�ʼ���Floyd�հ������ǳ�ʱ�� 

bool floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][j]==0&&(d[i][k]&d[k][j])==1)return false;
	return true;
}
	  Ȼ��͸ĳ�ö�٣���AC�ˡ�ע��memset��Ҫ����bool���� 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1003;
int d[MAXN][MAXN],n,m;
void input(){
	cin>>n>>m;
	int a,b;
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++){
		cin>>a>>b;d[a][b]=true;
	}
}
bool judge(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(d[i][j] && i!=j)
				for(int k=1;k<=n;k++)
					if(d[j][k] && j!=k && !d[i][k])return false;
	}
	return true;
} 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t-->0){
		input();
		if(judge()){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
