# DSA
About MergingArrays()
In that functon if the length of arrays is same then it gets executed until the last second last elememt, but prints garbage value 
in place of the last element(the biggest one)
Now that is because for the last element the loop condition becomes false and thus no valuse assignment for the last address of array.

Now this funcution also gets messed up if length of array varies.
I think that the core logic of the program is correct but it is not used properly.
here we can add some condition on the loop such that it will execute until any one array comes to it's end and after that it is known that all
the left elements of next array are in order and greater than earlier elements, so just need to copy those elements to the final array.
