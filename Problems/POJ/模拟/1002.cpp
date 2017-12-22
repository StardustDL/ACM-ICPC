/*
487-3279
题意：给你一些由大写字母、数字、和'-'组成的字符串，并给出大写字母各自对应的数字。求出转换为数字后重复的次数。
分析：模拟，注意转数字 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cctype>
using namespace std;
int num[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
map<int, int> s;
char buf[128];
int main(){
	int t;
	scanf("%d", &t);
	bool flag=false;
	for(int i=0;i<t;i++){
		scanf("%s",buf);
		int c=0;
		for(int j=0;buf[j];j++){
			if(isdigit(buf[j]))c=c*10+buf[j]-'0';
			else if(isalpha(buf[j]))c=c*10+num[buf[j]-'A'];
		}
		s[c]++;
	}
	for(map<int,int>::iterator it=s.begin();it!=s.end();it++)
		if(it->second>1){
			flag=true;
			printf("%03d-%04d %d\n", it->first/10000, it->first%10000,it->second);
		}
	if(!flag)puts("No duplicates.");
	return 0;
}
        
