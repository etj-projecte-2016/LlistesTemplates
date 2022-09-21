#pragma once

#ifndef LLISTA_H
#define LLISTA_H

#include "Node.h"
#include  <iostream>
using namespace std;

template<class T>
class Llista
{
public:
	Llista() { m_primer = nullptr;	}
	~Llista();
	bool esBuida() const { return (m_primer == nullptr); }
	Node<T> *getInici() const { return m_primer; }
	Node<T> *insereixNext(const int& valor, Node<T> *posicio);
	Node<T> *eliminaNext(Node<T>* posicio);
	void mostraLlista() const;
private:
	Node<T>* m_primer;
};

template <class T>
Llista<T>::~Llista()
{
	while (m_primer != nullptr)
		eliminaNext(nullptr);
}

template <class T>
Node<T>* Llista<T>::insereixNext(const int& valor, Node<T>* posicio)
{
	Node<T>* aux = new Node<T>();
	if (aux != nullptr)
	{
		aux->setValor(valor);
		if (posicio == nullptr)
		{
			aux->setNext(m_primer);
			m_primer = aux;
			return aux;
		}

		aux->setNext(posicio->getNext());
		posicio->setNext(aux);
		return aux;
	}
	return aux;
}

template <class T>
Node<T>* Llista<T>::eliminaNext(Node<T>* posicio)
{
	Node<T>* aux;
	Node<T>* seguent = nullptr;
	if (posicio == nullptr)
	{
		aux = m_primer;
		m_primer = aux->getNext();
		delete aux;
		seguent = m_primer;
		return seguent;
	}

	aux = posicio->getNext();
	if (aux != nullptr)
	{
		posicio->setNext(aux->getNext());
		seguent = aux->getNext();
		delete aux;
	}

	return seguent;
}

template <class T>
void Llista<T>::mostraLlista() const
{
	Node<T>* aux = getInici();
	while (aux != NULL)
	{
		cout << aux->getValor() << " ";
		aux = aux->getNext();
	}
	cout << endl;
}



#endif // LLISTA_H