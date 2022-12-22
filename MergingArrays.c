#include<stdio.h>
#include<stdlib.h>

void MergingArrays(int *A, int *B, int *p, int l1, int l2)
{
    int CheckEnd=-1;       //Tells that which array have reached to it's end.
    int i=0, j=0, k=0, var;       //i is for A, j is for B, k is for SortedArray, var is for comparing
    
    while (i<l1 && j<l2)        //Until one array is finished this will exe.
    {
        var = (*(A+i) == *(B+j))?(-1):((*(A+i)>*(B+j))?(1):(0));
        //var will have -1 if both nos are same
        //1 if A[] is bigger.
        //0 if B[] is bigger.

        if (var == 1)
        {
            *(p+k) = *(B+j);
            k++; j++;
        }
        else if (var == 0)
        {
            *(p+k) = *(A+i);
            k++; i++;
        }
        else
        {
            *(p+k) = *(A+i); k++;
            *(p+k) = *(B+j);
            k++; i++; j++;
        }

        CheckEnd = (i==l1 && j==l2)?(0):((i==l1)?(1):((j==l2)?(2):(-1)));
        //0: Both arrays have reached its end, 1: A has reached end, 2: B has reached it's end.
    }

    if (CheckEnd == 0)
    {
        int var;
        var = (*(A+i)>*(B+j))?(*(A+i)):(*(B+j));
        *(p+k) = var;
    }

    else if (CheckEnd == 1)
    {
        while (j<l2)
        {
            *(p+k) = *(B+j);
            j++; k++;
        }
    }
    else if (CheckEnd == 2)
    {
        while (i<l1)
        {
            *(p+k) = *(A+i);
            i++; k++;
        }
    }
}

int main()
{
    int A[] = {2000};
    int B[] = {0, 1000};
    int l1 = 1, l2 = 2;

    int *p;
    p = (int *)malloc((l1 + l2)*sizeof(int));       //Creating space for Sorted Array.

    MergingArrays(A, B, p, l1, l2);

    int i;
    for (i=0; i<(l1+l2); i++)
    {
        printf("%d\t", *(p+i));
    }
    return 0;
}
