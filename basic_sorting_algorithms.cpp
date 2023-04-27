#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void show_array(int array[], int n){
    for(int i=0; i<n; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int array[], int n){
    for(int i=0; i<(n-1); ++i){
        cout << "Pass " << i+1 << ": " << endl;
        for(int j=0; j<(n-1); ++j){
            if (array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
            show_array(array, n);
        }
        cout << endl;
    }
    cout << "Sorted numbers: " << endl;
    show_array(array, n);
}

void selection_sort(int array[], int n){
    for(int i=0; i<(n-1); ++i){
        cout << "Pass " << i+1 << ": " << endl;
        for(int j=i+1; j<n; ++j){
            if(array[i] > array[j]){
                swap(array[i], array[j]);
            }
            show_array(array, n);
        }
        cout << endl;
    }
    cout << "Sorted numbers: " << endl;
    show_array(array, n);
}

void insertion_sort(int array[], int n){
    for(int i=1; i<n; ++i){
        cout << "Pass " << i << ": " << endl;
        for(int j=0; j<i; ++j){
            if(array[j] > array[i]){
                swap(array[j], array[i]);
            }
            show_array(array, n);
        }
        cout << endl;
    }
    cout << "Sorted numbers: " << endl;
    show_array(array, n);
}

int give_random_number(int range, int lowest_limit){
    return rand() % range + lowest_limit;
}

void generate_numbers(int array[], int range, int lowest_limit, int n){
    for(int i=0; i<n; ++i){
        array[i] = give_random_number(range, lowest_limit);
    }
}

int main(){
    srand(time(NULL));
    bool access = true;
    while (access == true){
        // change the array size to what you wish below
        int myArray[5] = {};
        int n = sizeof(myArray) / sizeof(int);
        int x;
        // change the rng's range and lowest limit to what you wish below
        int range = 20, lowest_limit = 1;
        generate_numbers(myArray, range, lowest_limit, n);
        cout << "\n------------------------------------------\n";
        cout << "\nThe random numbers are: " << endl;
        show_array(myArray, n);
        cout << endl;
        cout << "1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Exit\nChoice: "; cin >> x; 
        cout << endl;
        if(x == 1){
            bubble_sort(myArray, n);
        } else if (x == 2){
            selection_sort(myArray, n);
        } else if (x == 3){
            insertion_sort(myArray, n);
        } else {
            access = false;
            cout << "Sorting algorithms coded by Vonn Mamaril. Thank you for using this code!" << endl;
        }
    }
}