#include "outparam.h"
#include <string>
#include <iostream>

bool get_prop(const std::string& propkey, Out<std::string> val)
{
  if( propkey == "name" )
  {
     val = "logan";
     return true;
  }

  return false;
}

  
bool get_prop2(const std::string& propkey, std::string& val)
{
  if( propkey == "name" )
  {
     val = "logan";
     return true;
  }

  return false;
}


int main()
{
  std::string pval;
  get_prop("name", out( pval ));   
  get_prop2("name",  pval );   
  std::cout << pval << "\n"; 
}
