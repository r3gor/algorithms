#include <bits\stdc++.h>

#define t size_t

inline const void print(const std::vector<int> v){ 
    for (t i=0; i<v.size(); i++) printf("%d ", v[i]);
    printf("\n");
}

int partition(std::vector<int> &v, int low, int high) {
    int i = low - 1;
    int pivot = v[high-1];
    for (t j=low; j<high; j++) {
        if (v[j] < pivot) 
            std::swap(v[++i], v[j]);
    }
    std::swap(v[++i], v[high-1]);
    return i;
}

void quicksort(std::vector<int> &v, int low, int high) {
    if (low >= high) return;
    int i = partition(v, low, high);
    quicksort(v, low, i-1);
    quicksort(v, i+1, high);
}



int main()  
{  
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};  
    quicksort(arr, 0, arr.size());  
    std::cout << "Sorted array: \n";  
    print(arr);  
    return 0;
} 