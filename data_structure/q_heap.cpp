#include <iostream> 
  
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
int main() 
{ 
    int num;
    while(cin >> num) {
        int arr[num];
        for(int i = 0; i < num; i++) {
            cin >> arr[i];
        }

        int sum = 0;
        for(int i = 1; i < num; i++) {
            heapSort(arr, num);
            sum += arr[i] + arr[i-1];
            arr[i] = arr[i] + arr[i-1];   
        }
        cout << sum << endl;
    }

    return 0;
} 