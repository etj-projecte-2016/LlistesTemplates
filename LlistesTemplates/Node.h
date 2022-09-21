#pragma once
#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

template<class T>
class Node
{
public:
	Node() : m_valor(T()), m_next(nullptr) {};
	~Node() { m_next = nullptr; };
	Node(const T& valor) : m_valor(valor), m_next(nullptr) {};
	Node<T>* getNext() const { return m_next; };
	void setNext(Node<T>* next) { m_next = next; }
	int getValor() const { return m_valor; }
	void setValor(const T& valor) { m_valor = valor; }
private:
	T m_valor;
	Node<T>* m_next;
};

#endif // NODE_H