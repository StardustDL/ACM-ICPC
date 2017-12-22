/*
Óîº½Ô±
·ÖÎö£ºÄ£Äâ 
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int arr[6][6];
char direction[20];
void init(){
    arr[0][1]=2;arr[0][2]=4;arr[0][4]=5;arr[0][5]=1;
    arr[1][2]=0;arr[1][5]=3;arr[1][0]=5;arr[1][3]=2;
    arr[2][0]=1;arr[2][3]=4;arr[2][1]=3;arr[2][4]=0;
    arr[3][1]=5;arr[3][4]=2;arr[3][2]=1;arr[3][5]=4;
    arr[4][0]=2;arr[4][3]=5;arr[4][2]=3;arr[4][5]=0;
    arr[5][4]=3;arr[5][1]=0;arr[5][0]=4;arr[5][3]=1;
}
void cal(int &x,int &y,int &z,int pos,int step){
	switch(pos){
		case 0:x+=step;break;
		case 1:y+=step;break;
		case 2:z+=step;break;
		case 3:x-=step;break;
		case 4:y-=step;break;
		case 5:z-=step;break; 
	}
}
int main(){
    init();
    int n,x,y,z,pos,step,head,T,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        x=y=z=pos=0;
        head=2;
        while(n--){
            scanf("%s %d",direction,&step);
            switch(direction[0]){
            	case 'b':pos=(pos+3)%6;break;
            	case 'l':pos=arr[pos][head];break;
            	case 'r':pos=((arr[pos][head])+3)%6;break;
            	case 'u':t=pos;pos=head;head=(t+3)%6;break;
            	case 'd':t=pos;pos=(head+3)%6;head=t;break; 
			}
            cal(x,y,z,pos,step);
        }
        printf("%d %d %d %d\n",x,y,z,pos);
    }
    return 0;
}
