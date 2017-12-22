/*
The Hardest Problem Ever
分析：水题，但为什么会WA？ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=300;
char str[MAXN+3];
int main(){
	while(scanf("%s",str)){
		if(strlen(str)==10)break;
		scanf("\n");
		gets(str);
		cout<<str<<endl;
		for(int i=0;str[i]!='\0';i++){
			if(str[i]<='Z'&&str[i]>='A'){
				putchar('A'+(str[i]-'A'-5+26)%26);
			}
			else putchar(str[i]);
		}
		puts("");
		scanf("%s\n",str);
	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxl 300
char decipher(char a){
    if (!isupper(a))return a;
    return (a - 'A' + (26 - 5)) % 26 + 'A';
}
int main(){
    while (1){
        char st[maxl];
        gets(st);
        if (st[0] == 'E')break;
        gets(st);
        int len = strlen(st);
        for(int i = 0; i < len; i++)
            putchar(decipher(st[i]));
        putchar('\n');
        gets(st);
    }
}
*/
