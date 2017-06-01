class Stack
{
private:
	int* m_elements;
	size_t m_capacity;
	size_t m_count;

	void ExpandMemory();

public:
	Stack(int element);
	Stack(const Stack& stack);
	~Stack();

	Stack& operator=(Stack& element);
	Stack& operator<<(int element);
	Stack& operator>>(int element);

	void Push(int element);
	int Pop();
	size_t GetCount();
	int Top();
	void Clear();

};
