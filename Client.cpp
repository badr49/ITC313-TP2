
#include "Client.h"
#include <iostream>



Client::Client(std::string n, std::string p){
	m_nom = n ;
	m_prenom = p ;
}

int Client::getID(){
	return m_id;
}

std::string Client::getNOM(){
	return m_nom;
}

std::string Client::getPRENOM(){
	return m_prenom;
}

std::vector<Produit*> Client::getPANIER(){
	return m_panier;
}