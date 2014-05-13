//============================================================================
// Name        : main.cpp
// Author      : Silen
// Version     : 1.0
// Copyright   :
// Description : Projekt na zajêcia
//============================================================================

#include <iostream>

using namespace std;

class Karabin{

public:
    class Magazynek{

    int wybor=0;
    public:
        class Amunicja{
        public:
            virtual int ammoDmg()=0;
            virtual ~Amunicja(){}
        };

        class Odlamkowe : public Amunicja{

        public:
            int ammoDmg(){
                return 25;
            }
        };

        class Dymne : public Amunicja{
        public:
            int ammoDmg(){
                return 10;
            }
        };

        class Zapalajace : public Amunicja{
        public:
            int ammoDmg(){
                return 1;
            }
        };


  int dodajNaboj(){
    Amunicja *pointAmmo;

    cout<<"Podaj co chcesz wybrac: 1 Odlamkowe 2 Dymne 3 Zapalajace"<<endl;
    cin >> wybor;

        if(wybor==0){
                pointAmmo = new Odlamkowe;
            }
        else if(wybor==1){
                pointAmmo = new Dymne;
            }
        else if (wybor==2){
                pointAmmo = new Zapalajace;
            }
    pointAmmo->ammoDmg();

    int sumaObrazen=0;
    sumaObrazen+=pointAmmo->ammoDmg();



    return (sumaObrazen);
  }
};
Magazynek X;
    int suma;
    void sumaObrazen(){
    	suma+=X.dodajNaboj();
        cout<<"Suma obrazen: "<<suma<<endl;
    }
};

int main()
{
    Karabin A;
    for (int i=0;i<3;++i)
    A.sumaObrazen();
    return 0;
}

