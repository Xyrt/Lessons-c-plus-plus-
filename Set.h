class Set
{
	int* m_elements;
	size_t m_capacity;
	size_t m_count;

	void ExpandMemory();

public:
	Set();
	bool Contains(int element) const;
	size_t GetCount() const;
	void Add(int element);
	void Remove(int element);
};
