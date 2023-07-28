#include <iostream>
#include <string>

using namespace std;

//void printSeq(int * sequence, int size);
//void partition(S,p)

/*
 * This function contains an implementation of countSort using a arrays. Takes an array
 * of integers containing the user-input values as parameter. Uses three different arrays
 * "temp" arrays to perform count sort on input arr.
 */
void countSort(int * seq, int size) {
    int maxVal = 0;
    //find max val for count arr index boundary(must be less than 99)
    for (int i = 0; i < size; i ++) {
        if (seq[i] > maxVal) {
            maxVal = seq[i];
        }
    } //getMax
    //initialize countArr 0-MaxVal
    int countArr[maxVal];
    for (int i = 0; i < size; i++) {
        countArr[seq[i]] += 1;
    } //store count of each int in input seq
    //range is 1-99 - start from lower boundary
    for (int j = 1; j <= maxVal; j++) {
        countArr[j] += countArr[j-1];
    } // Get cumulative sum of counts for proper indexing
    int total[200];
    //get index of input seq in count arr and place in totalarr
    for (int k = size - 1; k >= 0; k--) {
        //cout << total[countArr[seq[k]] - 1] << ",";
        total[countArr[seq[k]] - 1] = seq[k];
        //decre count by 1
        countArr[seq[k]] -= 1;
    } //add sorted elements to input array
    for (int i = 0; i < size; i ++) {
        seq[i] = total[i];
        }
} // countSort

/*
 * Helper function that implements the partitionon used in quick sort implementation.
 */
int partition(int * S, int less, int greater) {
    //start index leftmost
    int temp = less;
    //Starting pivot from end of curr seq
    int pivot = S[greater];
    for (int j = less; j < greater; j++) {
        if (S[j] < pivot) {
            //if S[j] less pivot, swap.
            swap(S[temp], S[j]);
            //increment inital start index
                       temp++;
        }
    }
    //Swap pivot after iterating through sequence
    swap(S[temp], S[greater]);
    //return pivot index
    return temp;
} // partition

/*
 * This function contains an implementation of in-place quick sort using.
 * an array Takes the input array as a param and ranks of left and right
 * before reucrsion.
 */
void quickSort(int * seq, int l, int r) {
    //less and greater. all input elements are unique so no E..
    //class notes
    //(h, k) ¬ inPlacePartition(x)
    //inPlaceQuickSort(S, l, h - 1)
    //inPlaceQuickSort(S, k + 1, r)
    if (l < r) {
        int pivot = partition(seq, l, r);
        quickSort(seq, l, pivot - 1);
        quickSort(seq, pivot + 1, r);
    } // partition and recur
} // quickSort

/*
* Helper print array function after sorting fns are called.
*/
void printSeq(int * sequence, int size) {
    for (int i = 0; i < size; i++) {
        if (i < size-1) {
            cout << sequence[i] << ",";
        }
        else {
            //reached end of sequence no 'n' needed.
            cout << sequence[i] << endl;
        }
    } // for
} //printSeq

/*
 * Main method for handling user input, and calling both of the sorting
 * functions.
 */
int main() {
    cout << "Enter elements (integers) one by one, each on their own line:" << endl;
    int i = 0;
    //fixed size input stated via Code05 on elC.
    const int size = 16;
    //two input arrays, one for each sorting method to display function.
    int sequence[16];
    int sequence2[16];
    //Handle user input
    while (i < 16) {
        cin >> sequence[i];
        sequence2[i]=sequence[i];
        i++;
    }
    //first sorting algorithm, quick sort O(n*logn) linearithmic average time.
    //printSeq(sequence, size);
    cout << "Result from first sorting algorithm (quick sort):" << endl;
    int left = 0; int right = size-1;
    quickSort(sequence, left, right);
    printSeq(sequence, size);
    //second sorting algorithm, counting sort O(n log n) linear average run time.
    //using sequence2 as input arr because it hasnt been sorted yet.
    //printSeq(sequence2,size);
    cout << "Result from second sorting algorithm (counting sort):" << endl;
    countSort(sequence2, size);
    printSeq(sequence2, size);
    return 0;
} // main



  

 