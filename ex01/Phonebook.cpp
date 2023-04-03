#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	len = 0;
	return;
}

Phonebook::~Phonebook(void){ return; }

void Phonebook::addcontact(Contact newcontact)
{
	static int i = 0;

	if (i == 8)
		i = 0;
	list[i] = newcontact;
	list[i].setid(i + 1);
	if (len < 8)
		len++;
	i++;
}

Contact *Phonebook::getList(void){ return (list); }

int	Phonebook::getlen(void){ return (len); }