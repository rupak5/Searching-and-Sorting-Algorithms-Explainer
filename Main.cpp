#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include<unistd.h>

using namespace std;

void intro(int no);

void example(int no);

void linear_search(vector<int> sequence , int required_number);

void jump_search(vector <int> sequence, int requied_number);

void bsearch(vector <int> ar, int item);

void interpolation_search(vector<int> A, int num);

void selection_sort(vector<int> &A);

void insertion_sort(vector<int> a);

void bubble_Sort(vector<int> sequence);

void merge(vector<int> &a, int str, int end);

void merge_sort(vector<int> &a, int str, int end);

int main()
{
	cout << "\t" << "Hello Folks\n\n";
	cout << "\t" << "Welcome to our C++ project\n\n";
	cout << "\t" << "" << "SEARCHING AND SORTING ALGORITHMS FOR BEGINNERS \n\n";
start:
	cout << "\t" << "SEARCHNG" << setw(38) << "SORTING" << "\n\n";
	cout << "\t" << "Type 1 for searching algo or type 2 for sorting algo\n";
	int which_algo;
	cin >> which_algo;
	if (which_algo == 1)
	{
		cout << "-> Linear Search(0)\n-> Jump Search(1)\n-> Bimary Search(2)\n-> Interpolation Search(3)\n\n";
		cout << "Which Searching algorithm you want to learn?\nEnter the number which is at last of algorithm name.\n";
	}
	else if (which_algo == 2)
	{
		cout << "-> Selection Sort(0)\n-> Insertion Sort(1)\n-> Bubble Sort(2)\n-> Merge Sort(3)\n\n";
		cout << setw(82) << "Which sorting algorithm you want to learn?\nEnter the number which is at last of algorithm name.\n";
	}
	else
	{
		cout << setw(65) << "invalid output\n";
		goto start;
	}
	int inpt;
	cin >> inpt;
	if (inpt > 3 || inpt < 0)
	{
		cout << "Invalid Input\n";
		goto start;
	}
	if (which_algo == 2)
	{
		inpt += 4;
	}
	intro(inpt);
	vector<int> in;
	int srchnum = 0;
	int na;
	cout << "\nEnter the size of your sequence.\n";

	cin >> na;
	cout << "\nEnter a sequence separated by spaces and then press enter.\n";
	for (int i = 0; i < na; ++i)
	{
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	if (which_algo == 1)
	{
		cout << "\nEnter element to be searched.\n\n";

		cin >> srchnum;
	}
	switch (inpt)
	{
	case 0:
		linear_search(in, srchnum);
		break;
	case 1:
		jump_search(in, srchnum);
		break;
	case 2:
		sort(in.begin(), in.end());
		bsearch(in, srchnum);
		break;
	case 3:
		interpolation_search(in, srchnum);
		break;
	case 4:
		selection_sort(in);
		break;
	case 5:
		insertion_sort(in);
		break;
	case 6:
		bubble_Sort(in);
		break;
	case 7:
		merge_sort(in, 0, in.size() - 1);
		break;
	}
predex:
	usleep(2000000);
	cout << "\n\nWould you like to understand the algorithm with a predefined example?\nType 1 for 'Yes' or 0 for 'No'.\n";
	int wantex;

	cin >> wantex;
	if (wantex == 1)
		example(inpt);
	else if (wantex != 0 && wantex != 1)
	{
		cout << "\nInvalid Input\n";
		goto predex;
	}
wanmore:
	usleep(2000000);
	cout << "\nWould you like to learn more?\nType 1 for 'Yes' or 0 for 'No'.\n";
	int wantmore;

	cin >> wantmore;
	if (wantmore == 1)
		goto start;
	else if (wantmore == 0)
	{
		cout << "\n\t\tThanks for learning from us.\n\n\t\tWe had fun teching you ;-)\n\n";
	}
	else
	{
		cout << "Invalid Input\n";
		goto wanmore;
	}
}

void intro(int no)
{
	switch (no)
	{
	case 0:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nLINEAR SEARCH :- \n\n";
		cout << "Linear search is a very simple search algorithm.\n";
		cout << "In this type of search, a sequential search is made over all items one by one,\n";
		cout << "Every item is checked and if a match is found then that particular item is returned,\n";
		cout << "otherwise the search continues till the end of the data collection.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 1:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nJUMP SEARCH :- \n\n";
		cout << "Jump Search is a searching algorithm for sorted arrays.\n";
		cout << "The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps\n";
		cout << "or skipping some elements which is equal to the square root of the size of array, in place of searching all elements\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 2:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nBINARY SEARCH:-";
		cout << "\n Search a sorted array by repeatedly dividing the search interval in half.";
		cout << "\n The array need to be sorted to perform binary search.";
		cout << "\n\n We basically ignore half of the elements just after one comparison.";
		cout << "\n1. Compare x with the middle element.";
		cout << "\n2. If x matches with middle element, we return the mid index.";
		cout << "\n3. Else If x is greater than the mid element, then x can only lie in right half";
		cout << "\n4. subarray after the mid element. So we recur for right half.";
		cout << "\n5. Else (x is smaller) recur for the left half.";
		cout << "\n6. some basic formula:- to calculate middle index=(beginning index +last index)/2";
		cout << "\n   during recursion:- if mid value < search element -> beginning=(middle index+1)";
		cout << "\n\t\t   :- if mid value > search element -> last=(middle index-1)\n\n";
		cout << "--------------------------------------------------------------------------------------------";
		break;
	case 3:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nINTERPOLATION SEARCH :- \n\n";
		cout << "Interpolation search is an improvement over binary search.\n";
		cout << "Binary Search always checks the value at middle index. But, interpolation search may check at different locations based on the value of element being searched.\n";
		cout << "For interpolation search to work efficiently the array elements/data should be sorted and uniformly distributed.\n";
		cout << "In Interpolation Search we have a formula from where we start searching\n";
		cout << "Formula is:\n\n";
		cout << "pos = start + [ ((end - start)/A[end] - A[start]) * (e - A[start]) ]\n\n";
		cout << "where\nstart = Starting Index of sequence\nend = Last Index of sequence\ne = Element to be searched\nA[start] and A[end] = Element at start and end index\n\n";
		cout << "At first we make start = 0 and end = n-1.\n";
		cout << "If A[pos] == e, element found at index pos\n";
		cout << "Otherwise if e > A[pos] we make start = pos + 1\n";
		cout << "Else if e < A[pos] we make end = pos - 1\n";
		cout << "Let's understand Interpolation Search with an example of your choice.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 4:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nSELECTION SORT:-\n\n";
		cout << "The selection sort algorithm sorts an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning.\n";
		cout << "Let's understand Selection Sort by an example of your choice.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 5:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nINSERTION SORT:-\n\n";
		cout << "In insertion sort,each successive element is picked and inserted at an appropriate position in the previously sorted array.";
		cout << "\nIt is efficient for smaller data sets, but very inefficient for larger lists.";
		cout << "\nThe insertion sort is also used when there are only a few elements left to be sorted\n";
		cout << "--------------------------------------------------------------------------------------------";
		break;
	case 6:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nBUBBLE SORT :- \n\n";
		cout << "Bubble sort is a simple sorting algorithm.\n";
		cout << "This sorting algorithm is comparison-based algorithm in which each pair\n";
		cout << "of adjacent elements is compared and the elements are swapped if they are not in order.\n";
		cout << "This algorithm is not suitable for large data sets as its average and worst case complexity\n";
		cout << "are of Ο(n^2) where n is the number of elements in the sequence.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 7:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nMERGE SORT :- \n\n";
		cout << "Merge Sort is a Divide and Conquer algorithm.\n";
		cout << "It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.\n";
		cout << "The merge() function is used for merging two halves.\n";
		cout << "Let's Understand Merge Sort with an example of your choice.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	}
}

void example(int no)
{
	switch (no)
	{
	case 0:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nLet us consider a simple example to understand Linear Search :\n\n";
		cout << "consider a sequence like\n ";
		cout << "\t\t\t   |1| |2| |3| |4| |5| |6| |7| |8| |9| |10|\n\n";
		cout << "If you want to determine the positions of the occurrence of the number 7 in this array.\n";
		cout << "To determine the positions, every element in the array from start to end, i.e.,\n";
		cout << "from index 1 to index 10 will be compared with number 7, to check which element matches the number 7.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 1:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nLet us consider a simple example to understand Jump Search :\n\n";
		cout << "Let us consider the following sequence:\n";
		cout << "\t\t\t (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610).\n";
		cout << "Length of the sequence is 16. Jump search will find the value of 55 with the following steps\n";
		cout << "assuming that the block size to be jumped is 4( jump size=sqrt(16) ) :-\n\n";
		cout << "STEP 1: Jump from index 0 to index 4\n";
		cout << "STEP 2: Jump from index 4 to index 8\n";
		cout << "STEP 3: Jump from index 8 to index 12\n";
		cout << "STEP 4: Since the element at index 12 is greater than 55 we will jump back a step to come to index 8.\n";
		cout << "STEP 5: Perform linear search from index 8 to get the element 55.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 2:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\n\n Let consider an array (must be sorted)";
		cout << "\n 10 12 14 21 23 28 31 37 42 44 49 53";
		cout << "\n lets find out position of 44\n";

		cout << "\n STEP 1-";
		cout << "\n\t here we have beginning=0   last=11   mid=(0+11)/2=5  data[5]=28";
		cout << "\n\t since data[5]=28 not equal to search element(44) and 28<44";
		cout << "\n\t therefore beginning=mid+1=6";
		cout << "\n\t now beginning=6 , last=11  => 31 37 42 44 49 53";

		cout << "\n STEP 2-";
		cout << "\n\t here we have beginning=6   last=11   mid=(6+11)/2= 8.5 =8  data[8]=42";
		cout << "\n\t since data[8]=42 not equal to search element(44) and 42<44";
		cout << "\n\t therefore beginning=mid+1=9";
		cout << "\n  now beginning=9 , last=11  => 44 49 53";

		cout << "\n STEP 3-";
		cout << "\n\t here we have beginning=9   last=11   mid=(9+11)/2= 10  data[10]=49";
		cout << "\n\t since data[10]=49 not equal to search element(44) and 49>44";
		cout << "\n\t therefore last=mid-1=10-1=9";
		cout << "\n  now beginning=9 , last=19  => 44 ";

		cout << "\n STEP 4-";
		cout << "\n\t here we have beginning=9   last=9   mid=(9+9)/2= 9 =9  data[9]=44";
		cout << "\n\t since data[9]=44 is equal to search element(44) ";
		cout << "\n\n element 44 is found at index 9 and at position 10";
		cout << "--------------------------------------------------------------------------------------------";
		break;
	case 3:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "Consider a sequence {1, 2, 4, 6, 7, 10, 11, 14, 15} and we have to search 4 in it.\n\n";
		cout << "So start = 0 and end = 8, by formula we get pos = 1.71. We consider floor so we get pos = 1.\n\n";
		cout << "Now we check whether e and element at indexd 1 are equal, which comes out that they are not.\n\n";
		cout << "As e > A[pos] we make start = pos+1 = 2.\n\n";
		cout << "Now with start = 2 and end = 8 we get pos = 2 and value 4 which is the value we wanted to search.\n\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 4:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "Consider a Sequence {8, 4, 9, 6, 3}\n\n";
		cout << "Now the algorithm will traverse through all the elements of the sequnce to find the smalllest element and will replace it with element at 0th index.\n\n";
		cout << "The sequence would become {3, 4, 9, 6, 8}.\n\n";
		cout << "The same process will happen but now the next lowest term and element at index 1 will be replaced to get a sequence {3, 4, 9, 6, 8}.\n\n";
		cout << "Here no replacement took place because 4 was the smallest among the elemnts next to it.\n\n";
		cout << "The same process will continue like this:\n\n";
		cout << "{3, 4, 9, 6, 8}-->{3, 4, 6, 9, 8}-->{3, 4, 6, 8, 9}\n\n";
		cout << "As the algorithm reaches last element, it will get terminated and we will get our sorted sequence.\n\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 5:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nLets us consider an unsorted array:-\n";
		cout << "\n\t 12 11 13 5 7\n";
		cout << "\nProcedure will always start from second element.";
		cout << "\n\nStep 1:-\n";
		cout << "\n for given array,compare 11 with 12(left adjacent element).The comparision shows 12>11,hence 11 and 12 will get swap.";
		cout << "\n\t12 11 13 5 7 ---> 11 12 13 5 7";
		cout << "\n\nStep 2:-\n";
		cout << "\n 1.Now compare 13 with 12.the comparision shows 12<13,Hence no change in array.";
		cout << "\n 2.compare 13 with 11,shows 11<13 hence no change in array";
		cout << "\n\t11 12 13 5 7";
		cout << "\n\nStep 3:-\n";
		cout << "\n 1.Now compare 5 with 13.the comparision shows 13>5,Hence 13 and 5 will get swap.\n\t11 12 13 5 7 ---> 11 12 5 13 7 ";
		cout << "\n 2.Now compare 5 with 12.the comparision shows 12>5,Hence 12 and 5 will get swap.\n\t11 12 5 13 7 ---> 11 5 12 13 7";
		cout << "\n 3.Now compare 5 with 11.the comparision shows 11>5,Hence 11 and 5 will get swap.\n\t11 5 12 13 7 ---> 5 11 12 13 7";
		cout << "\n\nStep 4:-\n";
		cout << "\n 1.Now compare 7 with 13.the comparision shows 13>7,Hence 13 and 7 will get swap.\n\t5 11 12 13 7 ---> 5 11 12 7 13 ";
		cout << "\n 2.Now compare 7 with 12.the comparision shows 12>7,Hence 12 and 7 will get swap.\n\t5 11 12 7 13 ---> 5 11 7 12 13";
		cout << "\n 3.Now compare 7 with 11.the comparision shows 11>7,Hence 11 and 7 will get swap.\n\t5 11 7 12 13 ---> 5 7 11 12 13";
		cout << "\n 4.compare 7 with 5,shows 5<7,hence no change in array\n\t5 7 11 12 13";
		cout << "\n\n Final Sorted Array- 5 7 11 12 13";
		cout << "--------------------------------------------------------------------------------------------";
		break;
	case 6:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "\nLet us consider a simple example to understand Bubble Sort :\n\n";
		cout << "let's consider a following sequence (5,1,4,2,8)\n\n";
		cout << "On First Pass:\n";
		cout << "( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ),	 Here, algorithm compares the first two elements, and swaps since 5 > 1.\n";
		cout << "( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), 	Swap since 5 > 4\n";
		cout << "( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), 	Swap since 5 > 2\n";
		cout << "( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), 	Now, since these elements are already in order (8 > 5), algorithm does not swap them.\n\n";

		cout << "On Second Pass:\n";
		cout << "( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )\n";
		cout << "( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ),	 Swap since 4 > 2\n";
		cout << "( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )\n";
		cout << "( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )\n\n";

		cout << "Now, the array is already sorted, but our algorithm does not know if it is completed.\n";
		cout << "The algorithm needs one whole pass without any swap to know it is sorted.\n\n";

		cout << "On Third Pass:\n";
		cout << "( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )\n";
		cout << "( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )\n";
		cout << "( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )\n";
		cout << "( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )\n";

		cout << "At complition of the third pass, we get a sorted sequence.\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	case 7:
		cout << "--------------------------------------------------------------------------------------------";
		cout << "Consider a sequence {5, 4, 8, 7, 6}.\n\n";
		cout << "Now what merge sort algorithm will do is that it will divide it into parts until single elements are left.\n\n";
		cout << "{5, 4, 8, 6, 7} --> {5, 4, 8} and {7, 6}.\n\n";
		cout << "{5, 4, 8} --> {5, 4} and 8.\n\n";
		cout << "{5, 4} --> 5 and 4\n\n";
		cout << "Now 5 and 4 are compared and merged to form a sequence {4, 5}.\n\n";
		cout << "Further elements of {4, 5} starting from 1st element are compared with 8 and are merged to form a sequence {4, 5, 8}.\n\n";
		cout << "The same happens with {7, 6} and we get {6, 7}.\n\n";
		cout << "Now two sorted sequences {4, 5, 8} and {6, 7} are compared starting from first element of each sequence.\n\n";
		cout << "After comparison and merging we get our sorted sequence {4, 5, 6, 7, 8}.\n\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		break;
	}
}

void selection_sort(vector<int> &A)
{
	int n = A.size();

	//Printing Original Sequence
	cout << "Original Sequence: ";
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
	usleep(2000000);
	//--------------------------

	//Sorting algo starts here:
	for (int i = 0; i < n - 1; ++i)
	{
		int imin = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (A[j] < A[imin])
				imin = j;
		}

		cout << "\n" << i << " <---> " << imin << "\n"; //Elements replaced

		int temp = A[i];
		A[i] = A[imin];
		A[imin] = temp;

		//Printing Updated Sequence
		cout << "Updated Sequence: ";
		for (int i = 0; i < A.size(); ++i)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		usleep(3000000);
		//----------------

	}
	//Printing Sorted Sequence
	cout << "\nSorted Sequence: ";
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
	usleep(3000000);
	//------------------------
}

void insertion_sort(vector<int> a)
{
	int i, j, temp, count = 1;

	//to display unsorted array

	cout << "\n\n\n Unsorted Array-";
	for (int i = 0; i < a.size(); i++)
		cout << " " << a[i];
	usleep(3000000);

	cout << endl;

	for (int i = 1; i < a.size(); i++)
	{
		cout << "\nstep-" << count++;
		cout << endl;
		temp = a[i];
		if (a[i - 1] <= temp)
		{	if (a[i - 1] < temp)
				cout << "\na[" << i - 1 << "]<a[" << i << "]";
			else
				cout << "\na[" << i - 1 << "]=a[" << i << "]";
			cout << "\n" << i - 1 << "<--->" << i << "   ";
			cout << "No Change";
		}
		for (j = i - 1; (j >= 0) && (temp < a[j]); j--)
		{
			a[j + 1] = a[j];
			a[j] = temp;
			cout << "\na[" << j << "]>a[" << j + 1 << "]";
			cout << "\n" << j << "<--->" << j + 1 << "   ";

			//to display original array after each instance
			cout << "\n\tSequence after itiration->";
			for (int k = 0; k < a.size(); k++)
				cout << " " << a[k];
			cout << endl;
		}

		cout << "\n\n";
	}
	//to display sorted array

	cout << "\n\n\n SORTED SEQUENCE";
	for (int i = 0; i < a.size(); i++)
		cout << " " << a[i];
}


void bubble_Sort(vector<int>sequence)
{
	// printing original sequence
	// ------------------------------------------

	cout << "Original Sequence -> ";
	for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		cout << *it << " ";
	cout << "\n\n";
	usleep(3000000);
	//-----------------------------------------
	int sequence_length = sequence.size();
	int i, j;
	bool swapped_or_not;
	for (i = 0; i < sequence_length - 1; i++)
	{
		swapped_or_not = false;

		for (j = 0; j < sequence_length - i - 1; j++)
		{
			if (sequence[j] > sequence[j + 1])
			{
				int temp = sequence[j];
				sequence[j] = sequence[j + 1];
				sequence[j + 1] = temp;
				swapped_or_not = true;


				// printing sequence
				// -----------------------------------------

				cout << "\t" << j << "<--->" << j + 1 << "\n";
				for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
					cout << *it << " ";
				cout << "\n";
				usleep(3000000);
				//-----------------------------------------
			}
		}
		if (swapped_or_not == false)
		{
			// printing final sequence
			// -----------------------------------------

			cout << "\n Sorted sequence -> ";
			for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
				cout << *it << " ";

			// -----------------------------------------
			break;
		}
		cout << "\n" << i + 1 << " iteration complete \n\n";
		usleep(1000000);
	}

}

//Two functions of Merge Sort:
void merge(vector<int> &a, int str, int end)
{
	int mid = (str + end) / 2;
	int i = str;
	int j = mid + 1;
	int k = str;
	int temp[100];
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (int i = str; i <= end; ++i)
	{
		a[i] = temp[i];
	}

	//Printing Merged Sequence
	cout << "Merged Sequence: ";
	for (int i = str; i <= end; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n";
	usleep(3000000);
	//-----------------------

	//Printing final Sorted Sequence:
	if (str == 0 && end == a.size() - 1)
	{
		cout << "Sorted Sequence: ";
		for (int i = 0; i < a.size(); ++i)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
		usleep(3000000);
	}
	//----------------------
}

void merge_sort(vector<int> &a, int str, int end)
{
	if (str >= end)
	{
		return;
	}
	int mid = (str + end) / 2;

	//Printing of two broken sequences
	cout << "Sequence Is broken down into parts:\n";
	for (int i = str; i <= mid; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "and ";
	for (int i = mid + 1; i <= end; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n";
	usleep(3000000);
	//-------------------------------

	merge_sort(a, str, mid);
	merge_sort(a, mid + 1, end);
	cout << "Merge function is called\n";
	merge(a, str, end);
}


void linear_search(vector<int> sequence , int required_number)
{
	int index;
	bool check = false;
	for (int i = 0; i < sequence.size(); i++)
	{
		// checking number in the sequence
		//-----------------------------------------
		int count = 0;
		cout << "\tIs " << required_number << " == " << sequence[i] << "\n";
		for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			if (count == i )
				cout << "|_| ";
			else
				cout << *it << " ";
			count++;
		}
		cout << "\n\n";

		usleep(3000000);

		//-----------------------------------------

		if (sequence[i] == required_number)
		{
			index = i;
			check = true;
			break;
		}
	}
	if (check)
		cout << "\nThe number " << required_number << " is at position " << ++index;
	else
		cout << "\nThe number " << required_number << " is not present in the sequence";

}


void jump_search(vector <int> sequence, int requied_number)
{
	cout << "original sequence -> ";
	for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		cout << *it << " ";
	cout << "\n";

	sort(sequence.begin(), sequence.end());
	// printing original sequence
	// ------------------------------------------

	cout << "sorted Sequence   -> ";
	for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		cout << *it << " ";
	cout << "\n\n";
	usleep(2000000);
	//-----------------------------------------

	int previous = 0;
	int sequence_length = sequence.size();
	int step = sqrt(sequence_length);
	int count = 1;
	while (sequence[min(step, sequence_length) - 1] < requied_number)
	{
		//-----------------------------------------

		cout << "\t" << requied_number << " > " << sequence[min(step, sequence_length) - 1] << "\n";
		for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			if (count == step)
			{
				cout << "|_| ";
				count++;
			}
			else
			{
				cout << *it << " ";
				count++;
			}

		}
		cout << "\n";
		usleep(3000000);
		//-----------------------------------------

		previous = step;
		step += sqrt(sequence_length);
		count = 1;
		if (previous >= sequence_length)
		{
			cout << "\n" << requied_number << " is not present in the sequence";
			return;
		}
	}
	cout << "\n\n";
	count = 0;
	cout << "from now linear search will start :- \n\n";

	while (sequence[previous] < requied_number)
	{
		//-----------------------------------------

		cout << "\t" << requied_number << " > " << sequence[previous] << "\n";
		for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			if (count == previous)
			{
				cout << "|_| ";
				count++;
			}
			else
			{
				cout << *it << " ";
				count++;
			}
		}
		cout << "\n";
		usleep(3000000);
		//-----------------------------------------
		previous++;
		count = 0;
		if (previous > min(step, sequence_length) - 1)
		{
			cout << "\n" << requied_number << " is not present in the sequence";
			return;
		}
	}
	if (sequence[previous] == requied_number)
		cout << "\n" << requied_number << " is present at " << ++previous << " position";


}

void bsearch(vector <int> ar, int item)
{	int t = ar.size();
	int beg = 0, last = t - 1, mid, j = 1;
	cout << "\n\n" << setw(65) << "->HAVE A LOOK ON PROCEDURE<-";
	cout << "\n\n valuse of array element entered by you:-";
	cout << "\n\n  ARRAY(index)-";

	//to diplay original array

	for (int i = 0; i < t; i++)
		cout << "    " << ar[i] << "(" << i << ")";
	usleep(3000000);

	while (beg <= last)
	{	cout << "\n\n\n step- " << j << " ARRAY- ";

		//to display array after each loop
		for (int i = beg; i <= last; i++)
			cout << " " << ar[i];
		usleep(3000000);

		cout << "\n\n \t here beg=>" << beg << "  last=>" << last << "\t mid=(beg+last)/2->  mid=" << (beg + last) / 2;
		mid = (beg + last) / 2;

		if (item == ar[mid])
		{
			cout << "\n\n\n step- " << j + 1 << " ARRAY- " << ar[mid];
			cout << "\n\t since {item = array[" << mid << "]}";
			cout << "\n\n position of element " << item << " is " << mid << "(index)+1=" << mid + 1;
			usleep(3000000);
			return;
		}
		else if (item > ar[mid])
		{	beg = mid + 1;
			cout << "\n\t since {item > array[" << mid << "]} --> " << item << " > " << ar[mid];
			cout << endl;
			cout << "\n\t therefore beg=mid+1 --> beg= " << mid << " +1 = " << beg;
		}
		else
		{	last = mid - 1;
			cout << "\n\t since \t{item < array[" << mid << "]} --> " << item << " < " << ar[mid];
			cout << "\n\t therefore \tlast=mid-1 --> last= " << mid << " -1 = " << last;
		}
		j++;
	}
	cout << "\n item is not found";
	usleep(3000000);
}

void interpolation_search(vector<int> A, int num)
{
	sort(A.begin(), A.end());
	int n = A.size();
	cout << "Sequence: ";
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << "\nNumber to be searched: " << num << "\n\n";
	usleep(3000000);
	int start, end;
	int pos = -1;
	start = 0;
	end = n - 1;
	int flag = 0;
	while (start <= end && num >= A[start] && num <= A[end])
	{
		pos = start + (((double)(end - start) / (A[end] - A[start])) * (num - A[start]));
		//Printing start, end and pos
		cout << "start = " << start << " end = " << end << " pos = " << pos << "\n\n";
		if (A[pos] == num)
		{
			cout << "Number found at pos.\n\n";
			flag = 1;
			usleep(3000000);
			break;
		}
		if (num > A[pos])
		{
			cout << "Number > Element at index pos.\n\nstart = pos + 1\n\n";
			usleep(3000000);
			start = pos + 1;
		}
		else
		{
			cout << "Number < Element at index pos.\n\nend = pos - 1\n\n";
			usleep(3000000);
			end = pos - 1;
		}
	}
	if (flag == 0)
		cout << "NUmber is not present in the sequence.\n\n" << endl;
	else
		cout << "Number is present in the sequence.\n\n" << endl;
}