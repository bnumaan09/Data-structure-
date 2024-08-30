//program to generate leucas series: 1,1,1,3,5,9,17
# include <stdio.h>

 int leucas(int n)
{
    if(n == 1 || n == 2 || n== 3)
        return 1;
    else
        return leucas(n -3) + leucas(n - 2) + leucas(n - 1);    
}

int main()
{
    int n;
    for(int i = 1; i <= 10; i++)
    {
        int d = leucas(i);
        printf("%d\t", d);
    }
}