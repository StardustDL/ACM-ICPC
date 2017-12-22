/*
DOTA
*/
#include<stdio.h>
#include<string.h>
int main(){
	int n=0,i,m=0;
	char s[1000000];
	scanf("%s",&s);
	for(i=0;i<=sizeof(s)-1;i++)	{
		if(s[i]=='K')n++;
		else{
			if(n>m){m = n;}
			n = 0;
		}
	}
	switch(m){
		case 0:
		case 1:
		case 2:
			printf("You are a Foolish Man");
			break;
		case 3:
			printf("You are on a Killing Spree");
			break;
		case 4:
			printf("You are Dominating");
			break;
		case 5:
			printf("You have a Mega-Kill");
			break;
		case 6:
			printf("You are Unstoppable");
			break;
		case 7:
			printf("You are Wicked Sick");
			break;
		case 8:
			printf("You have a M-m-m-m....Monster Kill");
			break;
		case 9:
			printf("You are Godlike");
			break;
		default:
			printf("You are Beyond Godlike (Somebody kill him!)");
			break;
	}
	return 0;
}
