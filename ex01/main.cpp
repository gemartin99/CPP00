#include <iostream>
#include <string>
#include <stdio.h>

# include "Phonebook.hpp"
# include "Contact.hpp"

static bool is_digits(const std::string &str)
{
	return (str.find_first_not_of("0123456789") == std::string::npos);
}

static void ft_add(Phonebook *p_list)
{
	int i;
	std::string info[5];

	i = -1;
	while (++i < 5)
	{
		switch(i)
		{
			case 0:
				std::cout << "Introduce the first name" << std::endl;
				break;
			case 1:
				std::cout << "Introduce the last name" << std::endl;
				break;
			case 2:
				std::cout << "Introduce the nickname" << std::endl;
				break;
			case 3:
				std::cout << "Introduce the phone number" << std::endl;
				break;
			case 4:
				std::cout << "Introduce the darkest secret" << std::endl;
				break;
		}
		if (std::getline(std::cin, info[i]).rdstate() != 0)
			exit (-1);
		if (i == 3 && is_digits(info[i]) && info[i] != "")
			;
		else if ((i == 3 && !is_digits(info[i])) || info[i] == "")
		{
			std::cout << "Invalid input" << std::endl;
			i--;
		}
	}
	Contact newcontact(info[0], info[1], info[2], info[3], info[4]);
	(*p_list).addcontact(newcontact);
}

static std::string check_len(std::string str)
{
	std::string tmp = "          ";
	int j = str.length();

	if (j == 10)
		return (str);
	else if (j < 10)
	{
		tmp = tmp.substr(0, 10-j);
		tmp.append(str);
		return (tmp);
	}
	tmp = str.substr(0,9);
	tmp.append(".");
	return (tmp);
}

static void print_data(Contact contact)
{
	std::cout << "First Name:" << contact.getf_name() << std::endl;
	std::cout << "Last Name:" << contact.getl_name() << std::endl;
	std::cout << "Nick Name:" << contact.getn_name() << std::endl;
	std::cout << "Phone Number:" << contact.getp_number() << std::endl;
	std::cout << "Darkest Secret:" << contact.getsecret() << std::endl;
}

static void ft_search(Phonebook *p_list)
{
	int i = 0;
	int j = 1;
	int c = 0;
	std::string	put = "";
	Contact	*temp = (*p_list).getList();

	if (p_list->getlen() == 0)
	{
		std::cout << "Phonebook is empty. You must add Contacts to be able to search for them." << std::endl;
		return ;
	}
	std::cout << "*********************************************" << std::endl;
	while (i < (*p_list).getlen())
	{
		c = 0;
		while (j == ((*p_list).getList())[c].getid())
		{
			std::cout << "*         " << temp[c].getid() << "|";
			std::cout << check_len(temp[c].getf_name()) << "|";
			std::cout << check_len(temp[c].getl_name()) << "|";
			std::cout << check_len(temp[c].getn_name()) << "*" << std::endl;
			j++;
			c++;
		}
		i++;
	}
	std::cout << "*********************************************" << std::endl;
	std::cout << "Introduce el id del contacto" << std::endl;
	std::cin >> put;
	i = -1;
	while (++i < p_list->getlen())
	{
		if (put == std::to_string(temp[i].getid()))
		{
			print_data(((*p_list).getList())[i]);
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			return ;
		}
	}
	std::cout << "Id incorrecto" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
}

int main(int argc, char **argv)
{
	Phonebook p_list;
	std::string	input = "";

	(void)argv;
	if (argc != 1)
		return (0);
	std::cout << "Avaible commands: ADD, SEARCH, EXIT." << std::endl;
	while (input != "EXIT")
	{
		std::cout << '>';
		if (std::getline(std::cin, input).rdstate() != 0)
			exit (-1);
		if (input == "SEARCH")
			ft_search(&p_list);
		if (input == "ADD")
			ft_add(&p_list);
	}
	return 0;
}