/*
File Name: assign1_s_f88.cpp

Author: Shane Fleming
Date: 01/27/16
Assignment Number: 1
CS 2308.257 Spring 2016
Instructor: Jill Seaman

Grade Book*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

   ifstream fin;  //opening file in "fin"
   ofstream fout; //opening file out "fout"

/********************************************************************
 ex:  Calculates the average for 5 exam scores, dropping lowest grade 
 returns the total points of the exams as a int
*********************************************************************/

 int ex (int &examtot)
    {
	int  low, examscore [5];
	int x = 1;
            fin >> examscore[0];
            low = examscore[0]; 
               
          while (x < 5)
               {
                   fin >> examscore[x];
		   if (examscore[x] < low)
			low = examscore[x];
                    x++;
                }

                      examtot = (examscore[0] + examscore[1] + examscore[2] + 
                      examscore[3] + examscore[4] - low);

          return 0;

     }

/*****************************************************************
 ass:  Adds the four assignments grades together
 returns the total points of the assignments as a int
******************************************************************/

 int ass (int &asstot)
    {
        int ass[4], x = 0;
        
            while (x < 4)
               {
                   fin >> ass[x];
                      asstot += ass[x];
                    x++;
                }

          return 0;

     }

/****************************************************************
 header:  Produces a header for the "fout" file
 void: Return 0;
 Starts the desired format for the document
*****************************************************************/

 void header()
    {
         fout
         << "StudentID     Points     Percent     Grade" << endl
         << "__________________________________________" << endl
         << endl;
    }

/*****************************************************************
******************************************************************/

char lettergrade(float &temptot)
    {
        char fgrade;

                if (temptot >= 448)
                        fgrade = 'A';
                else if (temptot <= 447 && temptot >= 398)
                        fgrade = 'B';
                else if (temptot <= 397 && temptot >= 348)
                        fgrade = 'C';
                else if (temptot <= 347 && temptot >= 298)
                        fgrade = 'D';
                else
                        fgrade = 'F';
          fout << fgrade << endl;
     return 0;
    }

/*****************************************************************
******************************************************************/

void loop()
    {
string id;

while (fin >> id)
        {
           int extotal = 0, asstotal = 0, m = 0;
           float temptot = 0;

              fout << id << "        ";
   
                 ex(extotal);

              fin >> m;
            if (m > 60)
              m = 60;

                  ass(asstotal);
          temptot = extotal + m + asstotal;
          fout << fixed << setprecision(0) << temptot << "        ";
          fout << fixed << setprecision(1) << (temptot / 500) * 100 << "         ";

     lettergrade(temptot);
         
        }
    }   

/*****************************************************************
******************************************************************/

int main()
   {
         fin.open("class_scores.txt");
         fout.open("final_grades.txt");

      header();
      loop();

    return 0;
   }
