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

void Magasin::AddProduct( Produit prod){
	
	
	Produit *pr = &prod ;
	m_products.push_back(pr);

}

std::vector<Client*> Magasin::getCLIENTS() const
{
	return m_clients ;
}
/*
std::vector<Commande*> getORDERS() const
{
	return m_orders ;
}
*/
std::ostream& operator << (std::ostream &output, const Magasin &obj)
{
	
	std::cout<<"-----------------------------EASYSTORE-----------------------------------" << std::endl ;
	std::cout<<"-------------------------------------------------------------------------" << std::endl ;
	std::cout<<"-----------------------------Products :----------------------------------" << std::endl ;
	
	for(Produit* prd: obj.m_products)
	{
		output << *prd << std::endl;
		
	}

	std::cout<<"-------------------------------------------------------------------------" << std::endl ;
	std::cout<<"-----------------------------Clients :-----------------------------------" << std::endl ;
	
	for(Client* cl: obj.m_clients)
	{
		output << *cl << std::endl;
	}

	std::cout<<"-------------------------------------------------------------------------" << std::endl ;
	std::cout<<"----------------------------Commandes :-----------------------------------" << std::endl ;

	for(Commande* oder: obj.m_orders)
	{
		output << *oder << std::endl;
	}

	return output;
}


void Magasin::LookForProduct(std::string title)
{
	bool p=false ;
	int a = m_products.size(); 
	
	for(int i=0; i<a; i++)
	{
		if ((m_products.at(i))->getTITLE() == title)
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

void Magasin::SetProductQuantity(std::string a,int q)
{

	
	for(Produit* prd: m_products)
	{
		
		if (prd->getTITLE() == a)
		{
			prd->setQUANTITY(q) ;
			std::cout << "updated product on the store :"  ;
			std::cout << *prd << std::endl ;
		}
	}
}

void Magasin::AddClient(Client cl)
{
	Client *ptr = &cl ;
	m_clients.push_back(ptr);

}


void Magasin::ClientsDisplay(){
	std::cout<<"-----------------------------Clients :--------CD---------------------------" << std::endl ;
	//int a = m_clients.size();
	for(Client* cl: m_clients)
	{
		
	std::cout<< (cl->getPANIER()).size() << std::endl;			
	std::cout<< *cl << std::endl;
		
	}

}

Client* Magasin::LookForClient(int id)
{
	std::cout<<"-----------------------Looking for "<< id <<" -----------------------------"<< std::endl;
//	bool p = false ;
	int  a = m_clients.size(); 
	int pos = 0 ;
	for(int i=0; i<a; i++)
	{
		if ((m_clients.at(i))->getID() == id)
		{
			//std::cout << *m_clients.at(i) ;
			pos = i ;			
			//p = true ;	
				
		}

	}
/*	if (p == false)
	{
		std::cout << "Client introuvable!" << std::endl ;
		o
	}
*/
	return m_clients.at(pos) ;	
}
	
void Magasin::LookForClient(std::string nom)
{
	std::cout<<"-----------------------Looking for "<< nom <<" -----------------------------"<< std::endl;
	bool p=false ;
	int a = m_clients.size(); 
	
	for(int i=0;i<a;i++)
	{
		if ((m_clients.at(i))->getNOM() == nom)
		{
			std::cout << *m_clients.at(i) ;
			p = true ;	
		}

	}
	if (p == false)
		std::cout << "Client introuvable!" << std::endl ;
}
 
void Magasin::AddProdPanier(Client* c, Produit* prod, int quantity)
{
	if( prod->getQUANTITY() < quantity )
	{
		std::cout << "Le magasin ne contient que "<< prod->getQUANTITY() << " articles de ce produit " << std::endl ;
	}
	else
	{	
		for( Client* clt: m_clients )
		{
			if( clt->getID() == c->getID() ) 
			{
				for( Produit* prd: m_products )
				{
					if( prd->getTITLE() == prod->getTITLE() )
					{
						std::cout << "add fct, la ref du produit est : " << prd << std::endl;
						clt->AddProductBasket(prd) ;
						ModProdQuantite( clt, prd->getTITLE(), quantity) ;

						int q = prd->getQUANTITY() - quantity ;
						SetProductQuantity( prd->getTITLE(), q) ;	
					}
				}	
			}
		}	
	}
}

void Magasin::DelProdPanier(Client* c, std::string title)
{
	
	LookForClient( c->getID() )->DelProductBasket( title) ;
}

void Magasin::ModProdQuantite(Client* c, std::string title, int quantite)
{
	LookForClient( c->getID() )->SetQuantity( title, quantite) ;
}

void Magasin::ValidOrder(Commande* com)
{
	std::string inp = "" ;
	std::cout << "Voulez vous commander tout votre panier? (o/n) : " << std::endl ;
	std::cin >> inp ;

	if( inp == "o" )
	{
		Client* clt = LookForClient( com->getCLIENT()->getID() ) ;
		std::cout << " taille de m : " << clt->getPANIER().size() ;
		for(Produit* prd: clt->getPANIER() )
		{
			
			com->AddProductOrder(prd) ;
			std::cout << std::endl << "size prod achetes : " << com->getPRODUITS().size() << std::endl ;
		}	
	}
	if( inp == "n" )
	{
		std::cout << "votre panier de produits achetés est vide pour le moment. " << std::endl ;
	}
//
	std::string input= "" ;

	std::cout<<"Do you really want to valid this order? (o/n) "<< std::endl ;
	std::cin >> input ;
	if ( input == "o")
	{
//		LookForClient( com->getCLIENT()->getID() ) ;
		m_orders.push_back(com) ;
		std::cout<<"new m_orders size : "<< m_orders.size() <<std::endl;
		std::cout<< *m_orders.at( m_orders.size()-1 ) << std::endl;	
	}
}

void Magasin::UpdateStatus(Commande& cm)
{
	for( Commande* com: m_orders)
	{
		if( (com->getCLIENT())->getID() == (cm.getCLIENT())->getID() )
		{
			com->setSTATUS() ;
		}	
	}
}


void Magasin::OrdersDisplay()
{
	std::cout<<"-----------------------------Orders :-----------------------------------" << std::endl ;
	
	for(Commande* cm: m_orders)
	{
		std::cout<< *cm << std::endl;	
	}
}

void Magasin::OrdersClientsDisplay(Client& cl)
{
	bool p=false ;
	
	for(Commande* com: m_orders)
	{
		if ( (com->getCLIENT())->getID() == cl.getID())
		{
			std::cout << *com ;
			p = true ;	
		}

	}
	if (p == false)
		std::cout << "Ce client n'a aucune commande pour le moment!" ;	
}
/*
*/






