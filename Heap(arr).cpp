#include <bits/stdc++.h>
using namespace std;

struct heap
{
    int capacity;
    int heap_size;
    int *heap_arr;

    void Heap(int cap)
    {
        capacity = cap;
        heap_size = 0;
        heap_arr = (int *)malloc(cap * sizeof(int));
        ;
    }

    int parent_ind(int ind)
    {
        return (ind - 1) / 2;
    }

    int left_child_ind(int ind)
    {
        return 2 * ind + 1;
    }

    int right_child_ind(int ind)
    {
        return 2 * ind + 2;
    }

    int get_parent(int ind)
    {
        return heap_arr[parent_ind(ind)];
    }

    int get_left_child(int ind)
    {
        return heap_arr[left_child_ind(ind)];
    }

    int get_right_child(int ind)
    {
        return heap_arr[right_child_ind(ind)];
    }

    void min_heapify(int size, int i)
    {
        int left = left_child_ind(i);
        int right = right_child_ind(i);
        int smallest = i;
        if (left < size && heap_arr[left] < heap_arr[smallest])
        {
            smallest = left;
        }
        if (right < size && heap_arr[right] < heap_arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(heap_arr[smallest], heap_arr[i]);
            min_heapify(size, smallest);
        }
    }

    void max_heapify(int size, int i)
    {
        int left = left_child_ind(i);
        int right = right_child_ind(i);
        int largest = i;
        if (left < size && heap_arr[left] > heap_arr[largest])
        {
            largest = left;
        }
        if (right < size && heap_arr[right] > heap_arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(heap_arr[largest], heap_arr[i]);
            max_heapify(size, largest);
        }
    }

    void insert(int x, bool min) // inserts in min or max heap
    {
        if (heap_size == capacity)
        {
            capacity++;
            heap_arr = (int *)realloc(heap_arr, (heap_size + 1) * sizeof(int));
        }
        heap_size++;
        int i = heap_size - 1;
        heap_arr[i] = x;
        if (min)
        {
            maintain_MinHeap_for_insertion(i);
        }
        else
        {
            maintain_MaxHeap_for_insertion(i);
        }
    }

    void heapsort(bool min)
    {
        if (min)
        {
            for (int i = heap_size / 2 - 1; i >= 0; i--)
            {
                min_heapify(heap_size, i);
            }
            for (int i = heap_size - 1; i > 0; i--)
            {
                swap(heap_arr[0], heap_arr[i]);
                min_heapify(i, 0);
            }
        }
        else
        {
            for (int i = heap_size / 2 - 1; i >= 0; i--)
            {
                max_heapify(heap_size, i);
            }
            for (int i = heap_size - 1; i > 0; i--)
            {
                swap(heap_arr[0], heap_arr[i]);
                max_heapify(i, 0);
            }
        }
    }

    void maintain_MinHeap_for_insertion(int i)
    {
        while (i != 0 && get_parent(i) > heap_arr[i])
        {
            swap(heap_arr[i], heap_arr[(i - 1) / 2]);
            i = parent_ind(i);
        }
    }

    void maintain_MaxHeap_for_insertion(int i)
    {
        while (i != 0 && get_parent(i) < heap_arr[i])
        {
            swap(heap_arr[i], heap_arr[parent_ind(i)]);
            i = parent_ind(i);
        }
    }

    void maintain_MinHeap_for_deletion(int i)
    {
        while (i < heap_size)
        {
            if (left_child_ind(i) < heap_size && get_left_child(i) <= get_right_child(i) && get_left_child(i) < heap_arr[i])
            {
                swap(heap_arr[i], heap_arr[left_child_ind(i)]);
                i = left_child_ind(i);
                continue;
            }
            if (right_child_ind(i) < heap_size && get_right_child(i) <= get_left_child(i) && get_right_child(i) < heap_arr[i])
            {
                swap(heap_arr[i], heap_arr[right_child_ind(i)]);
                i = right_child_ind(i);
                continue;
            }
            break;
        }
    }

