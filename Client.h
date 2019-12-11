

#ifndef _CLIENT_H
#define _CLIENT_H


#include "Produit.h"
#include <string>
#include <vector>

class Client {
	public :
		Client(std::string n, std::string p);

		friend std::ostream& operator<< (std::ostream &output, const Client& obj);
	private :
		std::string m_nom ;
		std::string m_prenom ;
		std::vector<Produit*> m_panier;

};
#endif