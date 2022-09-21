#include "Conjunt.h"
#include <iostream>
using namespace std;

Conjunt::Conjunt()
{
	m_maxElements = MAX_ELEMENTS;
	m_elements = new int[m_maxElements];
	m_nElements = 0;
}

Conjunt::~Conjunt()
{
	delete[] m_elements;
}

bool Conjunt::existeix(const int& valor) const
{	
	if (cercaElement(valor) >= 0) return true;		
	return false;
}

int Conjunt::cercaElement(const int& valor) const
{
	int posicio = 0;
	while (posicio < m_nElements)
	{
		if (m_elements[posicio] == valor)
			return posicio;
		else
			posicio++;
	}
	return -1;
}

void Conjunt::mostra() const
{
	cout << "Elements del conjunt: " << endl;
	for (int i = 0; i < m_nElements; i++)
		cout << m_elements[i] << endl;
}
bool Conjunt::afegeix(const int &valor)
{
	if (cercaElement(valor) == -1)
	{
		if (m_nElements == m_maxElements)
		{
			int* aux = new int[m_maxElements * 2];
			for (int i = 0; i < m_maxElements; i++)
				aux[i] = m_elements[i];
			delete[]m_elements;
			m_elements = aux;
			m_maxElements *= 2;
		}

		m_elements[m_nElements] = valor;
		m_nElements++;
		return true;
	}
	return false;
}

bool Conjunt::elimina(const int& valor)
{
	int posicio = cercaElement(valor);

	if (posicio >= 0)
	{
		for (int i = posicio; i < (m_nElements - 1); i++)
			m_elements[i] = m_elements[i + 1];
		m_nElements--;
		return true;
	}
	return false;
}

/*
istream& operator>> (istream& input, Conjunt& c) {

	cout << "Part Real: ";
	input >> c.m_numerador;
	cout << "Part imaginaria: ";
	input >> c.m_denominador;
	return input;

}

ostream& operator<< (ostream& output, const Conjunt& c) {

	output << c.m_numerador << "+" << c.m_denominador << "i";
	return output;

}
*/
