/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
FILE *in,*out;
char str[100];
int main(){
	srand(time(0));
	while(1){
		int rd=rand();
		sprintf(str,"data.exe %d",rd);
		//cout<<str<<endl;
		system(str);
		puts("Violent:");
		system("vio.exe");
		puts("Program:");
		system("pro.exe");
		
		if(system("fc vio.out pro.out")){
			system("pause");
		}
	}
	return 0;
}

