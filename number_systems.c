#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//#include <stdlib.h>
//
void input(long long*first,short*from,short*to){
    long long first2;
    short from2,to2;
    printf("This programm is converting numbers from 2/8/10 to 10/8/2\n");
    printf("Input number who will be converting :\n>");
    scanf("%lld",&first2);
    printf("His number system :\n>");
    scanf("%hd",&from2);
    printf("Output number system :\n>");
    scanf("%hd",&to2);
    *first=first2;
    *from=from2;
    *to=to2;
}
//
long long convertBinaryToDecimal(long long n){
    long long res=0,base=0;
    while(n!=0){
        if(n&1)
            res+=pow(2,base);
        n/=10;
        ++base;
    }
    return res;
}
//
long long convertDecimalToBinary(long long n){
    long long res=0,remainder,i=1;
    while(n!=0){
        remainder=n%2;
        n/=2;
        res+=remainder*i;
        i*=10;
    }
    return res;
}
//
long long convertDecimalToOctal(long long n){
    long long res=0,remainder,i=1;
    while(n!=0){
        remainder=n%8;
        n/=8;
        res+=remainder*i;
        i*=10;
    }
    return res;
}
//
long long convertOctalToDecimal(long long n){
    long long res=0,base=0,remainder;
    while(n!=0){
        remainder=n%10;
        res+=remainder*pow(8,base);
        n/=10;
        ++base;
    }
    return res;
}
//
long long convertOctalToBinary(long long n){
    return convertDecimalToBinary(convertOctalToDecimal(n));
}
//
long long convertBinaryToOctal(long long n){
    return convertDecimalToOctal(convertBinaryToDecimal(n));
}
//
int main(void){
    long long first,finally;
    short from,to;
    bool again=true;
    short flag;
    while(again){
        input(&first,&from,&to);
        switch(from)
        {
        case 2:
            if(to==8)
                finally=convertBinaryToOctal(first);
            else
                finally=convertBinaryToDecimal(first);
            break;
        case 8:
            if(to==2)
                finally=convertOctalToBinary(first);
            else
                finally=convertOctalToDecimal(first);
            break;
        case 10:
            if(to==2)
                finally=convertDecimalToBinary(first);
            else 
                finally=convertDecimalToOctal(first);
            break;

        default:
            printf("Uncorrect value for 'to'\n");
            break;
        }
        printf("result = %lld\n",finally);
        printf("do you continue ?(0||1)\n>");
        scanf("%hd",&flag);
        if(flag==0)
            again=false;
        
    }
    return 0;
}

