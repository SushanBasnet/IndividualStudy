//
//  main.cpp
//  IndividualStudy
//
//  Created by Sushan Basnet on 1/11/20.
//  Copyright © 2020 Sushan Basnet. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <thread>

using namespace std;
const char *path="/Users/sbasnet/nums.txt";






void swap(int* a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* use last element as pivot
 find its position in array
 move smaller elements left to the pivot
 move bigger elements right to the pivot*/
int partition(vector<int>& arr, int i, int k) {
    int pivot = arr[k];
    int pindex = i;
    for(int j=i; j < k; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[pindex], &arr[j]);
            pindex++;
        }
    }
    swap(&arr[pindex], &arr[k]);
    return pindex;
}

void quicksort(vector<int>& arr, int i, int k) {
    if(k <= i) return;
    int pivot = partition(arr, i, k);
    quicksort(arr, i, pivot-1);
    quicksort(arr, pivot+1, k);
}

// merges two arrays that are sorted in O(n) time
// input array, start, middle, end
void merge(vector<int>& arr, int i, int j, int k) {
    int leftpos = i;
    int rightpos = j+1;
    vector<int> tmp;
    
    while(leftpos <= j && rightpos <=k) {
        if (arr[leftpos] < arr[rightpos]) tmp.push_back(arr[leftpos++]);
        else tmp.push_back(arr[rightpos++]);
        comparisions++;
    }
    
    while(leftpos <= j) {
        tmp.push_back(arr[leftpos++]);
    }
    while(rightpos <= k) {
        tmp.push_back(arr[rightpos++]);
    }
    
    //now transfer to the initial array O(n)
    for(int k=0; k<tmp.size(); k++) {
        arr[i+k] = tmp[k];
    }
}

//Recursively divides the array into two parts and calls merge
// Input: array of nums, starting index, end index
void mergesort(vector<int>& arr, int i, int k) {
    if (k <= i) return;
    int j = (i+k)/2;
    mergesort(arr, i, j);
    mergesort(arr, j+1, k);
    merge(arr, i, j, k);
}

void generateTextFile(int len) {
    ofstream out(path);
    for(int i=0; i<len; i++) {
        out << rand() % len << " ";
    }
}

void readFromFile(vector<int>& nums) {
    ifstream in(path);
    string inputStr;
    if(in.is_open())
    {
        while(in >> inputStr) {
            nums.push_back(stoi(inputStr));
        }
    }
}


int main(int argc, const char * argv[]) {
    generateTextFile(1000000);
    vector<int> nums;
    readFromFile(nums);
    double duration;
    
    vector<int> nums2 = nums;
    clock_t start = clock();
    mergesort(nums, 0, nums.size()-1);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "MergeSort Duration: " << duration << endl;
    

    start = clock();
    quicksort(nums2, 0, nums.size()-1);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "QuickSort Duration: " << duration << endl;

    //for(int i: nums) cout << i << endl;
    
}
