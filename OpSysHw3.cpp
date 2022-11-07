#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
 
int main()
{
std::ifstream readfile("file.txt");//reading numbers from text file
std::string eachline;
//initializing array to hold the count of each limits
int range[10] = {0,0,0,0,0,0,0,0,0,0};
//reading numbers from file
cout<<"Numbers read from file are: ";
while (std::getline(readfile, eachline))
{
std::istringstream iss(eachline);
int n;
 
while (iss >> n)//reading each value from file
{
//displaying number read from file
cout<<n<<" ";
//checking number to match with respective range.. and incrementing count
if(n>=0 && n<=9){
range[0]++;
}
else if(n>=10 && n<=19){
range[1]++;
}
else if(n>=20 && n<=29){
range[2]++;
}
else if(n>=30 && n<=39){
range[3]++;
}
else if(n>=40 && n<=49){
range[4]++;
}
else if(n>=50 && n<=59){
range[5]++;
}
else if(n>=60 && n<=69){
range[6]++;
}
else if(n>=70 && n<=79){
range[7]++;
}
else if(n>=80 && n<=89){
range[8]++;
}
else if(n>=90 && n<=99){
range[9]++;
}
 
}
}
 
//finally displaying results
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
 
return 0;
}
