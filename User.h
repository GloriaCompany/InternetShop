#pragma once
#include <string>
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

	void setId();
	void setRole();
	void setLogin();
	void setPassword();

	virtual void showAllProducts();
	virtual void showInfoProductByName();
	virtual void showInfoProductByArticle();
};