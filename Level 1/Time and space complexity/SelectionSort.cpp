  #include <iostream>
  using namespace std;
  
  bool isSmaller(int arr[], int i, int j) {
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
  }
  
  void swap(int arr[], int i, int j) {
    cout << "Swapping " << arr[j] << " and " << arr[i] << endl;
  }
  
  void selectionSort(int arr[], int n) {
    //write your code here
    for (int i = 0; i < n - 1; i++)
    {
        int mindex = i;
        for (int j = i+1; j < n; j++)
        {
            if(isSmaller(arr, j, mindex))
            {
                mindex = j;
            }
        }
        swap(arr, mindex, i);
    }
  }


    void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << endl;
    }
  }

    int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    selectionSort(arr, n);
    print(arr, n);
    return 0;
}