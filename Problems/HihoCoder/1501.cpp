#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
int n,l;
char str[105];
inline bool issnake(){
    for(int i=0;i<l;i++)if(str[i]=='_')return true;
    return false;
}
inline int outSnake(int i){
    int cnt=0;
    for(;i<l;i++){
        if(isupper(str[i])){
            if(cnt==0){
                cnt=1;putchar(tolower(str[i]));
            }
            else{putchar('_');return i;}
        }
        else putchar(str[i]);
    }
    return l;
}
inline int outCamel(int i){
    putchar(i>0?toupper(str[i]):str[i]);
    for(++i;i<l;i++){
        if(str[i]=='_')return i+1;
        putchar(str[i]);
    }
    return l;
}
inline void output(int(*ou)(int)){
    for(int i=0;i<l;)
        i=ou(i);
    puts("");
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        l=strlen(str);
        if(issnake())output(outCamel);
        else {str[0]=toupper(str[0]);output(outSnake);}
    }
    return 0;
}