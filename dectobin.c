# include <stdio.h>

void Binary(int num)
{   
    int r;
    if(num == 0)
        printf("\t");
    else
    {
       r = num % 2;
       Binary(num / 2);
       printf("%d", r);
    }    

}
int main()
{
    int num = 8;
    Binary(num);
}