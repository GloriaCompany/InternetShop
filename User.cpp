#include "User.h"

User::User(int _id, int _role, std::string _login, std::string _password)
	: id(_id), role(_role), login(_login), password(_password){}

User::~User() {}

int User::getId() { return this->id; }
int User::getRole() { return this->role; }
std::string User::getLogin() { return this->login; }
std::string User::getPassword() { return this->password; }

void User::setId() { this->id = id; }
void User::setRole() { this->role = role; }
void User::setLogin() { this->login = login; }
void User::setPassword() { this->password = password; }

void User::showAllProducts()
{

}

void User::showInfoProductByName()
{

}

void User::showInfoProductByArticle()
{

}
