/*
����Ŷ�
�����������뵽�����������еĵ�iλ�þ�Ϊ����Եĵ�i����ʱ������С 
	  �ȶ�����ֵ��ɢ����������Ӧ�±꣩��Ȼ��k[i]��ʾa�е�ֵΪi��λ��Ҫ�ƶ���b�е��ĸ�λ�� 
	  Ȼ���ת��Ϊ����� 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<cstring>
#define lowbit(x) (x&-x)
using namespace std;
const int MAXN=100000,MOD=99999997;
typedef int LL;
struct data{
	int x,p;
	bool operator < (const data &d)const{
		return x<d.x;
	}
}a[MAXN+3],b[MAXN+3];
struct BIT{
	LL d[MAXN+3],n;
	void init(int n){this->n=n;}
	void add(LL x,LL ad){
		while(x<=n){d[x]=(d[x]+ad)%MOD;x+=lowbit(x);}
	}
	LL sum(int x){
		int ans=0;
		while(x>0){ans=(ans+d[x])%MOD;x-=lowbit(x);}
		return ans;
	}
}bit;
int n,ans=0,k[MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;a[i].p=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].x;b[i].p=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	bit.init(n);
	for(int i=1;i<=n;i++)k[a[i].p]=b[i].p;
	for(int i=1;i<=n;i++){
		bit.add(k[i],1);
		ans=(ans+i-bit.sum(k[i]))%MOD;//i-sum(k[i])��ʾǰi�����б�k[i]������ĸ��� 
		/*����������ѭ�������������� 
		ans+=bit.sum(k[i]);
		bit.add(k[i],1);
		*/
	}
	cout<<ans;
	return 0;
}
