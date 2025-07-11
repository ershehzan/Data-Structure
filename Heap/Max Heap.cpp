#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;       // total number of elements in the heap
    int total_size; // total size of the heap (capacity)

    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val)
    {
        if (size == total_size)
        {
            cout << "Heap is full" << endl;
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << "Inserted " << val << " into the heap." << endl;
    }
    void print()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        // Largest is the current index

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
        else
        {
            cout << "Heapify complete for index " << index << endl;
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty, cannot delete" << endl;
            return;
        }
        cout << "Deleted " << arr[0] << " from the heap." << endl;
        swap(arr[0], arr[size - 1]);
        size--;

        if (size == 0)
        {
            cout << "Heap is now empty after deletion." << endl;
            return;
        }
        Heapify(0);
    }
    int getMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1; // or throw exception
        }
        return arr[0];
    }
};

int main()
{
    int n;
    cout << "Enter the size of the heap: ";
    cin >> n;
    MaxHeap h(n);
    cout << "Enter " << n << " elements to insert into the heap: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        h.insert(val);
    }
    h.Delete();

    h.print();

    return 0;
}