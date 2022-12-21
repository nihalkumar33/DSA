/*
//To make 2D arrays using pointers to pointers.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i, j;
    int **arr = (int **)malloc(3*sizeof(int));
    //Now an pointer 'arr' to array of pointers is ready. 
    //Now I can store adresses in this array.
    //Those addresss can be pointing towards different arrays.

    arr[0] = (int *)malloc(3*sizeof(int));
    arr[1] = (int *)malloc(3*sizeof(int));
    arr[2] = (int *)malloc(3*sizeof(int));

    //Now here a 2D array of 3x3 is ready.
    //Here all arrays are stored in heaps, due to usage of malloc.
    //initialisation of 2D array.
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            arr[i][j] = i;
        }
    }
    //Printing the whole array.
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    //Now in the case when we use malloc we should always de allocate
    //the memory when once it's use is over.
    free(arr);
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
//To increase he size of array indirectly.
int main()
{
    int *arr_1 = (int *)malloc(3*sizeof(int));
    int i;

    for(i=0; i<3; i++)  //Array initialisation.
    {
        arr_1[i] = i;
    }

    int *arr_2 = (int *)malloc(5*sizeof(int));
    
    for (i=0; i<3; i++) //Coping complete 1st array in 2nd array.
        arr_2[i] = arr_1[i];

    free(arr_1);        //Deleting the old occupied memory.
    arr_1 = arr_2;      //arr_1 should point to the new array.
    arr_2[3] = 3; arr_2[4] = 4;
    arr_2 = NULL;       //Removing pointer arr_2 form the new array.

    for (i=0; i<5; i++) //Printing the array.
        printf("%d ", arr_1[i]);

    return 0;
}

//Using arrays as ADT.
#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int lenght;
};

int main()
{
    struct Array arr; int i;
    printf("Enter the size of array: ");
    scanf("%d", &arr.size);

    printf("Enter the length of array: \n");
    scanf("%d", &arr.lenght);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter all the elements of array: ");

    for (i=0; i<arr.lenght; i++)
    {
        scanf("%d", arr.A + i);
    }

    printf("printing all elements of the arrays: \n");
    for (i=0; i<arr.lenght; i++)
    {
        printf("%d ", *(arr.A+i));
    }
    return 0;
}
*/

//Using arrays as ADT's with proper operations.
#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;     //Pointer to the allocated memory in heap as array.
    int size;       //The size of array being entered by user.
    int length;     //The number of elements stored in our array.
}arr;

void display()      //To display all elements of array.
{
    printf("\nDisplaying all the elements of arrays:\n");
    int i;
    for (i=0; i<arr.length; i++)
    {
        printf("%d ", *(arr.A + i));
    }
    printf("\n");
}

void append(int x)       //To add x at the end of array.(just at arr.length).
{
    if (arr.length==arr.size)
        printf("No appending can be done the array is full. \n");
    
    else
    {
        arr.A[arr.length] = x;
        arr.length++;
    }
}

void insert(int index, int x)       //To insert 'x' at 'index', remember to increase length.
{
    int i;

    if (arr.length==arr.size)
        printf("No insertion can be done, array is full.\n");
    
    else
    {
        for (i=arr.length; i>index; i--)        //Shifting elements to insert x at index.
        {
            arr.A[i] = arr.A[i-1];
        }

        arr.A[index] =x;
        arr.length++;
    }
}

int linear_search(int key)      //Linear search with Transposition.
{
    int i, t;
    for (i=0; i<arr.length; i++)
    {
        if (key == arr.A[i])
        {
            if (i != 0)
            {
            t = arr.A[i-1];
            arr.A[i-1] = arr.A[i];
            arr.A[i] = t;
            return (i-1);
            }
            return 0;
        }
    }
    return -1;
}

int BinarySearch(int l, int h, int key)
{
    if (l<=h)
    {
        int m = (l+h)/2;
        if (key == arr.A[m])
            return m;

        else if (key > arr.A[m])
        {
            l = m;
            BinarySearch(l, h, key);
        }
        
        else
        {
            h = m;
            BinarySearch(l, h, key);
        }
    }
    else
        return -1;
}

void delete(int index)      //To delete the element at 'index'.
{
    int i;
    for (i=index; i<(arr.length-1); i++)
    {
        arr.A[i] = arr.A[i+1];
    }
    arr.length--;
}

