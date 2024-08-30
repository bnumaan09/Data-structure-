//program to convert decimal number to base b <= 20
# include <stdio.h>

void convert(int num, int b)
{   
    int r;
    if(num == 0)        printf("\t");
    else
    {
        r = num % b;
        convert(num / b, b);
        if(r >= 0 && r <=9 )
            printf("%d", r);
        else if(r == 10)
            printf("A");
        else if(r == 11)
            printf("B");
        else if(r == 12)
            printf("C");
        else if(r == 13)
            printf("D");
        else if(r == 14)
            printf("E");
        else if(r == 15)
            printf("F"); 
        else if(r == 16)
            printf("G");
        else if(r == 17)
            printf("H");
        else if(r == 18)
            printf("I");
        else if(r == 19)
            printf("J");
        else if(r == 20)
            printf("K");
     }    
}
int main()
{
    int b,num;
    printf("Enter the value of decimal number and base to which to be converted \n");
    scanf("%d %d", &num, &b);
    convert(num, b);
}