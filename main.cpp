#include <iostream>
#include <fstream>
#include <string>

int main ()
{
   using std::cout;
   using std::cin;
   using std::endl;
   using std::ios_base;

   const char* str1 = "Today I go home after work!";
   const char* str2 = "After I spend time    whith my freiends!";
   const char* filename1 = "data1.txt";
   //const char* filename2 = "data2.txt";

   // creating the object stream , file and write data into it:
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
   int counter1 = 0;
  // int counter2 = 0;
   inOutFile.open(filename1, ios_base::in | ios_base::out);
   if(inOutFile.is_open())
   {
      while (inOutFile.get(ch)) ++counter1; // read symbols
      if(inOutFile.eof()) inOutFile.clear(); // reset flag eof
      inOutFile.seekg(0);

      std::string s1;
      std::string s2;
      while(inOutFile)
      {
         inOutFile.get(ch);
         if(!isspace(ch))
         {
            s1 += ch;
         }
         else
         {
            if(isspace(inOutFile.peek()))
            {
               s2
            }
         }
         //s2 += s1 + " ";
      }
      inOutFile.close();
      if(inOutFile.eof()) inOutFile.clear();
      cout << s1 << endl;
   }

   cout << "File checked!" << endl;
   cout << "Symbols: " << counter1 << endl;


   #if 0
   char ch;
   const char endLine = '\n';
   while(cin.get(ch) ) // завершение по достижении EOF
   {
      if (ch != endLine)
         cout << ch;
      else
      {
         cin.putback(ch); // повторная вставка символа
         break;
      }
   }
   if (!cin.eof())
   {
      cin.get(ch);
      cout << endl << ch << " is next input character.\n";
   }
   else
   {
      cout << "End of file reached. \n"; // достигнут конец файла
      //std::exit(0);
   }
   while(cin.peek() !='#') // "заглядывание" вперед
   {
      cin.get (ch);
      cout << ch;
   }
   if (!cin.eof ())
      {
         cin.get(ch);
         cout << endl << ch << " is next input character.\n";
      }
   else
      cout << "End of file reached. \n"; // достигнут конец файла
   #endif
   return 0;
}
