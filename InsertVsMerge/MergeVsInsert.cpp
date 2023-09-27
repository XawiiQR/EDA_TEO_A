#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        
        merge(arr, left, middle, right);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Run_Python(){
    int result = std::system("python3 MergeVsInsert.py"); 
    if (result == 0) {
        std::cout << "El script de Python se ejecutó exitosamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar el script de Python." << std::endl;
    }
}
int main() {
    ofstream ArchivoMerge;
    ArchivoMerge.open("Merge.txt");
    ofstream ArchivoInsert;
    ArchivoInsert.open("Insert.txt");
    ofstream Sizes("Sizes.txt");
    for(int i=10; i<100;i+=10){
        int num;
        Sizes<<i<<endl;
        vector<int>Numeros;
        srand(time(NULL));
        for(int j = 1; j <i ; j++)
            {
                num = rand() % 10001;
                Numeros.push_back(num);
            }
        vector<int>Merge=Numeros;
        vector<int>Insert=Numeros;
        clock_t start = clock();
        mergeSort(Merge, 0, Merge.size() - 1);
        clock_t end = clock();
        double duration = static_cast<double>(end - start) /CLOCKS_PER_SEC;
        clock_t inicio = clock();
        insertionSort(Insert);
        clock_t fin = clock();
        double time = static_cast<double>(fin - inicio) / CLOCKS_PER_SEC;
        ArchivoMerge<<duration<<endl;
        ArchivoInsert<<time<<endl;
    }

    ArchivoInsert.close();
    ArchivoMerge.close();
    
    Run_Python();
    return 0;
}
