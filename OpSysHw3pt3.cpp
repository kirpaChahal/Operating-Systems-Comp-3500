#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <mutex>
using namespace std;
 std::mutex mtx;

const int SIZE = 100;
int arrHundo[SIZE];
const int SIZETEN = 10;
int range[10] = {0,0,0,0,0,0,0,0,0,0};
 
void readData() { //reads data from file and puts it into array of 100
  string inFileName = "file.txt";
  ifstream inFile;
  inFile.open(inFileName.c_str());
  if (inFile.is_open())
  {
      for (int i = 0; i < SIZE; i++)
      {
          inFile >> arrHundo[i];
          cout << arrHundo[i] << " ";
      }
      inFile.close(); // CLose input file
  }
  else { //Error message
      cerr << "Can't find input file " << inFileName << endl;
  }
}
 
void *myThreadFun(void *vargp) {
              readData();
              mtx.lock();
  int arrOne[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrOne[a]=arrHundo[a];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrOne[i];

       if(arrOne[i]>=0 && arrOne[i]<=9){
    range[0]++;
}
else if(arrOne[i]>=10 && arrOne[i]<=19){
    range[1]++;
}
else if(arrOne[i]>=20 && arrOne[i]<=29){
    range[2]++;
}
else if(arrOne[i]>=30 && arrOne[i]<=39){
    range[3]++;
}
else if(arrOne[i]>=40 && arrOne[i]<=49){
    range[4]++;
}
else if(arrOne[i]>=50 && arrOne[i]<=59){
    range[5]++;
}
else if(arrOne[i]>=60 && arrOne[i]<=69){
    range[6]++;
}
else if(arrOne[i] && arrOne[i]<=79){
    range[7]++;
}
else if(arrOne[i]>=80 && arrOne[i]<=89){
    range[8]++;
}
else if(arrOne[i]>=90 && arrOne[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

mtx.unlock();

    return NULL;
}


void *myThreadFun2(void *vargp) {
   readData();
     mtx.lock();

  int arrTwo[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrTwo[a]=arrHundo[a+10];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrTwo[i];

       if(arrTwo[i]>=0 && arrTwo[i]<=9){
    range[0]++;
}
else if(arrTwo[i]>=10 && arrTwo[i]<=19){
    range[1]++;
}
else if(arrTwo[i]>=20 && arrTwo[i]<=29){
    range[2]++;
}
else if(arrTwo[i]>=30 && arrTwo[i]<=39){
    range[3]++;
}
else if(arrTwo[i]>=40 && arrTwo[i]<=49){
    range[4]++;
}
else if(arrTwo[i]>=50 && arrTwo[i]<=59){
    range[5]++;
}
else if(arrTwo[i]>=60 && arrTwo[i]<=69){
    range[6]++;
}
else if(arrTwo[i] && arrTwo[i]<=79){
    range[7]++;
}
else if(arrTwo[i]>=80 && arrTwo[i]<=89){
    range[8]++;
}
else if(arrTwo[i]>=90 && arrTwo[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

mtx.unlock();

    return NULL;
}



/////
void *myThreadFun3(void *vargp)
{
               mtx.lock();
               readData();
  int arrThree[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrThree[a]=arrHundo[a+20];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrThree[i];

       if(arrThree[i]>=0 && arrThree[i]<=9){
    range[0]++;
}
else if(arrThree[i]>=10 && arrThree[i]<=19){
    range[1]++;
}
else if(arrThree[i]>=20 && arrThree[i]<=29){
    range[2]++;
}
else if(arrThree[i]>=30 && arrThree[i]<=39){
    range[3]++;
}
else if(arrThree[i]>=40 && arrThree[i]<=49){
    range[4]++;
}
else if(arrThree[i]>=50 && arrThree[i]<=59){
    range[5]++;
}
else if(arrThree[i]>=60 && arrThree[i]<=69){
    range[6]++;
}
else if(arrThree[i] && arrThree[i]<=79){
    range[7]++;
}
else if(arrThree[i]>=80 && arrThree[i]<=89){
    range[8]++;
}
else if(arrThree[i]>=90 && arrThree[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

    mtx.unlock();

    return NULL;
}


///
void *myThreadFun4(void *vargp)
{
              readData();
              mtx.lock();
  int arrFour[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrFour[a]=arrHundo[a+30];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrFour[i];

       if(arrFour[i]>=0 && arrFour[i]<=9){
    range[0]++;
}
else if(arrFour[i]>=10 && arrFour[i]<=19){
    range[1]++;
}
else if(arrFour[i]>=20 && arrFour[i]<=29){
    range[2]++;
}
else if(arrFour[i]>=30 && arrFour[i]<=39){
    range[3]++;
}
else if(arrFour[i]>=40 && arrFour[i]<=49){
    range[4]++;
}
else if(arrFour[i]>=50 && arrFour[i]<=59){
    range[5]++;
}
else if(arrFour[i]>=60 && arrFour[i]<=69){
    range[6]++;
}
else if(arrFour[i] && arrFour[i]<=79){
    range[7]++;
}
else if(arrFour[i]>=80 && arrFour[i]<=89){
    range[8]++;
}
else if(arrFour[i]>=90 && arrFour[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

    mtx.unlock();
    return NULL;

}


void *myThreadFun5(void *vargp)
{
          mtx.lock();

              readData();
  int arrFive[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrFive[a]=arrHundo[a+40];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrFive[i];

       if(arrFive[i]>=0 && arrFive[i]<=9){
    range[0]++;
}
else if(arrFive[i]>=10 && arrFive[i]<=19){
    range[1]++;
}
else if(arrFive[i]>=20 && arrFive[i]<=29){
    range[2]++;
}
else if(arrFive[i]>=30 && arrFive[i]<=39){
    range[3]++;
}
else if(arrFive[i]>=40 && arrFive[i]<=49){
    range[4]++;
}
else if(arrFive[i]>=50 && arrFive[i]<=59){
    range[5]++;
}
else if(arrFive[i]>=60 && arrFive[i]<=69){
    range[6]++;
}
else if(arrFive[i] && arrFive[i]<=79){
    range[7]++;
}
else if(arrFive[i]>=80 && arrFive[i]<=89){
    range[8]++;
}
else if(arrFive[i]>=90 && arrFive[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

    return NULL;
}


///
void *myThreadFun6(void *vargp)
{
           readData();
  int arrSix[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrSix[a]=arrHundo[a+50];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrSix[i];

       if(arrSix[i]>=0 && arrSix[i]<=9){
    range[0]++;
}
else if(arrSix[i]>=10 && arrSix[i]<=19){
    range[1]++;
}
else if(arrSix[i]>=20 && arrSix[i]<=29){
    range[2]++;
}
else if(arrSix[i]>=30 && arrSix[i]<=39){
    range[3]++;
}
else if(arrSix[i]>=40 && arrSix[i]<=49){
    range[4]++;
}
else if(arrSix[i]>=50 && arrSix[i]<=59){
    range[5]++;
}
else if(arrSix[i]>=60 && arrSix[i]<=69){
    range[6]++;
}
else if(arrSix[i] && arrSix[i]<=79){
    range[7]++;
}
else if(arrSix[i]>=80 && arrSix[i]<=89){
    range[8]++;
}
else if(arrSix[i]>=90 && arrSix[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

      mtx.unlock();


    return NULL;
}


///
void *myThreadFun7(void *vargp)
{
          readData();
            mtx.lock();

  int arrSeven[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrSeven[a]=arrHundo[a+60];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrSeven[i];

       if(arrSeven[i]>=0 && arrSeven[i]<=9){
    range[0]++;
}
else if(arrSeven[i]>=10 && arrSeven[i]<=19){
    range[1]++;
}
else if(arrSeven[i]>=20 && arrSeven[i]<=29){
    range[2]++;
}
else if(arrSeven[i]>=30 && arrSeven[i]<=39){
    range[3]++;
}
else if(arrSeven[i]>=40 && arrSeven[i]<=49){
    range[4]++;
}
else if(arrSeven[i]>=50 && arrSeven[i]<=59){
    range[5]++;
}
else if(arrSeven[i]>=60 && arrSeven[i]<=69){
    range[6]++;
}
else if(arrSeven[i] && arrSeven[i]<=79){
    range[7]++;
}
else if(arrSeven[i]>=80 && arrSeven[i]<=89){
    range[8]++;
}
else if(arrSeven[i]>=90 && arrSeven[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

      mtx.unlock();

    return NULL;
}


///
void *myThreadFun8(void *vargp)
{
          mtx.lock();

          readData();
  int arrEight[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrEight[a]=arrHundo[a+70];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrEight[i];

       if(arrEight[i]>=0 && arrEight[i]<=9){
    range[0]++;
}
else if(arrEight[i]>=10 && arrEight[i]<=19){
    range[1]++;
}
else if(arrEight[i]>=20 && arrEight[i]<=29){
    range[2]++;
}
else if(arrEight[i]>=30 && arrEight[i]<=39){
    range[3]++;
}
else if(arrEight[i]>=40 && arrEight[i]<=49){
    range[4]++;
}
else if(arrEight[i]>=50 && arrEight[i]<=59){
    range[5]++;
}
else if(arrEight[i]>=60 && arrEight[i]<=69){
    range[6]++;
}
else if(arrEight[i] && arrEight[i]<=79){
    range[7]++;
}
else if(arrEight[i]>=80 && arrEight[i]<=89){
    range[8]++;
}
else if(arrEight[i]>=90 && arrEight[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

      mtx.unlock();


    return NULL;
}


void *myThreadFun9(void *vargp)
{

      mtx.lock();

         readData();
  int arrNine[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrNine[a]=arrHundo[a+80];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrNine[i];

       if(arrNine[i]>=0 && arrNine[i]<=9){
    range[0]++;
}
else if(arrNine[i]>=10 && arrNine[i]<=19){
    range[1]++;
}
else if(arrNine[i]>=20 && arrNine[i]<=29){
    range[2]++;
}
else if(arrNine[i]>=30 && arrNine[i]<=39){
    range[3]++;
}
else if(arrNine[i]>=40 && arrNine[i]<=49){
    range[4]++;
}
else if(arrNine[i]>=50 && arrNine[i]<=59){
    range[5]++;
}
else if(arrNine[i]>=60 && arrNine[i]<=69){
    range[6]++;
}
else if(arrNine[i] && arrNine[i]<=79){
    range[7]++;
}
else if(arrNine[i]>=80 && arrNine[i]<=89){
    range[8]++;
}
else if(arrNine[i]>=90 && arrNine[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

      mtx.unlock();

    return NULL;
}

void *myThreadFun10(void *vargp)
{
      readData();
        mtx.lock();

  int arrTen[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrTen[a]=arrHundo[a+90];
  }
   for (int i=0; i<10; i++) {
       std::cout << arrTen[i];

       if(arrTen[i]>=0 && arrTen[i]<=9){
    range[0]++;
}
else if(arrTen[i]>=10 && arrTen[i]<=19){
    range[1]++;
}
else if(arrTen[i]>=20 && arrTen[i]<=29){
    range[2]++;
}
else if(arrTen[i]>=30 && arrTen[i]<=39){
    range[3]++;
}
else if(arrTen[i]>=40 && arrTen[i]<=49){
    range[4]++;
}
else if(arrTen[i]>=50 && arrTen[i]<=59){
    range[5]++;
}
else if(arrTen[i]>=60 && arrTen[i]<=69){
    range[6]++;
}
else if(arrTen[i] && arrTen[i]<=79){
    range[7]++;
}
else if(arrTen[i]>=80 && arrTen[i]<=89){
    range[8]++;
}
else if(arrTen[i]>=90 && arrTen[i]<=99){
    range[9]++;
}
   }
       ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();

      mtx.unlock();
    return NULL;
}
 
 
 
int main() {
  
 
  int arrThree[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrThree[a]=arrHundo[a+20];
  }
  int arrFour[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrFour[a]=arrHundo[a+30];
  }
  int arrFive[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrFive[a]=arrHundo[a+40];
  }
  int arrSix[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrSix[a]=arrHundo[a+50];
  }
  int arrSeven[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrSeven[a]=arrHundo[a+60];
  }
  int arrEight[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrEight[a]=arrHundo[a+70];
  }
  int arrNine[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrNine[a]=arrHundo[a+80];
  }
  int arrTen[SIZETEN];
  for (int a = 0; a < SIZETEN; a++)
  {
      arrTen[a]=arrHundo[a+90];
  }
 
   pthread_t thread_id;
  pthread_t thread_id2;
  pthread_t thread_id3;
  pthread_t thread_id4;
  pthread_t thread_id5;
  pthread_t thread_id6;
  pthread_t thread_id7;
  pthread_t thread_id8;
  pthread_t thread_id9;
  pthread_t thread_id10;
   printf("Before Thread\n");
   pthread_create(&thread_id, NULL, myThreadFun, NULL);
   pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
   pthread_create(&thread_id3, NULL, myThreadFun3, NULL);
   pthread_create(&thread_id4, NULL, myThreadFun4, NULL);
   pthread_create(&thread_id5, NULL, myThreadFun5, NULL);
   pthread_create(&thread_id6, NULL, myThreadFun6, NULL);
   pthread_create(&thread_id7, NULL, myThreadFun7, NULL);
   pthread_create(&thread_id8, NULL, myThreadFun8, NULL);
   pthread_create(&thread_id9, NULL, myThreadFun9, NULL);
   pthread_create(&thread_id10, NULL, myThreadFun10, NULL);
   pthread_join(thread_id, NULL);
   pthread_join(thread_id2, NULL);
   pthread_join(thread_id3, NULL);
   pthread_join(thread_id4, NULL);
   pthread_join(thread_id5, NULL);
   pthread_join(thread_id6, NULL);
   pthread_join(thread_id7, NULL);
   pthread_join(thread_id8, NULL);
   pthread_join(thread_id9, NULL);
   pthread_join(thread_id10, NULL);
   printf("After Thread\n");
   exit(0);
   return 0;
   ofstream myfile;
myfile.open ("output.txt");
int temp = 0;
int grpNum = 1;
for(int i=0;i<10;i++){
myfile <<"\nGroup "<<grpNum<<" ("<<temp<<" - "<<(temp+9)<<") Count: "<<range[i];
//incrementing to update range limit in console
temp = temp+10;
grpNum++;
}
myfile.close();
   }





