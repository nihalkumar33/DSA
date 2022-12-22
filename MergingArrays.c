#include<stdio.h>
#include<stdlib.h>

void MergingArrays(int *A, int *B, int *p, int l1, int l2)
{
    int i=0, j=0, k=0, var;     //i is for A, j is for B, k is for SortedArray, var is for comparing
    while (i<l1 || j<l2)
    {   //We will check which of the list is smaller or the one which reaches to the end early.
        int large;
        large = (l1==l2)?(-1):((l1>l2)?(1):(0));    //1:l1>l2, 0: l1<l2, -1: l1=l2
        
        if (large == 1)       //If elements in A are remaning.
        {
            *(p+k) = *(A+i);
            k++; i++;
        }

        else if (large == 0)        //If elements in B are remaning.
        {
            *(p+k) = *(B+j);
            k++; j++;
        }

        else        //If both array's last elements are remaning.
        {
            
        }
        if (i != l1-1 && j != l2-1)     //This will execute until no list have reached to its end.
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
                *(p+k) = *(A+i);
                *(p+k+1) = *(B+j);
                printf("%d %d Check the values: \n", *(p+k), *(A+i));
                k++; i++; j++;
            }
        }
    }
}

int main()
{
    int A[] = {1, 4, 6, 7, 16, 100};
    int B[] = {5, 9, 12, 15, 20, 30};
    int l1 = 6, l2 = 6;

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