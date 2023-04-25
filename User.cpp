#include "User.h"

User::User(int _id, int _role, std::string _login, std::string _password)
	: id(_id), role(_role), login(_login), password(_password){}

User::~User() {}

int User::getId() { return this->id; }
int User::getRole() { return this->role; }
std::string User::getLogin() { return this->login; }
std::string User::getPassword() { return this->password; }

void User::setId(int id) { this->id = id; }
void User::setRole(int role) { this->role = role; }
void User::setLogin(std::string login) { this->login = login; }
void User::setPassword(std::string password) { this->password = password; }

void User::showAllProducts(std::deque<Product>& products)
{

}

void User::showInfoProductByName(std::deque<Product>& products, std::string productName)
{

}

void User::showInfoProductByArticle(std::deque<Product>& products, std::string productName)
{

}

bool User::auth(std::string _login, std::string _password)
{
    
    if (_login.empty() || _password.empty()) {
        return false;
    }

    if (_login.find(' ') != std::string::npos || _password.find(' ') != std::string::npos) {
        return false;
    }

    const int MIN_LOGIN_LENGTH = 5;
    const int MIN_PASSWORD_LENGTH = 8;
    if (_login.length() < MIN_LOGIN_LENGTH || _password.length() < MIN_PASSWORD_LENGTH) {
        return false;
    }

    const int MAX_LOGIN_LENGTH = 15;
    const int MAX_PASSWORD_LENGTH = 15;
    if (_login.length() > MAX_LOGIN_LENGTH || _password.length() > MAX_PASSWORD_LENGTH) {
        return false;
    }

    if (login == _login && password == _password) {
        return true;
    }
    else {
        return false;
    }
}