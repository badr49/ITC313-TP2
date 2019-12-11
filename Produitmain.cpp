#include "Produit.h"
#include <iostream>


int main(){

	Produit a("CHIPS", "spicy", 100, 2) ;

	std::cout << a;

	a.setQ(70) ;

	std::cout << a;

return 0;
}