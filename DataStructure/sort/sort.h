#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>
#include <cstdlib>

#define CUTOFF 3

/*swap function*/
inline void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/*print*/
void print(std::vector<int> vec)
{
    for(auto i : vec)
	std::cout << i << " ";
    std::cout << std::endl;
}

/*bubble sort*/
void bubbleSort(std::vector<int> vec, int size)
{
    if(size == 0)
	return ;
    for(int i = 0; i < size; i++)
    {
	for(int j = 1; j < size-i; j++)
	{
	    if(vec[j - 1] > vec[j])
		swap(vec[j - 1], vec[j]);
	}
    }
    print(vec);
}

/*Insertion Sort: this function is called Qsort*/
void InsertionSort(std::vector<int> &vec, int start, int size)
{
    int tmp;
    int i, p;
    for(p = 1; p < size; p++)
    {
	tmp = vec[start + p];
	for(i = p + start; i > start && vec[i - 1] > tmp; i--)
	    vec[i] = vec[i - 1];
	vec[i] = tmp;
    }
    /*std::cout << "after insertion sort:";
    print(vec);*/
}

/*quick sort with Median-of-Three Partitioning*/
int median3(std::vector<int> &vec, int left, int right)
{
    int middle = (left + right) / 2;

    if(vec[left] > vec[middle])
	swap(vec[left], vec[middle]);
    if(vec[left] > vec[right])
	swap(vec[left], vec[right]);
    if(vec[middle] > vec[right])
	swap(vec[middle], vec[right]);

    /*hide key*/
    swap(vec[middle], vec[right - 1]);
    return vec[right - 1];
}

void Qsort(std::vector<int> &vec, int left, int right)
{
    int key;
    int i, j;
    //print(vec);
    if(left + CUTOFF <= right)
    {
	key = median3(vec, left, right);
	/*std::cout << "key:"   << key   << " "
		  << "left:"  << left  << " "
		  << "right:" << right << std::endl;
	*/
	i = left;
	j = right - 1;
	for( ; ; )
	{
	    while(vec[++i] < key) {}
	    while(vec[--j] > key) {}

	    if(i < j)
		swap(vec[i], vec[j]);
	    else
		break;
	}
	swap(vec[i], vec[right - 1]);
/*	std::cout << "after quick sort:";
	print(vec);
*/
	Qsort(vec, left, i - 1);
	Qsort(vec, i + 1, right);
    }
    /*if less than CUTOFF, use insertion sort*/
    else
    {
	/*std::cout << "left:" << left  << " "
		  << "right:"<< right << std::endl;
	*/
	InsertionSort(vec, left, right - left + 1);
    }
}

void quickSort(std::vector<int> vec, int size)
{
    Qsort(vec, 0, size-1);
    print(vec);
}
#endif
