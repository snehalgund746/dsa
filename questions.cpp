 1)STACK :-
#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;
void push(int val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stack[top] = val;
    }
}
void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}
void display() {
    if (top >= 0) {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    } else
        cout << "Stack is empty" << endl;
}
int main() {
    int ch, val;

    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    cout<<"Enter choice:"<<endl;
    cin>>ch;
        switch (ch) {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }
    }


2)HEAPIFY
  def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    # If root is not largest, swap with largest and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heapSort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap
        heapify(arr, i, 0)  # Heapify root element


# Main program
arr = [1, 12, 9, 5, 6, 10]
heapSort(arr)
print("Sorted array is:")
for i in arr:
    print(i, end=' ')


3)FRACTIONAL KNAPSACK
class Item:
    def __init__(self, weight, value):  # Correct constructor
        self.weight = weight
        self.value = value
        self.ratio = value / weight  # value-to-weight ratio


def fractional_knapsack(items, capacity):
    # Sort items by ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0
    for i in items:
        if capacity >= i.weight:
            capacity -= i.weight
            total_value += i.value
        else:
            fraction = capacity / i.weight
            total_value += i.value * fraction
            break
    return total_value


# Test the function
items = [Item(20, 100), Item(30, 120), Item(10, 60)]
capacity = 50

print(fractional_knapsack(items, capacity))


4)BINARY SEARCH 

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {	
    int low = 0;     
    int high = size - 1;    

    while (low <= high) {        
        int mid = low + (high - low) / 2; // Correct midpoint calculation

        if (arr[mid] == target) {
            return mid; // Return the index
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1; // Target not found 
}


5)MERGE SORT

def mergeSort(arr):
    if len(arr) > 1:

        # Find the middle point and divide the array
        mid = len(arr) // 2
        start = arr[:mid]
        end = arr[mid:]

        # Sort the two halves
        mergeSort(start)
        mergeSort(end)

        i = j = k = 0

        # Merge the sorted halves
        while i < len(start) and j < len(end):
            if start[i] < end[j]:
                arr[k] = start[i]
                i += 1
            else:
                arr[k] = end[j]
                j += 1
            k += 1

        # Copy any remaining elements
        while i < len(start):
            arr[k] = start[i]
            i += 1
            k += 1

        while j < len(end):
            arr[k] = end[j]
            j += 1
            k += 1

# Driver code
if __name__ == '__main__':
    arr = [6, 5, 4, 8, 1, 9]
    print("Original Delivery Times:", arr)
    mergeSort(arr)
    print("Sorted by Delivery Time (Ascending):", arr)



int main() {
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};    
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);	      
    int targetElement = 23;    

    int result = binarySearch(sortedArray, size, targetElement);

    if (result != -1) {
        cout << "Element " << targetElement << " found at index: " << result << endl;
    } 
    else {
        cout << "Element " << targetElement << " not found in the array." << endl;
    }

    return 0;
}
