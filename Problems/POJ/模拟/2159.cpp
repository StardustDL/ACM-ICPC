/*
Ancient Cipher
���⣺��������+ѭ���û����������μ��ܣ���S�ܷ�->T
������ע�Ⲣ������μ��ܣ����򣺱�֤˳���޹أ�ѭ���û���Ҫ��ָ��Ԫ��Ψһ
	  �õ��㷨���������ַ�������ĸ������Ȼ���С������������������鲻��ȫһ�£�����һһ��Ӧ�������У�������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
int cnts[26],cntt[26],i;
char s[103],t[103];
int main(){
	cin>>s>>t;
	for(i=0;s[i]!='\0';i++){
		cnts[s[i]-'A']++;
		cntt[t[i]-'A']++;
	}
	sort(cnts,cnts+26);
	sort(cntt,cntt+26);
	for(i=0;i<26;i++){
		if(cnts[i]!=cntt[i]){
			puts("NO");
			break; 
		}
	}
	if(i==26)puts("YES");
	return 0;
}

