#include <stdio.h>
#include<math.h>

int differentiator(int a, int b);
// Precondition  : the lowest & the biggest number
// Postcondition : the biggest cycle length within range

int counter(int x);
// Precondition  : number within the input range
// POstcondition : cycle length of the specific number

int main()
{
    int a, b, x,  maxcycle;
    int count, temp, currentCycle;

    // != EOF (End of File) function
    // Mac Users : press ( ^ + D)
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
  // swap if range is entered in wrong order
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int maxCycle = 0;

    // check all the numbers within range
    // the largest cycle length would be saved into maxCycle
    // otherwise, keep calculating till the next largest one appears
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

// calculate each number's cycle length
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
