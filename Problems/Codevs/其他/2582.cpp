/*
Letters
������̰�ģ�ÿ����ĸһ��ѡ�������������ͬ��ĸ��������Ȼ��ͳ������������
	  �ر��һ�¾ͺã���һ��������26������ 
	  ����˵��һ����״����������ԣ�ÿ����i��Ӧ����״�����е�i��λ�ã���С����ö��������У��赱ǰֵΪx����ans+=sum(x)���൱��ͳ�Ʊ�xС������ǰi�������ж��ٸ���������xλ��+1 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<cstring>
#define lowbit(x) (x&-x)
using namespace std;
const int MAXN=1000000;
typedef char str[MAXN+3];
typedef long long LL;
struct BIT{
	LL d[MAXN+3],n;
	void init(int n){this->n=n;}
	void add(LL x,LL ad){
		while(x<=n){d[x]+=ad;x+=lowbit(x);}
	}
	LL sum(int x){
		int ans=0;
		while(x>0){ans+=d[x];x-=lowbit(x);}
		return ans;
	}
}bit;
int n;
stack<int> T[27+4];
str a,b;
int s[MAXN+3];
int main(){
	cin>>n>>a>>b;
	bit.init(n);
	for(int i=0;i<n;i++)T[a[i]-'A'].push(i);//�൱�ڶ�ÿ����ĸ��һ���ڽӱ����д��������ĸ�ĳ���λ�ã������� 
	for(int i=n-1;i>=0;i--){
		s[i]=T[b[i]-'A'].top();T[b[i]-'A'].pop();//ѡ����������Ķ�Ӧ 
	}
	LL ans=0;
	for(int i=n-1;i>=0;i--){//��״����������� 
		ans+=bit.sum(s[i]+1);//��Ϊ��ĸ��0..25������״����0λ�ò�����ֵ������+1 
		bit.add(s[i]+1,1LL);
	}
	cout<<ans;
	return 0;
}
