  #include <iostream>
  using namespace std;
  
  bool isGreater(int arr[], int j, int i) {
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
  }
  
  void swap(int arr[], int j, int i) {
    cout << "Swapping " << arr[j] << " and " << arr[i] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  
  void insertionSort(int arr[], int n) {
    //write your code here
    for (int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(isGreater(arr, j, j+1))
            {
                swap(arr, j, j+1);
            }
            else{
                break;
            }
        }
        
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
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}