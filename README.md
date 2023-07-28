# QuickSort
 Description:
    This program takes 16 integers via user input. The user should enter
    each integer, line by line. After the 16 integers are received (and stored in,
    two separate arrays], the program calls the first sorting method. I decided to implement quick
    quick sort after struggling with merge sort. Quick sort runs in linearithmic O(n*logn)
    average time. I broke quick sort into two functions, partition and quickSort as
    the professor showed us in class. The program then displays the sorted sequence
    to the user. Next the program calls my implementation of counting sort. Counting
    sort runs in linear O(n) average time. After the elements are sorted, it prints the
    sorted sequence. I decided to use two input arrays, one for each sorting method to
    display both algorithms are having to sort unsorted input.

    How to compile my program:
    g++ Sorting.cpp -o Sorting.out