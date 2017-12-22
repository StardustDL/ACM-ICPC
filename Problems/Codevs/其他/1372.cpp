/*
DNA
�������൱��ÿ���ַ��ж�Ӧ�ַ�����������Ӵ�������ö���Ӵ��м�㣬Ȼ�������߾�������չ��
	  ע�����ﲻ����һ���ַ�ҲΪ�����Ӵ������
	  ����ע�⣬��Ҫת��������Ӵ���������һ����ȷ����������Ҫ�����о� 
	  ����һ��O(n)������Manacher�㷨 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=50000;
typedef char str[MAXN+3];
int n,ans; 
str s;
char getn(char x){
	switch(x){
		case 'A':return 'T';
		case 'G':return 'C';
		case 'T':return 'A';
		case 'C':return 'G'; 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	for(int i=1;i<n;i++){
		int len=0,l=i,r=i+1;
		while(s[l]==getn(s[r]))len++,l--,r++;
		ans=max(ans,len);
	}
	cout<<2*ans;
	return 0;
}
