#pragma once
#include <string>
#include <deque>
#include "Product.h"

class User
{
private:
	int id;
	int role;
	std::string login;
	std::string password;
public:
	User() {};
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

	virtual void showAllProducts(std::deque<Product>& products);
	virtual void showInfoProductByName(std::deque<Product>& products, std::string productName);
	virtual void showInfoProductByArticle(std::deque<Product>& products, std::string article);
	bool auth(std::string _login, std::string _password);
};