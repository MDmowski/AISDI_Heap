#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;


template <class T>
class MinHeap
{
    std::vector<T> list;     // vector of elements
    int size; // number of elements
public:
    MinHeap() : size(0){};

    void MinHeapify(int index);

    void decreaseKey(int i, T new_val);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); } // Return index of left child

    int right(int i) { return (2 * i + 2); } // Return index of right child

    T extractMin(); 

    int getMin() { return list[0]; }

    void deleteElement(int index);

    void insertElement(T k);

    void display(int index);
};



template <class T>
void MinHeap<T>::insertElement(T k)
{
    size++;
    list.push_back(k);

    int i = size-1;
    while (i != 0 && list[parent(i)] > list[i])
    {
        std::swap(list[i], list[parent(i)]);
        i = parent(i);
    }
}
template <class T>
void MinHeap<T>::decreaseKey(int i, T new_val)
{
    list[i] = new_val;
    while (i != 0 && list[parent(i)] > list[i])
    {
        std::swap(list[i], list[parent(i)]);
        i = parent(i);
    }
}

template <class T>
T MinHeap<T>::extractMin()
{
    if (size <= 0)
        std::cout<<"No elements";
    if (size == 1)
    {
        size--;
        return list[0];
    }

    int root = list[0];
    list.erase(list.begin());
    size--;
    MinHeapify(0);

    return root;
}

template <class T>
void MinHeap<T>::deleteElement(int index)
{
    decreaseKey(index, INT_MIN);
    extractMin();
}
template <class T>
void MinHeap<T>::MinHeapify(int index)
{
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if (l < size && list[l] < list[index])
        smallest = l;
    if (r < size && list[r] < list[smallest])
        smallest = r;
    if (smallest != index)
    {
        std::swap(list[index], list[smallest]);
        MinHeapify(smallest);
    }
}

template <class T>
void MinHeap<T>::display(int index){
std::cout<<list[index]<<" ";
if(left(index) < size)
    display(left(index));
if (right(index) < size)
    display(right(index));
}

int main()
{
    MinHeap<std::string> h;
    h.insertElement("f");
    h.deleteElement(0);
    h.insertElement("2");
    h.insertElement("15");
    h.insertElement("g");
    h.insertElement("ghh");
    h.insertElement("45");
    h.display(0);
    return 0;
}
