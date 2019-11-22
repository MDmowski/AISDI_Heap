#include <utility>
#include <vector>
#include <algorithm>


template<typename KeyType, typename ValueType>
class Heap4
{
    using KeyValueType = std::pair<const KeyType, ValueType>;

    std::vector<KeyValueType> list;     // vector of elements

    int parent(int i){ 
        int index = (i - 1)/4;
        if(index > list.size() - 1)
            return -1;
        return index;
    }
    int child(int i, int childNum){ 
        int index = 4*i + childNum;
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
            std::swap(list[index], list[smallestIndex]);
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
                std::swap(list[i], list[parent(i)]);
                i = parent(i);
            }
    }

    KeyValueType const & peek() const noexcept
    {
        if(!empty())
            return list[0];
    }

    KeyValueType pop() noexcept
    {
        if(list.size() <= 0){
            std::cout<<"No elements";
            return KeyValueType();
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
