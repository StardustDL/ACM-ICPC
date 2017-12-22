/*
Ancient Cipher
题意：乱序排序+循环置换，经过两次加密，问S能否->T
分析：注意并不求如何加密，乱序：保证顺序无关；循环置换：要求指定元素唯一
	  得到算法：对两个字符串的字母计数，然后从小到大排序，如果计数数组不完全一致（不能一一对应），则不行，否则可以 
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

