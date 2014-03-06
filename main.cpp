#include <iostream>
#include <fstream>
#include <string>

int main ()
{
   using std::cout;
   using std::cin;
   using std::endl;
   using std::ios_base;

   const char* str1 = "Today I	 will   be	go  home     after work!";
   const char* str2 = "After I     spend time   whith    my	   freiends!";

   // creating the object stream , file and write data into it:
	 const char* filename1 = "data1.txt";
   std::fstream inOutFile;

   inOutFile.open(filename1, ios_base::out | ios_base::trunc/*| ios_base::app*/ );
   if(inOutFile.is_open())
   {
      inOutFile << str1 << endl;
      inOutFile << str2 << endl;
   }
   inOutFile.clear();
   inOutFile.close();
   cout << "File created!" << endl;

   // Check file for space
   char ch;
	 std::string s1;
   inOutFile.open(filename1, ios_base::in);
   if(inOutFile.is_open())
   {
      while(inOutFile.get(ch))
      {
				if(isspace (ch))
				{
					if(isspace (inOutFile.peek ())) continue;
					else s1 += ch;
				}
        else s1 += ch;
      }
      if(inOutFile.eof()) inOutFile.clear();
			inOutFile.close ();
   }
    // rewrite current file
    inOutFile.open (filename1, ios_base::out | ios_base::trunc);
    if(inOutFile.is_open ())
    {
       inOutFile << s1;
       inOutFile.close ();
    }
    // print string
    cout << s1 << endl;
   cout << "File checked!" << endl;
	// std::cin.get ();
   return 0;
}
