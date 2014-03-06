#include <iostream>
#include <fstream>
#include <string>
void WriteInFile(const char* filename, std::string &str1);
void CheckFileForSpaces(const char* filename);

   using std::cout;
   using std::cin;
   using std::endl;

int main ()
{
   std::string str1 = "Today I	 will   be	go  home     after work! \n"
                        "I will     spend time   whith    my	   freiends! \n";
   // creating the object stream , file and write data into it:
   const char* filename1 = "data1.txt";
   WriteInFile(filename1, str1);
   CheckFileForSpaces(filename1);
	// std::cin.get ();
   return 0;
}

void WriteInFile(const char* filename, std::string &str1)
{
   using std::ios_base;

   std::fstream OutFile;
   OutFile.open(filename, ios_base::out | ios_base::trunc/*| ios_base::app*/ );
   if(OutFile.is_open())
      OutFile << str1;
   OutFile.clear();
   OutFile.close();
   cout << "File created!" << endl; // could be comment
}
// Check file for space
void CheckFileForSpaces(const char* filename)
{
   char ch;
	std::string tempString;
	std::fstream inFile;
   inFile.open(filename, std::ios_base::in);
   if(inFile.is_open())
   {
      while(inFile.get(ch))
      {
         if(isspace (ch))
         {
            if(isspace (inFile.peek ())) continue;
            else tempString += ch;
         }
         else tempString += ch;
      }
      if(inFile.eof()) inFile.clear();
			inFile.close ();
			cout << "File checked!" << endl; // could be comment
   }
   // rewrite current file
   WriteInFile(filename, tempString);
   // print string
   //cout << tempString << endl;
}
