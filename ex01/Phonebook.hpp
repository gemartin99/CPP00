#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact list[8];
	int 	len;
public:
	Phonebook();
	~Phonebook();
	void	ft_add(Contact newcontact);
	Contact *getList(void);
	int		getlen(void);
	void 	addcontact(Contact newcontact);
};

#endif
