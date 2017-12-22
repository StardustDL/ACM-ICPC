#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int f(char a[]){    // 返回对应的月份
    for (int i = 0; i < 12; i ++)
        if (strcmp(a,month[i])==0)return i+1;
}
LL sY,eY,sD,eD,sM,eM;
char str[20];
int main(){
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        scanf("%s %lld, %lld",str,&sD,&sY);sM=f(str);
        scanf("%s %lld, %lld",str,&eD,&eY);eM=f(str);
        if(sM==1 || sM==2 && sD<=29)sY--;
        if(eM==1 || eM==2 && eD<29) eY--;
        printf("Case #%d: %lld\n",i,
            (eY/4-sY/4) - (eY/100-sY/100) + (eY/400-sY/400));
    }
    return 0;
}