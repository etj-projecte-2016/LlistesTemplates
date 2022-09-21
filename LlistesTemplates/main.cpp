#include "Llista.h"

int main()
{
	/////////////////////
	//Prova Llista Enters

	Llista<int> li;

	int max = 20;
	for (int i = 0; i < max; i++)
	{
		li.insereixNext(i, NULL);
	}
	//Escriptura
	cout << "Escrivint llista sencers\n";
	li.mostraLlista();

	return 0;
}