#include <stdio.h>



int main()
{
    int totalNum, finalAnswer;
    scanf("%d", &totalNum);
    
    int source[totalNum];
    
    for (int i=0; i<totalNum ; i++)
    {
        int num;
        scanf("%d", &num);
        source[i] = num;
    }
    
    if (totalNum == 1) printf("%d", source[0]);
    else
    {
        long long int temp[2], x;
        temp[0] = source[totalNum - 2] * source[totalNum - 1] + 1;
        temp[1] = source[totalNum - 1];

        if (totalNum > 2)
        {
            for (int i = totalNum - 3; i >= 0; i--)
            {
                x = temp[0];
                temp[0] = (source[i]) * temp[0] + temp[1];
                temp[1] = x;
            }
        }

        printf("%lld/%lld",temp[0],temp[1]);
    }
    
    return 0;
}
