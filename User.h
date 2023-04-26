#pragma once
#include "Product.h"
class User
{
private:
	int id;
	int role;
	std::string login;
	std::string password;
public:
	User(int _id, int _role, std::string _login, std::string _password);
	virtual ~User();

	int getId();
	int getRole();
	std::string getLogin();
	std::string getPassword();

	void setId(int id);
	void setRole(int role);
	void setLogin(std::string login);
	void setPassword(std::string password);

	bool auth(std::string _login, std::string _password);
};