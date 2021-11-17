#include <iostream>
#include<math.h>
#include <windows.h>

using namespace std;

class Сommunication_A {
    int a, A, K;
    
public:
    int B;
    const int p = 1023; //Алиса и Боб договорились о p и g заранее
    const int g = 614;
    void Get_a();
    void Calculate_A();
    int send_A();
    void Calculate_K();
    int ShowK();
};

class Сommunication_B {
    int b, B, K;

public:
    int A;
    const int p = 1023; 
    const int g = 614;
    void Get_b();
    void Calculate_B();
    int send_B();
    void Calculate_K();
    int ShowK();
};

class Interceptor{
    public:
        int a = 0;
        int b = 0;
        int p = 0;
        int g = 0;
        int A = 0;
        int B = 0;
};

void Сommunication_A::Get_a() {
    
    srand(time(NULL));

    a = 5 + rand() % 105;
    
    
   
}
void Сommunication_A::Calculate_A() {
    A = (g ^ a) % p;
}
int Сommunication_A::send_A() {
    return A;
}
void Сommunication_A::Calculate_K() {
    K = (B ^ a) % p;
}
int Сommunication_A::ShowK() {
    return K;
}
void Сommunication_B::Get_b() {
    
    srand(time(NULL));

    b = 10 + rand() % 110;
    
   
}
void Сommunication_B::Calculate_B() {
    B = (g ^ b) % p;
}
int Сommunication_B::send_B() {
    return B;
}
void Сommunication_B::Calculate_K() {
    K = (A ^ b) % p;
}
int Сommunication_B::ShowK() {
    return K;
}

int main()
{
    setlocale(LC_ALL, "RU");
    Сommunication_A Alice;
    Сommunication_B Bob;
    Interceptor Eva;
    if (Alice.p == Bob.p && Alice.g == Bob.g) {
        Eva.p = Bob.p;
        Eva.g = Bob.g;
        cout << "Ева знает p = " << Eva.p << " Ева знает g = " << Eva.g << endl;
        // Eva.g = 100 Ева не может изменить p и g
        Alice.Get_a();//Алиса генерирует a
        Bob.Get_b(); //Боб число генерирует b, Ева не может прочитать и изменить
        Alice.Calculate_A(); //Алиса вычисляет А
        Bob.A = Alice.send_A(); //Алиса отправляет бобу А
        Eva.A = Alice.send_A(); // Ева знает А, но не знает как оно получено, не знает a

        Bob.Calculate_B();
        Alice.B = Bob.send_B();
        Eva.B = Bob.send_B();// Ева знает B
        // Алиса и Боб начинают вычислять K
        Alice.Calculate_K();
        Bob.Calculate_K();
        cout << "A = " << Eva.A << endl;
        cout << "B = " << Eva.B << endl;
        cout << "a = " << Eva.a << endl;
        cout << "b = " << Eva.b << endl;
        cout << "p = " << Eva.p << endl;
        cout << "g = " << Eva.g << endl;
       // Eva.K Ева никак не получит доступ к значению K Алисы и Боба.
        cout << Alice.ShowK() << " = " << Bob.ShowK();
    }
    
    if (int i = 0) {
        cout << "1";
    }

    return 0;
}