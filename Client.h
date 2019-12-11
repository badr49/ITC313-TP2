

#ifndef _CLIENT_H
#define _CLIENT_H


#include "Produit.h"
#include <string>
#include <vector>

class Client {
	public :
		Client(int id, std::string n, std::string p);
		int getID();
		std::string getNOM();
		std::string getPRENOM();
		std::vector<Produit*> getPANIER();
		friend std::ostream& operator<< (std::ostream &output, const Client& obj);
	private :
		int m_id ;
		std::string m_nom ;
		std::string m_prenom ;
		std::vector<Produit*> m_panier;

};
#endif