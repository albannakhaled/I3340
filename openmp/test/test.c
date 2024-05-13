#include <stdio.h>
#define MAX 20
int main()
{
    int tab[100000] ;
    for (int i = 0; i < 100000; i++)
    {
        tab[i] = i % 7;
    }
    for (int i = 0; i < 100000; i++)
    {
        printf("%d\n",tab[i]);
    }
    
    
    return 0;
}