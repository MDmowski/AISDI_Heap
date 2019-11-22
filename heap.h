#include <utility>

template<typename KeyType, typename ValueType>
class Heap4
{
  public:
    using KeyValueType = std::pair<const KeyType, ValueType>;

	bool empty() const noexcept
	{
		std::terminate();
	}

	void insert(KeyType const & key, ValueType const & value)
	{
		std::terminate();
	}

	void insert(KeyValueType const & key_value)
	{
		std::terminate();
	}

	KeyValueType const & peek() const noexcept
	{
		std::terminate();
	}

	KeyValueType pop() noexcept
	{
		std::terminate();
	}

	size_t size() const noexcept
	{
		std::terminate();
	}

	template<typename StreamType>
	void print(StreamType& stream) const
	{
		std::terminate();
	}
};
