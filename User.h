#pragma once
#include "Users.h"


class User : public Users {

public:
	 void set_password(string);
	 void set_username(string);
	 string get_password();
	 string get_username();
	 bool check_profile(string,string);
	 bool check_username(string);
	 void open_file();
	 void update_profile(string,string);
	 void search_by_name(string , string);
	 void search_by_author(string , string);
	 void search_by_year(string );
	 void search_by_company(string);

private:
   string password;
   string name;

};
