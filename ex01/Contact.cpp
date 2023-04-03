# include "Contact.hpp"


Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string secret)
{
	this->f_name = f_name;
	this->l_name = l_name;
	this->n_name = n_name;
	this->p_number = p_number;
	this->secret = secret;
	id = 0;
	return;
}

Contact::Contact()
{
	f_name = "";
	l_name = "";
	n_name = "";
	p_number = "";
	secret = "";
	id = 0;
	return;
}

Contact::~Contact(void){ return; }

std::string Contact::getf_name(void){ return (f_name); }

std::string Contact::getl_name(void){ return (l_name); }

std::string Contact::getn_name(void){ return (n_name); }

std::string Contact::getp_number(void){ return (p_number); }

std::string Contact::getsecret(void){ return (secret); }

void	Contact::setid(int newid){ id = newid; }

int 	Contact::getid(){ return (id); }
