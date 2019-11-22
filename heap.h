#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>


template<typename KeyType, typename ValueType>
class Heap4
{
    using KeyValueType = std::pair<KeyType, ValueType>;

    std::vector<KeyValueType> list;     // vector of elements

    int parent(int i){ 
        unsigned int index = (i - 1)/4;
        if(index > list.size() - 1)
            return -1;
        return index;
    }
    int child(int i, int childNum){ 
        unsigned int index = 4*i + childNum;
        if(index > list.size() - 1 && childNum > 4 && childNum < 1)
            return -1;
        return index;
    }; 

    void minHeapify(int index)
    {
        int smallestIndex = index;
        KeyType smallestKey = list[index].first;
        for(int i = 1; i < 5; i++){
            if(smallestKey > list[child(index, i)].first){
                smallestIndex = child(index, i);
                smallestKey = list[child(index, i)].first;
            }
        }
        if(smallestIndex != index)
        {
            std::iter_swap(list.begin() + index, list.begin() + smallestIndex);
            minHeapify(smallestIndex);
        }
    }
    
  public:

    bool empty() const noexcept
    {
        return list.empty();
    }

    void insert(KeyType const & key, ValueType const & value)
    {
        insert(KeyValueType(key, value));
    }

    void insert(KeyValueType const & key_value)
    {
            list.push_back(key_value);
            int i = list.size() - 1;
            while (i != 0 && list[parent(i)].first > list[i].second)
            {
                std::iter_swap(list.begin() + i, list.begin() + parent(i));
                i = parent(i);
            }
    }

    KeyValueType const & peek() const noexcept
    {
        if(!empty())
            return list[0];
        exit(-1);
    }

    KeyValueType pop() noexcept
    {
        if(list.size() <= 0){
            std::cout<<"No elements";
            exit(-1);
        }

        KeyValueType root = list[0];
        list.erase(list.begin());
        minHeapify(0);

        return root;
    }

    size_t size() const noexcept
    {
        return list.size();
    }

    template<typename StreamType>
    void print(StreamType& stream) const
    {
    }
};
