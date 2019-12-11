/**
  * File:     Magasin.h
  * Author:   fig
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  Declaration of Magasin
  */

#ifndef _MAGASIN_H
#define _MAGASIN_H

#include <string>
#include <iostream>
#include <vector>
#include "Produit.h"
/*
#include "Client.h"
#include "Commande.h"
*/
class Magasin{
	public :
		Magasin() ;
		void addPROD(const std::string& t, const std::string& de, const int& q, const float& p);
		friend std::ostream& operator<< (std::ostream &output, const Magasin& obj);
		void LookPROD(Produit* t) ;
		void ModifPQ(Produit* t,int* q);	
		
	private :
		std::vector<Produit*> m_products;
		/*
		std::vector<Client*> m_clients ;
		std::vector<Order*> m_orders ;

	*/
};
#endif