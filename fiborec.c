# include <stdio.h>
int fibo(int n)
{
    if(n ==1 || n ==2)
        return 1;
    else
        return fibo(n - 2)+ fibo(n - 1);   
}

int main()
{
    int n;
    //printf("Enter which term of the fibonacci series is required\n");
   // scanf("%d", &n);

    //int f = fibo(n);
    //printf("Term number %d of the Fibonacci series is: %d\n", n, f);

    printf("First 10 terms of the Fibonacci series are: \n");
    for(int i = 1; i <=10; i++)
    {   
        int p = fibo(i);
        printf("%d\t", p);
    }
}