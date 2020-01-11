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
#define DELAY_NS 0
using namespace std;

const char *path="/Users/sbasnet/nums.txt";

//stimulate access latency for array (can be done with inheritance also)
int get(vector<int>& array, int index){
    this_thread::sleep_for(chrono::nanoseconds(DELAY_NS));
    return array[index];
}

void set(vector<int>& array, int index, int value) {
    this_thread::sleep_for(chrono::nanoseconds(DELAY_NS));
    array[index] = value;
}



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
    int pivot = get(arr, k);
    int pindex = i;
    for(int j=i; j < k; j++) {
        if (get(arr,j) <= pivot) {
            this_thread::sleep_for(chrono::nanoseconds(2* DELAY_NS)); // access during swap
            swap(&arr[pindex], &arr[j]);
            pindex++;
        }
    }
    this_thread::sleep_for(chrono::nanoseconds(2* DELAY_NS)); // access during swap
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
        if (get(arr, leftpos) < get(arr,rightpos)) tmp.push_back(get(arr,leftpos++));
        else tmp.push_back(get(arr,rightpos++));
    }
    
    while(leftpos <= j) {
        tmp.push_back(get(arr,leftpos++));
    }
    while(rightpos <= k) {
        tmp.push_back(get(arr,rightpos++));
    }
    
    //now transfer to the initial array O(n)
    for(int k=0; k<tmp.size(); k++) {
        set(arr,i+k,get(tmp,k));
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
    generateTextFile(10000000);
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
