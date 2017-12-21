/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int rd=19981222;
int main(int argn,char **args){
	if(argn==2){
		rd=0;
		for(int i=0;args[1][i]!='\0';i++)rd=rd*10+args[1][i]-'0'; 
	}
	freopen("data.in","w",stdout);
	//cout<<rd<<endl;
	srand(rd);
	int n=rand()%100;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)printf("%d ",rand());
	fclose(stdout);
	return 0;
}

