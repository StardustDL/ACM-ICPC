/*
���ηָ�
������̰�ļ��ɣ����ȿ϶���ѡ����У�������Ĳ������
	  Ȼ����������У����������+1����������У����������+1 
	  ������Ҫ��n+m-2�� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000;
int n,m,x=1,y=1,r[MAXN+3],c[MAXN+3],ans=0,len;
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++)cin>>r[i];
	for(int i=1;i<m;i++)cin>>c[i];
	sort(r+1,r+n);
	sort(c+1,c+m);
	len=n+m-2;//����Ҫ�ȴ�������֮��n,m��ı� 
	for(int i=1;i<=len;i++){
		if(r[n-1]<c[m-1]){//������ 
			x++;ans+=y*c[--m];
		}
		else{
			y++;ans+=x*r[--n];
		}
	}
	cout<<ans;
	return 0;
} 
