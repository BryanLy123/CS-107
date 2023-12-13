//This code identifies specific characteristics of the presidential votes in a particular election year
//Authors: Bryan Ly and Marisol Arroyo
//CS107 Spring 2021
//April 30, 2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

const int NUM_STATES = 50; //constant integer for total number of states in the U.S.

typedef struct Presidential_struct {
   int electYear;
   char state;
   int votes;
   int democratic;
   int republican;
   struct Presidential_struct* next;
   
}Presidential;


void LocCreate(Presidential* thisLoc, char thisState[], int thisVote, int thisDem, int thisRep, Presidential* nextLoc) {
    thisLoc->state = *thisState;
    thisLoc->votes = thisVote;
    thisLoc->democratic = thisDem;
    thisLoc->republican = thisRep;
    thisLoc->next = nextLoc;
    
    return;
}

void LocAdd(Presidential* headLoc, char newState[], int newVote, int newDem, int newRep){ //defines the function to add a new datapoint in the list
   
   Presidential* newLoc = (Presidential*)malloc(sizeof(Presidential));
   LocCreate(newLoc, newState, newVote, newDem, newRep, NULL);
   
   Presidential* currLoc = headLoc;
   while((currLoc->next) != NULL){
      currLoc = currLoc->next;
   }
   
   currLoc->next = newLoc; 
   
   return;
}

int findMaxVotes(Presidential* headLoc){//identifies the function to find the highest number of total votes
   int maxVotes = 0;
   
   Presidential* currLoc = headLoc;
   while(currLoc != NULL){
      if((currLoc->votes) >  maxVotes){
         maxVotes = (currLoc->votes);
      }
      currLoc = (currLoc->next);
   }

   return maxVotes;//returns highest number of total votes
}

int findMaxDem(Presidential* headLoc){//identifies the function to find the highest number of democratic votes
   int maxDem = 0;
   
   Presidential* currLoc = headLoc;
   while(currLoc != NULL){
      if((currLoc->democratic) >  maxDem){
         maxDem = (currLoc->democratic);
      }
      currLoc = (currLoc->next);
   }

   return maxDem;//returns highest number of democratic votes
}

int findMaxRep(Presidential* headLoc){ //identifies the function to find the highest number of republican votes
   int maxRep = 0;
   
   Presidential* currLoc = headLoc;
   while(currLoc != NULL){
      if((currLoc->republican) >  maxRep){
         maxRep = (currLoc->republican);
      }
      currLoc = (currLoc->next);
   }

   return maxRep;//returns highest number of republican votes
}

void SortArray(char sortingList[], int numVals){ //defines the selection sort algorithm to sort the list
   int indexSmallest;
   int temp; 
   int j;
   
   for (int i = 0; i < numVals - 1; ++i) { //loops through list of integers

   // Find index of smallest remaining element
   indexSmallest = i; //declares variable for smallest integer
   for (j = i + 1; j < numVals; ++j) { //loops through list to compare integer size

      if (sortingList[j] < sortingList[indexSmallest]) { 
         indexSmallest = j;//declares new integer variable
      }
   }

   // Swap numbers[i] and numbers[indexSmallest]
   temp = sortingList[i];
   sortingList[i] = sortingList[indexSmallest];
   sortingList[indexSmallest] = temp;
   }
}

int main() {
   FILE* inputFile = NULL;
   char fileName[50] = "PresElecData_1976_2020.txt";
   char irrelevant[10];
   int numread;
   int year;
   char abrev[50];
   int total;
   int dem;
   int rep;
   int data;
   
   inputFile = fopen(fileName, "r"); //opens the file to be read in 
   
   fscanf(inputFile, "%s %s %s %s %s", irrelevant, irrelevant, irrelevant, irrelevant, irrelevant);//scans the labels for each data point
   
   if (inputFile == NULL){ //determines if the data in the file is valid
      printf("Could not open file.");
      return -1; //ends the code if the file is not valid
   }
   
   int elect;
   printf("Enter a valid election year.\n"); //prompts user to enter an election year
   scanf("%d", &elect);
   
   printf("\n");
   
   if (elect % 4 != 0){ //identifies when the input year is a valid election year
      printf("Not a valid election year.\n");
      return -1;
   }
   
   Presidential* headLoc = NULL; //declares initial pointer
   headLoc = (Presidential*)malloc(sizeof(Presidential));//declares the size of the pointer
   
   int maxVotes = 0;
   int maxDem = 0;
   int maxRep = 0;
   
   int totalAvg = 0;
   int demAvg = 0;
   int repAvg = 0;
   
   int prevTot = 0;
   int prevDem = 0;
   int prevRep = 0;
   
   while (!feof(inputFile)){ //identifies when the data is not the end of the data
      numread = fscanf(inputFile, "%d %s %d %d %d", &year, abrev, &total, &dem, &rep); //identifies number of data points being read in
      if (numread == 5){
         data++;
         if (elect == year){ 
            //printf("%d %s %d %d %d\n", year, abrev, total, dem, rep);
            if (total > 0){
               LocAdd(headLoc, abrev, total, dem, rep); //adds the datapoints to a linked list
               maxVotes = findMaxVotes(headLoc); //calls the function to find the highest overall vote
            } 
            if (dem > 0){
               LocAdd(headLoc, abrev, total, dem, rep);//adds the datapoints to a linked list
               maxDem = findMaxDem(headLoc); //calls the function to find the highest democratic vote
            }  
            if (rep > 0){
               LocAdd(headLoc, abrev, total, dem, rep);//adds the datapoints to a linked list
               maxRep = findMaxRep(headLoc); //calls the function to find the highest republican vote
            }
            if (total > 0){
               totalAvg += total + prevTot; //sums the total vote counts during an election year  
            }
            if (dem > 0){
               demAvg += dem + prevDem; //sums the democratic vote counts during an election year  
            }
            if (rep > 0){
               repAvg += rep + prevRep; //sums the republican vote counts during an election year  
            }
            if (total > 0 && dem > 0 && rep > 0){ //identifies when the vote counts are valid and sets the current votes to the previous
             prevTot = total; //sets the previous total vote count to current total vote count
             prevDem = dem;//sets the previous democratic vote count to current democratic vote count
             prevRep = rep;//sets the previous republican vote count to current republican vote count
            }

            SortArray(abrev, NUM_STATES);

         }
      }
   }
   
   fclose(inputFile);
   
   printf("Number of Votes Recorded since 1976: %d\n", data); //identifies the total number of data points in the file
   
   printf("\n");
   
   printf("In %d the highest Total vote count was %d total votes\n", elect, maxVotes); //outputs the highest overall vote count 
   printf("In %d the highest Democratic vote count was %d votes\n", elect, maxDem);//outputs the highest democratic vote count 
   printf("In %d the highest Republican vote count was %d votes\n", elect, maxRep);//outputs the highest republican vote count 
   
   printf("\n");

   printf("Average Number of Total Votes in %d: %d Votes\n", elect, totalAvg / NUM_STATES); //outputs the average number of overall votes during an election year
   printf("Average Number of Democratic Votes in %d: %d Votes\n", elect, demAvg / NUM_STATES);//outputs the average number of democratic votes during an election year
   printf("Average Number of Republican Votes in %d: %d Votes\n", elect, prevRep / NUM_STATES);//outputs the average number of republican votes during an election year


   return 0;
}
