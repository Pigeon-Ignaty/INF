#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <cmath>
#include <numeric> 
#include <string> 

using namespace std;

unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long mod)
{
    unsigned long long x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

unsigned long long modulo(unsigned long long base, unsigned long long exponent, unsigned long long mod)
{
    unsigned long long x = 1;
    unsigned long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

bool MillerRabinTest(unsigned long long p, int k)
{
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2 == 0)
    {
        return 0;
    }
    unsigned long long s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < k; i++)
    {
        unsigned long long a = rand() % (p - 1) + 1, temp = s;
        unsigned long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

//2 147 483 648 4 294 967 295
unsigned long long examination() { //генератор простых чисел
    unsigned long long p = 5;
    bool SimpleNumber = 0;
    
    p = 128 + rand() % (255 - 128);// от 128 до 255
    while (SimpleNumber == 0) {
        p++;
        cout << "Сгенерировано " << p << endl;
        SimpleNumber = MillerRabinTest(p, 100); //проверка на просто число
    }

    return p;
}


unsigned long long Euler(unsigned long long p, unsigned long long q) {
    return ((p - 1) * (q - 1));

}
unsigned long gcd(unsigned long long a, int b) {
    int temp;
    while (b != 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;

    current = i;
    result = 1;

    for (long int j = 0; j < d; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result + 97;
}

long int encrypt(long int i, long int e, long int n)
{
    long int current, result;

    current = i - 97;
    result = 1;

    for (long int j = 0; j < e; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result;
}
int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned int>(time(nullptr)));

    unsigned long long p;
    p = examination();//генерируем 1 байтное число и проверяем Миллером-Рабином
    cout << "Простое число p = " << p << endl;

    unsigned long long q;
    q = examination(); //генерация 2 числа
    cout << "Простое число q = " << q << endl;
    unsigned long long module = p * q; //считаем модуль
    unsigned long long phi_n = Euler(p, q); //Считаем функцию Эйлера от модуля

    int e = examination();//генерируем просто число e
    bool buff1 = gcd(phi_n, e); // И проверяем его на простоту и взаимопростоту с ф-и Эйлера
    while (e >= phi_n && buff1 == 0) {
        e = examination();
        gcd(phi_n, e);
    }
    unsigned long long temp_d = 1; // генерируем просто число d
    unsigned long long d = 0;
    bool y = 0;
    while (y == 0) // Условие, что если выражение (d*e)mod phi_n == 1, то принимаем такое d
    {
        if ((temp_d * e) % phi_n == 1)
        {
            y = 1;
        }
        else {
            temp_d++;
        }
    }
    d = temp_d;
 
    cout << "Эйлер = " << phi_n << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Модуль = " << module << endl;

    cout << "Открытый ключ: " << "(" << e << "," << module << ")" << endl;
    cout << "Закрытый ключ: " << "(" << d << "," << module << ")" << endl;

    string message;
    unsigned long long encryptedText[100];
    unsigned long long decryptedText[100];
    cout << "Введите текст" << endl;
    getline(cin, message);



    cout << "Оригинальное сообщение: "<< endl << message << endl;


    

    for (long int i = 0; i < message.length(); i++) // Шифрованое текста
    {
        encryptedText[i] = encrypt(message[i], e, module);
    }

    cout << "Зашифрованное сообщение: " << endl;

    for (long int i = 0; i < message.length(); i++)
    {
        printf("%c", (char)encryptedText[i]);
    }

    for (long int i = 0; i < message.length(); i++)// Расшифрование текста
    {
        decryptedText[i] = decrypt(encryptedText[i], d, module);
    }

    cout << endl << "Расшифрованное сообщение:" << endl;

    for (long int i = 0; i < message.length(); i++)
    {
        printf("%c", (char)decryptedText[i]);
    }

    return 0;
}
