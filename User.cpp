#include "User.h"
#include <limits>
#include <array>
#include "Shop.h"

User::User()
{
}

User::User(int _id, int _role, std::wstring _login, std::wstring _password)
	: id(_id), role(_role), login(_login), password(_password){}

User::~User() {}

int User::getId() { return this->id; }
int User::getRole() { return this->role; }
std::wstring User::getLogin() { return this->login; }
std::wstring User::getPassword() { return this->password; }

void User::setId(int id) { this->id = id; }
void User::setRole(int role) { this->role = role; }
void User::setLogin(std::wstring login) { this->login = login; }
void User::setPassword(std::wstring password) { this->password = password; }
