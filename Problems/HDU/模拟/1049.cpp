/*
Climbing Worm
���⣺һ�����ӵ�����һ��n������ľ��У�Ȼ����ÿ���ӿ�����u���ȣ�Ȼ��Ҫ��Ϣһ���ӣ��ڴ��ڼ��������d���ȣ���������������Ҫ��á�
������ģ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,u,d;
int main(){
	while(cin>>n>>u>>d,n+u+d>0){
		int tme=0;
		while(n>0){
			if(tme&1)n+=d;
			else n-=u;
			tme++;
		}
		cout<<tme<<endl; 
	}
	return 0;
}

