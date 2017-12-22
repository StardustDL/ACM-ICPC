/*
题意：定义一种新的进制。在这种进制下，一个数的每个数位，从低位数起第k位，分别代表2^(k+1)-1。并且，在这种进制下，一个数的每个数位只会是0或者1，除了非0的最低位，即若一个数某个数位为2，则该数位后的所有数位均为0。现给定一个新进制下的数，问这个数转换成十进制是多少。
分析：模拟，网上这份代码的技巧不错 
*/
#include<cstdio>
#include<cstring>
char skew[32];
int main(){
    while(scanf("%s", skew),strcmp(skew,"0")){
        int len=strlen(skew),ans=0;
        for(int i=0;i<len;i++)ans+=(skew[i]&15)*((1<<len-i)-1);
        printf("%d\n",ans);
    }
    return 0;
}

