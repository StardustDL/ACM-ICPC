/*
LCIS 
������f[i]����a���ĵ�i����Ϊֹ, ����a[i]���ڵĲ���a[i]Ϊ��β�ģ�������b������������������У�
	  ����max��¼��a[i]>b[j]ʱa����ǰiλ��b����ǰjλ��LCIS���Ա�����һ��������a[i]=b[j]ʱʹ�ã�
	  ��ʱʹ�õ�maxʱj֮ǰ��LCIS����f[j]����Ϊmax+1���������һ�������maxΪʲô��a[i]=b[j]ʱҲ��ʹ���أ�
	  ��Ϊ�����������ͬһ��a[i]��˵�ġ���Ϊa[i]<b[j]ʱ������a[i]���ڵ�LCIS�������γɣ����Բ���Ҫ���� 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3000;
int f[MAXN+3],n;
int a[MAXN+3],b[MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1,mx=0;j<=n;j++){
			if(a[i]>b[j])mx=max(mx,f[j]);
			else if(a[i]==b[j])f[j]=max(f[j],mx+1);
		}
	}
	for(int i=1;i<=n;i++)f[0]=max(f[i],f[0]);
	cout<<f[0]<<endl;
	return 0;
}