    void maintain_MaxHeap_for_deletion(int i)
    {
        while (i < heap_size)
        {
            if (left_child_ind(i) < heap_size && get_left_child(i) >= get_right_child(i) && get_left_child(i) > heap_arr[i])
            {
                swap(heap_arr[i], heap_arr[left_child_ind(i)]);
                i = left_child_ind(i);
                continue;
            }
            if (right_child_ind(i) < heap_size && get_right_child(i) >= get_left_child(i) && get_right_child(i) > heap_arr[i])
            {
                swap(heap_arr[i], heap_arr[right_child_ind(i)]);
                i = right_child_ind(i);
                continue;
            }
            break;
        }
    }

    int get_Min_or_Max()
    {
        return heap_arr[0];
    }

    void Print()
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (i == heap_size - 1)
            {
                cout << heap_arr[i];
            }
            else
            {
                cout << heap_arr[i] << " ";
            }
        }
        cout << "\n";
    }

    void deletes_root(bool min)
    {
        swap(heap_arr[0], heap_arr[heap_size - 1]);
        heap_size--;
        if (min)
        {
            maintain_MinHeap_for_deletion(0);
        }
        else
        {
            maintain_MaxHeap_for_deletion(0);
        }
    }

    int extract_Min_or_Max(bool min)
    {
        if (heap_size <= 0)
            return INT_MAX;

        int root = get_Min_or_Max();
        deletes_root(min);
        return root;
    }

    // int find_and_get_index(int x, bool min, int i)
    // {
    //     if (left_child_ind(i) >= heap_size && right_child_ind(i) >= heap_size)
    //     {
    //         return -2;
    //     }

    //     if (i == heap_size - 1 && heap_arr[i] != x)
    //     {
    //         cout << i << endl;
    //         return -2;
    //     }
    //     int ind = -2;
    //     if (min)
    //     {
    //         if (i < heap_size && heap_arr[i] > x)
    //         {
    //             if (get_parent(i) == x)
    //             {
    //                 cout << parent_ind(i) << endl;
    //                 return parent_ind(i);
    //             }
    //             ind = find_and_get_index(x, min, parent_ind(i));
    //             cout << ind << endl;
    //         }
    //         if (i < heap_size && heap_arr[i] < x)
    //         {
    //             if (left_child_ind(i) < heap_size)
    //             {
    //                 if (get_left_child(i) == x)
    //                 {
    //                     cout << left_child_ind(i) << endl;
    //                     return left_child_ind(i);
    //                 }
    //             }

    //             if (right_child_ind(i) < heap_size)
    //             {
    //                 if (get_right_child(i) == x)
    //                 {
    //                     cout << right_child_ind(i) << endl;
    //                     return right_child_ind(i);
    //                 }
    //             }
    //             if (left_child_ind(i) < heap_size)
    //             {
    //                 if (i < heap_size && get_left_child(i) < x)
    //                 {
    //                     ind = find_and_get_index(x, min, left_child_ind(i));
    //                     // cout << ind << endl;
    //                     if (ind != -2)
    //                     {
    //                         return ind;
    //                     }
    //                 }
    //             }

    //             if (right_child_ind(i) < heap_size)
    //             {
    //                 if (i < heap_size && get_right_child(i) < x)
    //                 {
    //                     if (right_child_ind(i) < heap_size)
    //                     {
    //                         ind = find_and_get_index(x, min, right_child_ind(i));

    //                         cout << ind << endl;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
};

int main()
{
    heap minheap;
    minheap.Heap(2);
    int a;
    for (int i = 0; i < 10; i++)
    {

        cin >> a;
        minheap.insert(a, true);
    }

    minheap.Print();

    for (int i = 4; i >= 0; i--)
    {
        minheap.min_heapify(10, i);
    }
    minheap.Print();
    minheap.deletes_root(true);
    minheap.Print();

    for (int i = 4; i >= 0; i--)
    {
        minheap.max_heapify(10, i);
    }
    minheap.Print();
    minheap.deletes_root(false);
    minheap.Print();

    minheap.heapsort(false);
    minheap.Print();
    minheap.heapsort(true);
    minheap.Print();

    // minheap.heapsort(false);

    // int ind = -3;
    // ind = minheap.find_and_get_index(8, true, 0);
    // cout << ind << endl;

    //  minheap.max_heapify(4);
    //  minheap.Print();
    //   minheap.max_heapify(0);
    //  minheap.Print();
    //   minheap.max_heapify(0);
    //  minheap.Print();
    //   minheap.max_heapify(0);
    //  minheap.Print();
}