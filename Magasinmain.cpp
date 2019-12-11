
#include "Magasin.h"
#include <iostream>

int main()
{

	Magasin fig ;

	fig.addPROD("jacket","blue", 50, 100) ;
	fig.addPROD("CHIPS", "spicy", 100, 2) ;
	std::cout << fig ; 


	return 0;
}

