/*
���⣺��һ��1..n������P(i)������Pn(i)=P(Pn-1(i))������С��Kʹ��Pk(i)=i
����������������һ�û�T��T^k=e������Сk
	  ���������һ������kmin=T�Ĳ�ֵ�����ѭ�����ȵ���С������
	  ѭ�������û���ʾ��ͼ��i->p(i)����ͼ�еĻ���Ϊ�û��е�ѭ��
	  ������������������ÿһλ��������ٵ��û����Լ�Ӧ�õ����֡�ÿһλ�������������֣�ȡ��С�������Ϳ��ԡ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,a[MAXN+3],ans=1;
int gcd(int a,int b){
	//return a%b==0?b:gcd(b,a%b);
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,tmp,cnt;i<=n;i++){
		tmp=a[i];cnt=1;
		while(tmp!=i){
			tmp=a[tmp];
			cnt++;
		}
		ans=lcm(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}

