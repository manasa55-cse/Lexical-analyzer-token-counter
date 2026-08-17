#include <stdio.h>

int main()
{
    int x = 15;
    int y = 5;
    int result;

    result = x * y;

    if (result > 50)
    {
        printf("Result is greater than 50");
    }
    else
    {
        printf("Result is less than or equal to 50");
    }

    return 0;
}
