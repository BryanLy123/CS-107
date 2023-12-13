//This code outputs the various student populations of Colleges in 2020
//Authors: Bryan Ly and Marisol Arroyo
//CS107 Spring 2021
//February 25, 2021

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int const TOTAL_LEAGUES = 16; //initializes the total number of Colleges

// 2020 TOP COLLEGE ENROLLMENTS
int main(void) {
	char university[16][50] = {"Brown University", "Columbia University", "Cornell University", "Darmouth University", "Harvard University", "Princeton University", "University of Pennsylvania", "Yale University", "Stanford University", "California Institute of Technology", "Massachusetts Institute of Technology", "University of California, Berkley", "University of Michigan, Ann Arbor", "Duke University", "New York University", "University of California, San Diego"};
   int rank[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; //stores the array of college ranks
   int totalStudents[16] = {10257, 31077, 23600, 6572, 31566, 8374, 25860, 13433, 17381, 2233, 11574, 42501, 46716, 16606, 51847, 37887}; //stores the array of total student population
   int underGraduate[16] = {7043, 8216, 15182, 4418, 9950, 5428, 11851, 5964, 7087, 948, 4602, 30853, 30318, 6682, 26733, 30285}; //stores the array of undergraduate student population
   int graduate[16] = {3214, 22861, 8418, 2154, 21616, 2946, 14009, 7469, 10294, 1285, 6972, 11648, 16398, 9924, 25114, 7602}; //stores the array of graduate student population
   int maleStudents[16] = {4888, 14803, 11698, 3385, 15841, 4553, 11673, 6558, 9630, 1427, 6972, 20866, 23632, 8137, 22033, 19806}; //stores the array of male student population
   int femaleStudents[16] = {5369, 16274, 11902, 3187, 15725, 3821, 14187, 6875, 7751, 806, 4602, 21635, 23084, 8469, 29814, 18081}; //stores the array of female student population
   int i = 0; //initializes the count variable of "i"
   int count = 0; //initializes the count variable of "count"
   char choice; //initializes the choice characters
   char target; //initializes target characters
   int above; //initializes the minimum population sizes
   double total = 0.0; //initializes the double format for the total number of students
   double avgStudent; //initializes the double for the average number of students
   
   
   
   // outputs university rank and total population size
   for (i = 0; i < 16; ++i){
      printf("Name: %s, List Rank: %d, Total Population: %d", university[i], rank[i], totalStudents[i]); 
      printf("\n");
   }
   
   printf("\n");
   
   
   //outputs university undergraduate and graduate population size
   for (i = 0; i < 16; ++i){
      printf("Name: %s, Undergraduate Population: %d, Graduate Population: %d", university[i], underGraduate[i], graduate[i]); 
      printf("\n");
   }
   
   printf("\n");
   
   //outputs male and female students population size
   for (i = 0; i < 16; ++i){
      printf("Name: %s, Male Student Population: %d, Female Student Population: %d", university[i], maleStudents[i], femaleStudents[i]); 
      printf("\n");
   }
   
   printf("\n");
  
   
   //identifies when the choice selected is not "quit"
   while (choice != 'q'){ 
      printf("MENU\n"); //identifies the menu options
      printf("a - Average population size\n"); 
      printf("p - Output schools above a population size\n");
      printf("g - Graph of population size\n");
      printf("l - Output list of Ivy Leagues\n");
      printf("q - Quit\n");
      
      printf("\n");

      printf("Choose an option:\n"); //prompts user to input a menu option
      scanf(" %c", &choice);
      
      if (choice != 'a' && choice != 'p' && choice != 'g' && choice != 'l' && choice != 'q'){ //identifies when the selected menu option is not valid
      	printf("Invalid Menu Option\n");
        return 0;
      }
      
      
      
      if (choice == 'a'){ 
         printf("Target Population Types: \n"); //outputs a menu for available population types
         printf("t - Total Population\n");
         printf("f - Female Population\n");
         printf("m - Male Population\n");
         printf("u - Undergraduate Population\n");
         printf("g - Graduate Population\n");
         
         printf("\n");
         
         printf("Enter target population:\n"); //prompts user to enter a target population
         scanf(" %c", &target);
         
         if (target != 't' && target != 'f' && target != 'm' && target != 'u'&& target != 'g'){ //identifies when the user inputs an invalid target
            printf("Invalid Target Population Type, Try Again\n");
            scanf(" %c", &target); //allows user to input new target
         }

         printf("\n");
         
         switch(target){ //initializes the switch program for population sizes
            case 't': //case for average total student population
               for (i = 0; i < 16; ++i){
               		total += totalStudents[i];
               }
               avgStudent = total / TOTAL_LEAGUES;
               printf("Average Total Student Population: %.2lf\n", avgStudent);
               break;
            case 'f': //case for average female student population
               for (i = 0; i < 16; ++i){
               		total += femaleStudents[i];
               }
               avgStudent = total / TOTAL_LEAGUES;
               printf("Average Female Student Population: %.2lf\n", avgStudent);
               break;
            case 'm': //case for average male student population
               for (i = 0; i < 16; ++i){
               		total += maleStudents[i];
               }
               avgStudent = total / TOTAL_LEAGUES;
               printf("Average Male Student Population: %.2lf\n", avgStudent);
               break;
            case 'u': //case for average undergraduate student population
               for (i = 0; i < 16; ++i){
               		total += underGraduate[i];
               }
               avgStudent = total / TOTAL_LEAGUES;
               printf("Average Undergraduate Student Population: %.2lf\n", avgStudent);
               break;
            case 'g': //case for average graduate student population
               for (i = 0; i < 16; ++i){
               		total += graduate[i];
               }
               avgStudent = total / TOTAL_LEAGUES;
               printf("Average Graduate Student Population: %.2lf\n", avgStudent);
               break;  
               
           }   
           printf("\n");
      }
   
   
   		//identifies when the user chooses to find the schools that have a population greater than a minimum
      if (choice == 'p'){ 
         printf("Target Population Types: \n"); //outputs a menu for available population types
         printf("t - Total Population\n");
         printf("f - Female Population\n");
         printf("m - Male Population\n");
         printf("u - Undergraduate Population\n");
         printf("g - Graduate Population\n");
         
         printf("\n");
         
         printf("Enter target population:\n"); //prompts user to enter a target population
         scanf(" %c", &target);
         
         if (target != 't' && target != 'f' && target != 'm' && target != 'u'&& target != 'g'){//identifies when the user inputs an invalid target
            printf("Invalid Target Population Type, Try Again\n");
            scanf(" %c", &target); //allows user to input new target
         }
         
         printf("Enter population size minimum:\n"); //prompts user to enter minimum population size
         scanf(" %d", &above);
         printf("ABOVE %d\n", above); 
         
         printf("\n");
         
         switch(target){ //initializes the switch program for population sizes
            case 't': //case for total student population
               for (i = 0; i < 16; ++i){
                 if (totalStudents[i] > above){
                  printf("Name: %s, Total Population: %d\n", university[i], totalStudents[i]); 
                 }  
               }
               break;
               
            case 'f': //case for female students
               for (i = 0; i < 16; ++i){
                 if (femaleStudents[i] > above){
                  printf("Name: %s, Female Student Population: %d\n", university[i], femaleStudents[i]); 
                 }
               }
               break;
               
            case 'm': //case for male students
               for (i = 0; i < 16; ++i){
                 if (maleStudents[i] > above){
                  printf("Name: %s, Male Student Population: %d\n", university[i], maleStudents[i]); 
                 }
               }
               break;
               
            case 'u': //case for undergraduate students
               for (i = 0; i < 16; ++i){
                 if (underGraduate[i] > above){
                  printf("Name: %s, Undergraduate Population: %d\n", university[i], underGraduate[i]); 
                 }
               }
               break;
               
            case 'g': //case for graduate students
               for (i = 0; i < 16; ++i){
                 if (graduate[i] > above){
                  printf("Name: %s, Graduate Population: %d\n", university[i], graduate[i]); 
                 }
               }
               break;
         }
         printf("\n");
   	}
    
      
      if (choice == 'g'){
         printf("Target Population Types: \n"); //outputs a menu for available population types
         printf("t - Total Population\n");
         printf("f - Female Population\n");
         printf("m - Male Population\n");
         printf("u - Undergraduate Population\n");
         printf("g - Graduate Population\n");
         
         printf("\n");
         
         printf("Enter target population:\n"); //prompts user to enter a target population
         scanf(" %c", &target);
         
         if (target != 't' && target != 'f' && target != 'm' && target != 'u'&& target != 'g'){ //identifies when the user inputs an invalid target
            printf("Invalid Target Population Type, Try Again\n");
            scanf(" %c", &target); //allows user to input new target
         }

         printf("\n");
         
         switch(target){ //initializes the switch program for population sizes
      case 't': //case for average total student population
         printf("NOTE: Each '*' = 5000 Students\n"); //identifies the representation of each *
         printf("\n");
         for ( i = 0; i < 16; ++i){//loops each university name and stores the quotient into count
            printf("%s: ", university[i]);
            count = totalStudents[i] / 5000;
            while (count != 0){ //loops how many * to print
               printf("*");
               --count;
            }
            printf("\n");
         }      
         break;
      case 'f': //case for average female student population
         printf("NOTE: Each '*' = 5000 Students\n"); //identifies the representation of each *
         printf("\n");
         for ( i = 0; i < 16; ++i){//loops each university name and stores the quotient into count
            printf("%s: ", university[i]);
            count = femaleStudents[i] / 5000;
            while (count != 0){//loops how many * to print
               printf("*");
               --count;
            }
            printf("\n");
         }      

         break;
      case 'm': //case for average male student population
         printf("NOTE: Each '*' = 5000 Students\n"); //identifies the representation of each *
         printf("\n");
         for ( i = 0; i < 16; ++i){//loops each university name and stores the quotient into count
            printf("%s: ", university[i]);
            count = maleStudents[i] / 5000;
            while (count != 0){//loops how many * to print
               printf("*");
               --count;
            }
            printf("\n");
         }  
         break;
      case 'u': //case for average undergraduate student population
        printf("NOTE: Each '*' = 5000 Students\n"); //identifies the representation of each *
         printf("\n");
        for ( i = 0; i < 16; ++i){//loops each university name and stores the quotient into count
            printf("%s: ", university[i]);
            count = underGraduate[i] / 5000;
            while (count != 0){//loops how many * to print
               printf("*");
               --count;
            }
            printf("\n");
         }      
         break;
      case 'g': //case for average graduate student population
      	printf("NOTE: Each '*' = 5000 Students\n"); //identifies the representation of each *
         printf("\n");
         for ( i = 0; i < 16; ++i){ //loops each university name and stores the quotient into count
            printf("%s: ", university[i]);
            count = graduate[i] / 5000;
            while (count != 0){//loops how many * to print
               printf("*");
               --count;
            }
            printf("\n");
         }      
         break;  
         
     }   
         
         printf("\n");
      }
      
      
      if (choice == 'l'){ //when user enters 'l' the output is the initial list of college populations
         for (i = 0; i < 16; ++i){
            printf("Name: %s, List Rank: %d", university[i], rank[i]);       
            printf("\n");
         }
         printf("\n");
   }
   
  
    while (choice == 'q'){ //whenever the user enters 'q' the code ends
       return 0; 
    }
  }
   

   return 0;
}