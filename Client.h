/**
  * File:     Client.h
  * Author:   rachdad badr
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  Declaration of Client
  */

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
		void addPP(const std::string& t, const std::string& de, const int& q, const float& p) ;
		void delP();
		void ModifQ(std::string k, int l);
		void delPR(std::string g);
		friend std::ostream& operator<< (std::ostream &output, const Client &obj);
		

	private :
		int m_id ;
		std::string m_nom ;
		std::string m_prenom ;
		std::vector<Produit*> m_panier;

};
#endif