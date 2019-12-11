

#include "Produit.h"
#include <string>
#include <iostream>

Produit::Produit(std::string t, std::string de, int q, float p){
	m_title = t ;
	m_descr = de ;
	m_q = q ;
	m_prix = p ;
}

std::string Produit::getTITLE(){
	return m_title ; 
}

std::string Produit::getDESCR(){
	return m_descr ;
}

int Produit::getQ(){
	return m_q ;
}

float Produit::getPRIX(){
	return m_prix ;
}

void Produit::setQ(int c){
	m_q = c ;
}

std::ostream& operator << (std::ostream &output, Produit obj){
	output << obj.m_title <<" | "<<obj.m_descr<<" | "<<obj.m_q<<" | "<<obj.m_prix <<"$"<< std::endl;
	return output;

}


