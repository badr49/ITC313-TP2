/**
  * File:     Magasin.cpp
  * Author:   fig
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


void Magasin::LookPROD(Produit* t){
	int a = m_products.size(); 
	for(int i=0;i<a;i++){
		if (m_products.at(i) == t)
		{
			std::cout << t ;
			break ;
		}
	}
	std::cout << "produit introuvable!" ;
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

