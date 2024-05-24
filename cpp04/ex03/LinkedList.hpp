#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

template <class T>
class LinkedList
{
	private:
		T value;
	public:
		LinkedList* next;
		LinkedList() = delete;
		LinkedList(T val);
		LinkedList(const LinkedList &copy);
		LinkedList &operator=(const LinkedList &copy) = delete;
		~LinkedList() = default;
		T getValue();
		LinkedList<T> append(T val);
};

#endif
