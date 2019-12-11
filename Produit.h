
#ifndef _PRODUIT_H
#define _PRODUIT_H

#include <string>


class Produit{
	public:
		Produit(std::string t, std::string de="add description...", int q=1, float p=1);
		std::string getTITLE();
		std::string getDESCR();
		int getQ();
		float getPRIX();
		void setQ(int c);
		
		friend std::ostream& operator << (std::ostream &output, Produit obj);
		
	private:
		std::string m_title ;
		std::string m_descr ;
		int m_q ;
		float m_prix ;

};



#endif
