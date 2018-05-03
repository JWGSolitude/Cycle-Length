#include <stdio.h>
#include <math.h>

int differentiator(int a, int b);
int counter(int x);

int main()
{
    int a, b;
    printf("input 2 numbers between 0 - 1000,000\n");
    
    while (scanf("%d %d", &a, &b) != EOF)
    {
        if(a <=0 || a >= pow(10,6))
        {
            return 0;
        }
        
        if( b<=0 || b >= pow(10,6))
        {
            return 0;
        }
        printf("%d %d %d\n", a, b, differentiator(a, b));
    }
    return 0;
}


int differentiator(int a, int b)
{
    
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int maxCycle = 0;
    
    for (; a <= b; a++)
    {
        
        int currentCycle = counter(a);
        if (currentCycle > maxCycle)
        {
            maxCycle = currentCycle;
        }
    }
    return maxCycle;
}


int counter(int x)
{
    int count = 1;
    
    while (x != 1)
    {
        if (x % 2 == 0)
        {
            x /= 2;
        }
        else
        {
            x = x * 3 + 1;
        }
        count++;
    }
    return count;
}
