# include <stdio.h>

int sum(int num)
{   
    int r;
    if(num == 0)
        return 0;
    else
    {
        r = num % 10;
        return r + sum(num/10);
    }    
}
int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);

    int s = sum(num);
    printf("Sum of digits of the entered number is: %d\n", s);


}