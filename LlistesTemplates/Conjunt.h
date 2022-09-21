#pragma once
#include <iostream>
using namespace std;

class Conjunt
{
public:
	Conjunt();
	~Conjunt();
	bool afegeix(const int& valor);
	bool elimina(const int& valor); 
	bool existeix(const int& valor) const;
	bool esBuit() const { return (m_nElements == 0); }
	void mostra() const;
	//friend istream& operator>> (istream& input, Conjunt& c);
	//friend ostream& operator<< (ostream& output, const Conjunt& c);
private:
	int *m_elements;
	int m_nElements;
	int m_maxElements;
	static const int MAX_ELEMENTS = 5;

	int cercaElement(const int& valor) const;
};

