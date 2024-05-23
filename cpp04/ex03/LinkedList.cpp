#include "LinkedList.hpp"

template <>
LinkedList<class T>::LinkedList(T& val) : value(val) {
	next = nullptr;
}

template<>
T& LinkedList<class T>::getValue() {
	return value;
}

template<>
LinkedList<class T>::LinkedList(const LinkedList<T>& copy) : value(copy.value){}

template<>
LinkedList<class T> LinkedList<class T>::append(T& val) {
	LinkedList<T>* l = new LinkedList(val);
	next = l;
	return *l;
}

