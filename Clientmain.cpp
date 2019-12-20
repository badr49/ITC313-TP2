
#include "Client.h"
#include <iostream>




int main(){

	Client elki(56148, "Haidar", "Younes") ;
	elki.addPP("CHIPS","spicy", 2, 2) ;
	elki.addPP("jacket","blue", 1, 100) ;
	elki.addPP("xbox","Microsoft", 1, 320) ;
	elki.addPP("pc","HP", 1, 599) ;
	

	std::cout << elki ;

	
	std::cout <<"-------------------------------------------------------------------------------------------\n";
	std::cout << "changing quantity...\n" ;

	elki.ModifQ("CHIPS", 3) ;
	std::cout <<"-------------------------------------------------------------------------------------------\n";

	std::cout << elki ;

	std::cout <<"-------------------------------------------------------------------------------------------\n";

	elki.delPR("jacket");
	
	std::cout <<"-------------------------------------------------------------------------------------------\n";

	std::cout << elki;


	return 0;
}