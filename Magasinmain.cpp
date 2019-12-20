
#include "Magasin.h"
#include <iostream>

int main()
{

	Magasin fig ;


	fig.addPROD("jacket","blue", 50, 100) ;
	fig.addPROD("CHIPS", "spicy", 100, 2) ;
	std::cout << fig ; 
	fig.LookPROD("jacket") ;

	fig.ModifPQ("CHIPS", 320);




	return 0;
}

