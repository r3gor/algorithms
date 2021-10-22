/* quick sort */

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)  
{  
    size = 6;
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
int pivotsort(int arr[], int low, int high, int pivot) {
    /* agrupa menores de pivot a izq. y mayores a der. 
     * y retorna el indice del pivot 
     * */
    int may_pos = low;

    for (int j=low; j<=high-1; j++){
        if (arr[j]<arr[pivot]) {
            swap(arr[may_pos], arr[j]);
            may_pos++;
        }
    }
    swap(arr[may_pos], arr[pivot]);
    return may_pos;
}
void qsort(int arr[], int low, int high) {
    if (high>low){
        int pivot = high;
        int idx_pivot = pivotsort(arr, low, high, pivot);
        qsort(arr, low, idx_pivot-1);
        qsort(arr, idx_pivot+1, high);
    }
}

  
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    qsort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;
}