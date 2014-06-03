//============================================================================
// Name        : main.cpp
// Author      : Silen
// Version     : 1.0
// Copyright   :
// Description : Projekt na zajęcia
//============================================================================

#include <iostream>

using namespace std;

class Amunition{
public:
 virtual Amunition * cloneBullet()const = 0;				//tworzenie obiektow
 virtual int ammoDamage()=0;
 virtual ~Amunition(){}
};

class FagmentationBullet : public Amunition{
public:
 FagmentationBullet * cloneBullet() const {
   return new FagmentationBullet( *this );
  }
 int ammoDamage(){
   return 25;
  }
};

class SmokeBullet : public Amunition{
public:
 SmokeBullet * cloneBullet() const {
   return new SmokeBullet( *this );
  }
 int ammoDamage(){
   return 10;
  }
};

class IncendiaryBullet : public Amunition{
public:
 IncendiaryBullet * cloneBullet() const {
   return new IncendiaryBullet( *this );
  }
 int ammoDamage(){
   return 1;
  }
};
class Magazine{
private:

public:
 Amunition *bulletPointer[25];
 Magazine (){								//konstruktor do zapelnienia NULL
  for (int i=0;i<25;i++){
    bulletPointer[i] = NULL;
   }
  }
 Magazine(Magazine & originalBullet){		//konstruktor kopiujacy
  for (int i=0;i<25;i++){
    bulletPointer[i] = originalBullet.bulletPointer[i]->cloneBullet();
  }
      }

 Magazine& operator=(Magazine &originalBullet){   //operator przypisania
   if (this==&originalBullet){						//czesc warunkowa
     return *this;
    }

   for (int i=0;i<25;i++){							//czesc odsmiecania
     delete bulletPointer[i];
    }
   for (int i=0;i<25;i++){							//czesc przypisania
     if (originalBullet.bulletPointer[indexOfBullet]!=NULL) {
       bulletPointer[indexOfBullet] = originalBullet.bulletPointer[indexOfBullet]->cloneBullet();
     }
     else{
       bulletPointer[indexOfBullet] = NULL;
     }
    }
   return *this;
   }


 int choice;
void chooseBullet(){
		cout<<"Specify which bullet you want to use";
		cin>>choice;
 }
int indexOfBullet;
 void loadBullet(){
	 chooseBullet();
	 if(choice==0){
	  bulletPointer=FagmentationBullet;
	  bulletPointer[indexOfBullet]=bulletPointer[indexOfBullet]->cloneBullet();
	  indexOfBullet++;
	             }
	 else if(choice==1){
	  bulletPointer=&SmokeBullet;
	  bulletPointer[indexOfBullet]=bulletPointer[indexOfBullet]->cloneBullet();
	  indexOfBullet++;
	 			 }
	 else if(choice==2){
	  bulletPointer=&IncendiaryBullet;
	  bulletPointer[indexOfBullet]=bulletPointer[indexOfBullet]->cloneBullet();
	  indexOfBullet++;
	 			 }
    }

 virtual ~Magazine() {								//destruktor virtualny
  for (int i=0;i<25;i++){
    delete bulletPointer[i];
    bulletPointer[i]=NULL;
   }
  }
 };

class Rifle{
private:

public:





};

int main(){


	return 0;
}
