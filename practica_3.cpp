#include <iostream>
#include <string>
using namespace std;

/***************************************************************************************************
                        PRACTICA 3 - SANTIAGO RAMIREZ OROZCO - 23310173                                                 
                                    SMART POINTERS
    Son punteros inteligentes que liberan la memoria utilizada de una instancia de manera
    automatica cuando esta ya no es utilizada. Esto evita fugas de memoria al momento de 
    utilizar instancias que esten llamadas  varias veces o que hacen returns de manera seguida.
    El ejemplo que usare sera manteniendo mi idea de la practica 1 con los jugadores de soccer.
    Por cuestiones de comodidad y facilidad para mi realizare mi codigo en ingles. 

***************************************************************************************************/

//Creation of the Player class
class Soccer_Player {
    private:
        string name;
        int age;

    public:
        //Constructor
        Soccer_Player(string n, int a) : name(n), age(a){}

        //Display
        void show(){
            cout << "Name: " << name << " Age: " << age << endl;

        }

};

//Smart Pointer definition
class SmartPointer{

    private:
        //Creating a pointer to Soccer Player
        Soccer_Player *ptr;


    public:
        //Initialize the smart pointer 
        SmartPointer(Soccer_Player *p) : ptr(p){
            cout << "The player entered the match" << endl;
        };

        //Destructor asigned to free the memory
        ~SmartPointer(){
            delete ptr; //Free the memory
            cout << "The player is out of the game." << endl;
        }

        // Dereference operator overloading [1]
        Soccer_Player &operator*() const{
            return *ptr;
        }

        // Acces member operator overload
        Soccer_Player *operator->() const {
            return ptr;
        }

        // Others operators overloads
    SmartPointer& operator=(const SmartPointer& other) {
        if (this != &other) { // Evitar la auto-asignación
            delete ptr; // Liberar la memoria del objeto anterior
            ptr = new Soccer_Player(*other.ptr); // Crear un nuevo objeto Soccer_Player
        }
        return *this;
    }




};

/*************************************************************************************
    [1] La sobrecarga del operador de desreferencia a lo que entendi lo que hace
    es que cuando nosotros usemos el simbolo * en el main este no lo tome como
    un puntero crudo, sino que lo mande a ejecutar nuestro codigo del smart pointer
    y lo mismo pasa con la sobrecarga de; operador de acceso a miembros.
**************************************************************************************/

int main (void){

    //Object creation of the SmartPointer and assign a player to it.
    SmartPointer player1(new Soccer_Player("Cristiano Ronaldo", 39));

    //Creation of anoter Smart Pointer copying the first one
    SmartPointer player2 = player1;

    //Visualize the show function
    player1-> show();
    player2-> show();

    return 0;
}
