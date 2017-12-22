/*
Balloon Comes!
*/
#include<cstdio>
int main(){
    int t,a,b;
    char m[2];
    scanf("%d",&t);
    while(t--){
		scanf("%s%d%d",m,&a,&b);
		if(m[0]=='+') printf("%d\n",a+b);
		else if(m[0]=='-') printf("%d\n",a-b);
        else if(m[0]=='*') printf("%d\n",a*b);
        else if(a/b*b==a) printf("%d\n",a/b);
        else printf("%.2f\n",(double)a/b);
    }
    return 0;
}

