#include "User.h"
#include <limits>
#include <array>

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

const std::array<wchar_t, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','¹','?' };

bool User::auth(std::wstring _login, std::wstring _password)
{
    if (_login.empty() || _password.empty()) {
        return false;
    }

    if (_login.find(' ') != std::wstring::npos || _password.find(' ') != std::wstring::npos) {
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