/*
���⣺����һ���ֵ䣬�������ɵ���
		1.��ĳ�����������ֵ����ҵ��������corret
		2.��ĳ��������ͨ�� �任 �� ɾ�� �� ���һ���ַ������ֵ����ҵõ����������Щ���ʣ����˳�����  ������ǲ��ֵ���ֵ���
		3.��ĳ���������۲�������޷����ֵ����ҵõ���������� 
�����������������ж��Ƿ�ƥ�䣺������֮����з���
		1��strlen(str)==strlen( ch[n] );�п�����һ���ַ���һ��������ַ��Ƚϣ�ͳ�Ʋ�ͬ�ַ���
		2��strlen(str)+1==strlen( ch[n] );�п�����һ���ַ�������ַ��Ƚϣ�������ַ���ͬ����ch[n]�ַ��±������ƶ�һλ��str���䣬��ͬ�ַ�����1
		3��strlen(str)-1==strlen(  ch[n] )�п�����һ���ַ�������ַ��Ƚϣ�������ַ���ͬ����str]�ַ��±������ƶ�һλ��ch[n]���䣬��ͬ�ַ�����1 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
char str[33],mp[MAXN+3][33];
int n=0;
vector<int> ans;
bool check(int idx){
	int l1=strlen(str),l2=strlen(mp[idx]),k=0;
	switch(l1-l2){
		case 1:
			for(int i=0,j=0;i<l1;i++){
				if(str[i]!=mp[idx][j])k++;
				else j++;
			}
			break;
		case 0:
			for(int i=0,j=0;i<l1;i++,j++){
				if(str[i]!=mp[idx][j])k++;
			}
			break;
		case -1:
			for(int i=0,j=0;j<l2;j++){
				if(str[i]!=mp[idx][j])k++;
				else i++;
			}
			break;
	}
	return k==1;
}
int main(){
	while(scanf("%s",mp[n])&&strcmp(mp[n],"#")!=0)n++;
	while(scanf("%s",str)&&strcmp(str,"#")!=0){
		ans.clear();int i;
		for(i=0;i<n;i++)
			if(strcmp(str,mp[i])==0){printf("%s is correct\n",str);break;}
		if(i>=n){
			printf("%s:",str);
			for(i=0;i<n;i++)if(check(i))printf(" %s",mp[i]);
			puts("");
		}
	}
	return 0;
}

