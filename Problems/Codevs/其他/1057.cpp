/*
½ò½òµÄ´¢Ðî¼Æ»®
*/ 
#include<stdio.h>
int main(){
	int i,k,save=0,left=0;
	bool b = true;
	for(i=0;i<12;i++){
		left +=300;
		scanf("%d",&k);
		left -=k;
		if(left<0){
			printf("-%d",i+1);
			b = false;
			break;
		}
		save += (left/100)*100;
		left -= (left/100)*100;
	}
	if(b)printf("%d",save*12/10+left);
	return 0;
}
