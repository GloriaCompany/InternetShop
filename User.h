#pragma once
#include "Product.h"
#include "defines.h"

class User
{
private:
	int id;
	int role;
	std::wstring login;
	std::wstring password;
public:
	User();
	User(int _id, int _role, std::wstring _login, std::wstring _password);
	virtual ~User();

	int getId();
	int getRole();
	std::wstring getLogin();
	std::wstring getPassword();

	void setId(int id);
	void setRole(int role);
	void setLogin(std::wstring login);
	void setPassword(std::wstring password);
};