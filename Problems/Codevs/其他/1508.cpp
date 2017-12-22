/*
ÄãµÄ·ÉµúÔÚÕâ¶ù
*/
#include<cstdio>
#include<cstring>
using namespace std;
char c1[7],c2[7];
int a=1,b=1;
int main(){
	scanf("%s\n%s",c1,c2);
	for(int i=0;i<strlen(c1);i++)
		a*=c1[i]-'A'+1;
	for(int i=0;i<strlen(c2);i++)
		b*=c2[i]-'A'+1;
	if(a%47==b%47)printf("GO");
	else printf("STAY");
	return 0;
}
