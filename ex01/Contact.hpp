#ifndef Contact_HPP
# define Contact_HPP

# include <string>
# include <iostream>

class Contact
{
private:
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	p_number;
	std::string	secret;
	int			id;
public:
	Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string secret);
	Contact();
	~Contact();
	std::string	getf_name(void);
	std::string	getl_name(void);
	std::string	getn_name(void);
	std::string	getp_number(void);
	std::string	getsecret(void);
	void		setid(int newid);
	int 		getid();
};

#endif