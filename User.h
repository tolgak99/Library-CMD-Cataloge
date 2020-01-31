#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include "rlutil.h"
#include <direct.h>


using namespace std;

class Users {

public:
	virtual void set_password(string)=0;
	virtual void set_username(string)=0;
	virtual string get_password()=0;
	virtual string get_username()=0;
	virtual bool check_profile(string,string)=0;
	virtual bool check_username(string)=0;
	virtual void search_by_name(string , string)=0;
	virtual void search_by_author(string , string)=0;
	virtual void search_by_year(string )=0;
	virtual void search_by_company(string)=0;
private:
   string password;
   string name;

};
