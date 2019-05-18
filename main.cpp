#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
//using namepsace hw6;

// function prototypes
void printArray(double *arr, int size);
void copyArray(double *old, double *newA, int size);
void swap(double *x,double *y);
int partition (double *arr, int low, int high);
void BubbleSort(double *arr, int size);
void InsertionSort(double *arr, int n);
void QuickSort(double *arr, int low, int high);
void MergeSort(double *arr, int low, int high);
void Merge(double *a, int low, int middle, int high);


int main(int argc, char *argv[]){

  // variables for command line args and file io
  string filename;
  ifstream FileStream;
  string line; int n = 0;

  // ensuring valid file and command line args
  if (argc>1){
    filename = argv[1];
    FileStream = ifstream(filename);
  }

  else{cout << "No arguments entered...." << endl;exit(0);}

  // processing text file
  // getting number of lines to read
  getline(FileStream,line);
  n = stoi(line);

  double toSort[n]; // array to eventually sort
  double val; // value to add to array

  for (int x=0;x<n;x++){ // populating array
    getline(FileStream,line);
    toSort[x] = stod(line);
  }

  double toSort1[n]; copyArray(toSort,toSort1,n);
  double toSort2[n]; copyArray(toSort,toSort2,n);
  double toSort3[n]; copyArray(toSort,toSort3,n);
  double toSort4[n]; copyArray(toSort,toSort4,n);


  clock_t start_time; clock_t end_time;

  cout << endl;
  start_time = clock();
  cout << "Bubble Sort" << endl;
  BubbleSort(toSort1, n);
  end_time = clock();
  cout << "Start : " << start_time << endl;
  cout << "End : " << end_time << endl;
  cout << "Total time : " << end_time - start_time << endl;
  cout << endl;

  start_time = clock();
  cout << "Merge Sort" << endl;
  MergeSort(toSort2, 0, n-1);
  end_time = clock();
  cout << "Start : " << start_time << endl;
  cout << "End : " << end_time << endl;
  cout << "Total time : " << end_time - start_time << endl;
  cout << endl;

  start_time = clock();
  cout << "Insertion Sort" << endl;
  InsertionSort(toSort3, n);
  end_time = clock();
  cout << "Start : " << start_time << endl;
  cout << "End : " << end_time << endl;
  cout << "Total time : " << end_time - start_time << endl;
  cout << endl;

  start_time = clock();
  cout << "Quick Sort" << endl;
  QuickSort(toSort4, 0, n-1);
  end_time = clock();
  cout << "Start : " << start_time << endl;
  cout << "End : " << end_time << endl;
  cout << "Total time : " << end_time - start_time << endl;
}


// SORTING FUNCTIONS //

void printArray(double *arr, int size){
  for (int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void copyArray(double *old, double *newA, int size){
  for (int i = 0; i < size; i++){
    newA[i] = old[i];
  }
}

void swap(double *x,double *y){
  double temp = *x;
  *x = *y;
  *y = temp;
}


void BubbleSort(double *arr, int n)
{
  int i, j;
  for (i = 0; i < n-1; i++){
    for (j = 0; j < n-i-1; j++){
      if (arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void InsertionSort(double *arr, int n){
  double key; int j;
  for (int i = 1; i < n; i++){
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
    }
  arr[j + 1] = key;
  }
}

int partition (double *arr, int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++){
    if (arr[j] <= pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void QuickSort(double *arr, int low, int high) {
  if (low < high){
        int piv = partition(arr, low, high);
        QuickSort(arr, low, piv - 1);
        QuickSort(arr, piv + 1, high);
    }
}

void MergeSort(double *arr, int low, int high){
  if(low < high){
    int middle = (low+high)/2;
    MergeSort(arr, low, middle);
    MergeSort(arr, middle+1, high);
    Merge(arr, low, middle, high);
  }
}

void Merge(double *a, int low, int middle, int high){
  int *temp = new int[high-low+1];
  int left = low;
  int right = middle + 1;
  int index = 0;

  while(left <= middle && right <= high){
      if(a[left] <= a[right])
        temp[index++] = a[left++];

      else
        temp[index++] = a[right++];
  }

  while(left <= middle){temp[index++] = a[left++];}

  while(right <= high){temp[index++] = a[right++];}

  for(index = 0, left = low; left <= high; ++left, ++index){
      a[left] = temp[index];
  }

  delete []temp;
}
