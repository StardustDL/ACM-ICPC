/*
统计单词数
分析：直接做就可以 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype> 
#include<vector>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
char str[MAXN+3],t[13];
vector<int> v;
int lt,ls,start=-1,cnt=0;
int main(){
	scanf("%s",t);getchar();
	v.push_back(0);
	gets(str);
	for(int i=0;t[i]!='\0';i++){
		t[i]=tolower(t[i]);
	}
	for(int i=0;str[i]!='\0';i++){
		str[i]=tolower(str[i]);
		if(isblank(str[i])&&isalpha(str[i+1]))v.push_back(i+1);
	}
	for(int i=0,j;i<v.size();i++){
		for(j=0;t[j]!='\0'&&t[j]==str[v[i]+j];j++);
		if(t[j]=='\0'&&(!isalpha(str[v[i]+j]))){
			if(start==-1)start=v[i];
			//cout<<v[i]<<endl;
			cnt++;
		}
	}
	if(~start){
		printf("%d %d\n",cnt,start);
	}
	else puts("-1"); 
	return 0;
}

