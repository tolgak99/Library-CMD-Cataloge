#pragma once
#include "Users.h"


class Admin : public Users {

public:
	 void set_password(string);
	 void set_username(string);
	 string get_password();
	 string get_username();
	 bool check_profile(string,string);
	 bool check_username(string);
	 void update_password(string);
	 bool check_password(string);
	 void add_book(string,string,string,string,string,string);
	 void search_by_name(string , string);
	 void search_by_author(string , string);
	 void search_by_year(string );
	 void search_by_company(string);
	 bool is_empty(std::ifstream& );

private:
   string password;
   string name;

};
