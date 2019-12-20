/**
  * File:     Client.cpp
  * Author:   rachdad badr
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  implementation of Client class
  */

#include "Client.h"
#include <iostream>
#include <string>



Client::Client(int id, std::string n, std::string p){
	m_id = id ;
	m_nom = n ;
	m_prenom = p ;
}

std::ostream& operator << (std::ostream &output, const Client& obj)
{
	int a = obj.m_panier.size();
	for(int i=0;i<a;i++){
	output << *obj.m_panier.at(i) << std::endl;
}
return output;
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

void Client::addPP(const std::string& t, const std::string& de, const int& q, const float& p){
	Produit *pr = new Produit(t, de, q, p) ;
	m_panier.push_back(pr);

}

void Client::delP(){
	m_panier.clear() ;
}
void Client::ModifQ(std::string k, int l){
	std::cout << "Loading....\n" ;

	int o = m_panier.size(); 
	
	for(int i=0;i<o;i++){
		
		if ((m_panier.at(i))->getTITLE() == k){
			m_panier.at(i)->setQ(l) ;
			std::cout << "Done!\n" ;
			std::cout << *m_panier.at(i) ;
		}
	}

}

void Client::delPR(std::string g){
	
	int o = m_panier.size(); 
	
	for(int i=0;i<o;i++){
		
		if (m_panier.at(i)->getTITLE() == g){
			m_panier.erase(m_panier.begin()+i) ;
			std::cout << g << " Erased!\n" ;
			break ;
		}
	}
	
}

