/**
  * File:     Client.cpp
  * Author:   Rachdad Badr
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  implementation of Order class
  */


#include "Commande.h"
#include <iostream>
#include <string>


Commande::Commande(Client* cl) : m_client(cl) 
{

	m_status = "Non Livree" ;

	
/*	else
		std::cout << "Votre réponse ne peut etre que o(oui) ou n(non) . " << std::endl ;
*/}


Client* Commande::getCLIENT(){
	return m_client ;
}
std::vector<Produit*> Commande::getPRODUITS(){
	return m_produits_achetes ;
}

std::string Commande::getSTATUS(){
	return m_status ;
}

void Commande::AddProductOrder(Produit* product) 
{
	m_produits_achetes.push_back(product) ;
}

void Commande::setSTATUS()
{
	if ( m_status == "Non Livree" )
	{
		m_status = "Livree" ;
	}
	else 
		m_status = "Non Livree" ;
}

std::ostream& operator<< (std::ostream &output, Commande& obj)
{
	output << "           ID : " << obj.m_client->getID() <<"            Nom : "<<obj.m_client->getNOM()<< std::endl ;

	std::cout<<"----------------------------------Statut :----------------------------------" << std::endl ;

	output << obj.m_status << std::endl ;
	
	std::cout<<"----------------------------Produits Achetés :----------------------------------" << std::endl ;
	output << "vous avez " << obj.m_produits_achetes.size() << " articles dans votre panier f" << std::endl;

	for(Produit* prd: obj.m_produits_achetes)
	{
		output << *prd << std::endl ;
	}

	return output;
}
