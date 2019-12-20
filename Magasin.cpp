/**
  * File:     Magasin.cpp
  * Author:   rachdad badr
  * Date:     Fall 2019
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  implementation of Magasin class
  */


#include "Magasin.h"
#include <string>
#include <vector>
#include <iostream>



Magasin::Magasin(){

}

void Magasin::addPROD(const std::string& t, const std::string& de, const int& q, const float& p){
	Produit *pr = new Produit(t, de, q, p) ;
	m_products.push_back(pr);

}

std::ostream& operator << (std::ostream &output, const Magasin &obj)
{
	
	int a = obj.m_products.size();
	for(int i=0;i<a;i++){
	output << *obj.m_products.at(i) << std::endl;
}
return output;
}


void Magasin::LookPROD(std::string h){
	bool p=false ;
	int a = m_products.size(); 
	
	for(int i=0;i<a;i++){
		if ((m_products.at(i))->getTITLE() == h)
		{
			std::cout << *m_products.at(i) ;
			p = true ;	
		}

	}
	if (p == true)
	{
		std::cout << "produit trouvé!\n" ;
	}
	else
		std::cout << "produit introuvable!" ;
}

void Magasin::ModifPQ(std::string a,int q){
	std::cout << "Loading....\n" ;

	int o = m_products.size(); 
	
	for(int i=0;i<o;i++){
		
		if ((m_products.at(i))->getTITLE() == a){
			m_products.at(i)->setQ(q) ;
			std::cout << "Done!\n" ;
			std::cout << *m_products.at(i) ;
		}
	}
}
void Magasin::addC(const int id, const std::string n, const std::string p){

	Client *pr = new Client(id, n, p) ;
	m_clients.push_back(pr);

}


void Magasin::ClientsDisplay(){
	int a = this->m_clients.size();
	for(int i=0;i<a;i++){
		
				
	std::cout<<this->m_clients.at(i)->getID()<<" | "<<m_clients.at(i)->getNOM()<<" | "<<m_clients.at(i)->getPRENOM()<< std::endl;
		
}

}
/*
	


std::vector getPRODUCTS(){
	return m_products ;
}
std::string Magasin::Display(){
	for(int i=0;i<m_products.size();i++){
		std::cout << m_products[i] << std::endl; 
	}

}
*/

