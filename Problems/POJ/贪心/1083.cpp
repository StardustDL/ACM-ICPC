/*
Moving Tables
������������̰���㷨��������һ������˱�ķ�������easy����ԭ�����£�
      �ȴ���һ������f������������ⷿ��ţ�����������ȵ�λ�á�
	  ����1�ŷ����2�ŷ��䶼��Ӧλ��1�����ȣ�3�ŷ����4�ŷ����Ӧλ��2�����ȣ�
	  һ����200��������λ�á�
	  ��a[201]������Щλ�ã�����ĳλ�õ�ֵ���Ǿ������λ�õĴ�����
	  �����ĳһ�ŷ�����һ�ŷ�����������ÿ��λ�õĴ�����+1�������ȫ��ɨ�����ĸ�λ�þ���������࣬���ֵ�������λ�õ�ֵ*10�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define f(x) ((x&1)?((x+1)>>1):(x>>1))
int t,n,a,b,s[203];
int main(){
	cin>>t;
	while(t-->0){
		memset(s,0,sizeof(s));
		cin>>n;
		while(n-->0){
			cin>>a>>b;
			if(a>b)swap(a,b);
			a=f(a);b=f(b);
			for(int i=a;i<=b;i++)s[i]++;
		}
		for(int i=1;i<=200;i++)n=max(n,s[i]);
		cout<<n*10<<endl;
	}
}
