// Sorting algorithms 

#include<iostream> 
#include<bits/stdc++.h>
#include <vector> 
using namespace std; 

// Merge sort
void merge(vector<int> &A, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    
    int L[n1], R[n2];
    for(int i = 0; i<n1;i++){
        L[i] = A[l+i];
    }
    
    for(int i = 0; i<n2;i++){
        R[i] = A[m+1+i];
    }
    
    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            A[k] = L[i++];
        }else A[k] = R[j++];
        k++;
    }
    
    while(i<n1){
         A[k] = L[i++];
         k++;
    }
    
    while(j<n2){
         A[k] = R[j++];
         k++;
    }
}

void mergesort(vector<int> &A, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A, l,m,r);
    }
}

// Bubble sort
void bubblesort(vector<int> &a){
    bool swapped;
    int n = a.size();

    for(int i = 0; i<n-1;i++){
        swapped = false;
        for(int j =0; j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swapped= true;
                swap(a[j],a[j+1]);
            }
        }
        if(!swapped) break;
    }
}


// Insertion sort
void insertionsort(vector<int> &A){
    int n = A.size();
    int i, j , key;
    
    for(int i = 1; i<n;i++){
        key = A[i];
        j = i-1;
        
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}


// Selection sort
void selectionsort(vector<int> &A){
    int n = A.size();
    int i, j , min_i;
    
    for(int i = 0; i<n-1;i++){
        min_i = i;
        
        for(int j = i+1;j<n;j++){
            if(A[j]<A[min_i]) min_i = j;
        }
        
        swap(A[i],A[min_i]);
    }
}

// Quick sort
int pivot(vector<int> &A, int l, int r){
    int p = A[r];
    int i = l-1;
    
    for(int j = l; j<r;j++){
        if(A[j]<p){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}


void quicksort(vector<int> &A, int l, int r){
    if(l<r){
        int p = pivot(A,l,r);
        quicksort(A,l,p-1);
        quicksort(A,p+1,r);
    }
}


// Heap sort
void heapify(vector<int> &A, int n, int i){
    int largest = i;
    int l = 2*i + 1, r = l+1;
    
    if(l<n && A[l]>A[largest]) largest = l;
    if(r<n && A[r]>A[largest]) largest = r;
    
    if(largest!=i){
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}

void heapsort(vector<int> &A){
    int n = A.size();
    for(int i = n/2-1;i>=0;i--) heapify(A,n,i);
    
    for(int i = n-1;i>=0;i--){
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}


int main(){
    int n = 10;
    // cin >> n;
    vector<int> A(n);
    for(int i = 0; i<n; i++) A[i] = n-i-1;
    
    // mergesort(A,0,n-1);
    // bubblesort(A);
    // insertionsort(A);
    // selectionsort(A);
    // quicksort(A,0,n-1);
    heapsort(A);
    
    for(auto x:A) cout << x << " ";
}