int max()
{
    int max = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++)
    { 
        if (max <arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int sumR(int index)
{
    if (index>=0)
    {
        printf("%d \n", arr.A[index] + sumR(index - 1));
        return(arr.A[index] + sumR(index - 1));
    }
} 

void reverse1(int i, int j)      //Using simultaneous iteration from both ends.
{
    int var; 
    for (; i<j; )
    {
        var = *(arr.A + i);
        *(arr.A + i) = *(arr.A + j);
        *(arr.A + j) = var;
        i++; j--;
        //reverse1(i++, j--);
    }
}

void Rotate()        //To rotate an array by one unit to LHS.
{
    int var = arr.A[0]; int i;
    for (i=0; i<arr.length-1; i++)
    {
        arr.A[i] = arr.A[i+1];
    }
    arr.A[arr.length-1] = var;
}

void Rotate2O(int shift)
{
    int *cpy = (int *)malloc(shift * sizeof(int));      //For an aribatary array.
    int i;
    for (i=0; i<shift; i++)       //For copying initial elements to aribatary array.
    {
        *(cpy + i) = arr.A[i];
    }

    for (i=0; i<arr.length-shift; i++)     //To shift the elements by 'shift'.
    {
        arr.A[i] = arr.A[i+shift];
    }

    for (i=shift; i>0; i--)     //To copy the initial elements to orijnal array, at new posiions.
    {
        arr.A[arr.length-i] = *(cpy + shift - i);
    }
}

void InsertNum(int num)        //To insert a number in a sorted array.
{
    if (arr.size > arr.length)
    {
        int i; int index;
        for (i=0; i<arr.length; i++)     //To check the correct index for the number to be inserted.
        {
            if (arr.A[i] > num)
            {
                index = i;
                break;
            }
        }

        for (i=arr.length - 1; i>=index; i--)      //Creating space for num at 'index'.
        {
            arr.A[i+1] = arr.A[i];
        }
        arr.length++;

        arr.A[index] = num;     //Num is inserted in a sorted list.
    }

}

int sorted()
{
    int i; int flag=-1;
    for (i=0; i<arr.length; i++)
    {
        if (arr.A[i] < arr.A[i+1])
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void shift(int index)
{
    for (; index>=0; index--)
    {
        arr.A[index] = arr.A[index - 1];
    }
}

void l_neg()
{
    int i; int var;
    for (i=0; i<arr.length; i++)
    {
        if (arr.A[i] < 0)
        {
            var = arr.A[i]; b
            shift(i);
            arr.A[0] = var;
        }
    }
}

void neg_2()        //To move all the negative elements to LHS, and +ve to RHS.
{
    int i=0, j=arr.length-1;
    while (i<j)
    {
        int var;        //To swap the elements.
        var = arr.A[i];
        arr.A[i] = arr.A[j];
        arr.A[j] = var;

        if (arr.A[i] < 0)
            i++;
        if (arr.A[j] > 0)
            j--;
    }
}

int main()
{
    int i, inp, index, var; int num;

    printf("Enter the size of array: ");
    scanf("%d", &arr.size);     //User input for size of array.

    arr.A = (int *)malloc(arr.size * sizeof(int));      //Allocating contigious memory in heap.

    printf("Enter the number of elements to be initially inserted in array: ");
    scanf("%d", &arr.length);       //Declaring the size of array.(can be changed further).

    printf("Enter the elements: \n");
    for (i=0; i<arr.length; i++)        //Inserting data in array, (n = arr.length).
    {
        scanf("%d", (arr.A + i));
    }

    //printf("Enter the Number to  be appended: ");
    //scanf("%d", &inp);
    //append(inp);        
    //display();

    //printf("Enter the index and number for inserting: ");
    //scanf("%d %d",&index, &inp);
    //insert(index, inp);
    //display();

    //printf("Enter the index to be deleted: ");
    //scanf("%d", &inp);
    //delete(inp);
    //display();
    
    //printf("The maximum of the given array is: %d", max());
    //printf("Sum of all elements of the array is : %d, %d", sumR(arr.length-1), arr.length);
    //printf("Enter the number to be inserted: ");
    //scanf("%d", &num);
    display();
    neg_2();
    //printf("Just for check");
    display();

    return 0;
}
