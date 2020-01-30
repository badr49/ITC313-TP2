/**
  * File:     Client.h
  * Author:   Rachdad Badr
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  Declaration of Order
  */

#ifndef _COMMANDE_H_
#define _COMMANDE_H_

#include "Client.h"
#include "Produit.h"
#include <vector>
#include <string>

class Commande {
	//enum status ("Livrée", "Non Livrée") ;
	private :
		Client* m_client ;
		std::vector<Produit*> m_produits_achetes ;
		std::string m_status ;

	public :
		
		Commande(Client* cl) ;
		Client* getCLIENT() ;
		std::vector<Produit*> getPRODUITS() ;
		std::string getSTATUS() ;
		void AddProductOrder(Produit* product) ;
		void setSTATUS() ;
		friend std::ostream& operator<< (std::ostream &output, Commande& obj);



};
#endif
