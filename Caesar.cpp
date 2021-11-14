#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <cstring> 
#include <ctype.h>
#include <conio.h>
#include <algorithm>
#include <iomanip>


using namespace std;
int encryption();

string decryption() {
    return " d ";
};

//void decryption();

int main()
{

    char message[1500];
    /* ifstream in("txt.txt");
     while (!in.eof()) {
         in.getline(message, 255);
         in.close();
     }
     */
    cin.getline(message, 255);

    cout << "Text: " << message << endl;

    //cin.getline(message, 200);
    cout << "Enter key (1-25)" << endl;
    int key;
    cin >> key;

    char* enc_message = new char[strlen(message)];

    //  char* message = new char[];
     // cin >> message;
    char s_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char b_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char n_letters[] = "0123456789,.:;!')(-+=*&^%$";
    string str_s_letters = string(s_letters);
    string str_b_letters = string(b_letters);
    string str_n_letters = string(n_letters);

    int buffer1, buffer2, buffer3;
    for (int i = 0; i < strlen(message); i++) {
        if (!isupper(message[i])) {

            for (int k = 0; k < strlen(s_letters); k++) {

                if (message[i] == s_letters[k]) {
                    if (k >= (strlen(s_letters) - key)) {
                        buffer1 = k - (strlen(s_letters) - key); enc_message[i] = s_letters[buffer1];
                    }
                    else {
                        buffer1 = k; enc_message[i] = s_letters[buffer1 + key];
                    }


                }
            }
        }

        if (isupper(message[i])) {
            for (int j = 0; j < strlen(b_letters); j++) {
                if (message[i] == b_letters[j]) {
                    if (j >= (strlen(b_letters) - key)) {
                        buffer2 = j - (strlen(b_letters) - key); enc_message[i] = b_letters[buffer2];
                    }
                    else {
                        buffer2 = j; enc_message[i] = b_letters[buffer2 + key];
                    }


                }
            }
        }
        if (message[i] == ' ') {
            enc_message[i] = ' ';
        }
        else {
            for (int o = 0; o < strlen(n_letters); o++) {
                if (message[i] == n_letters[o]) {
                    if (o >= (strlen(n_letters) - key)) {
                        buffer3 = o - (strlen(n_letters) - key); enc_message[i] = n_letters[buffer3];
                    }
                    else { buffer3 = o; enc_message[i] = n_letters[buffer3 + key]; }


                }
            }

        }

    }


    cout << "Crypted text: ";
    for (int a = 0; a < strlen(message); a++) {
        cout << enc_message[a];
    }
    cout << "\n" << "key:" << key << endl;

    ofstream out;
    out.open("crypted.txt");
    for (int a = 0; a < strlen(message); a++) {
        out << enc_message[a];
    }
    out.close();
    delete[] enc_message;

    decryption(); {
        string enc_message;
        char str_s_letters[] = "zyxwvutsrqponmlkjihgfedcba";
        char str_b_letters[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        char str_n_letters[] = "$%^&*=+-()'!;:.,9876543210";
        int buffer1, buffer2, buffer3;
        ifstream mess;
        mess.open("crypted.txt");
        getline(mess, enc_message, '\0');
        mess.close();
        char* dec_message = new char[enc_message.length()];

        for (int key = 1; key < 26; key++) {//подбор ключа
            for (int i = 0; i < enc_message.length(); i++) { // проход по сообщению
                if (!isupper(enc_message[i])) {
          
                    for (int k = 0; k < strlen(str_s_letters); k++) { //проход по совпадению c маленькими буквами

                        if (enc_message[i] == str_s_letters[k]) {
                            if ((k + key) >= 26) {
                                dec_message[i] = str_s_letters[(k + key) % 26];
                                
                            }
                            else {

                                dec_message[i] = str_s_letters[(k + key)];
                                
                            }


                         


                        }
                      

                    }
                }
                if (isupper(enc_message[i])) { //проход по совпадению c большими буквами
                    for (int j = 0; j < strlen(str_s_letters); j++) {
                
                        if (enc_message[i] == str_b_letters[j]) {
                            if ((j + key) >= 26) {
                                dec_message[i] = str_b_letters[(j + key) % 26];

                            }
                            else {

                                dec_message[i] = str_b_letters[(j + key)];

                            }

                        }



                    }
                }
                if (enc_message[i] == ' ') { // если пробел
                    dec_message[i] = ' ';
                }
                else  {
                    for (int o = 0; o < strlen(str_n_letters); o++) { //проход по совпадению cо знаками и цифрами

                        if (enc_message[i] == str_n_letters[o]) {
                            if ((o + key) >= 26) {
                                dec_message[i] = str_n_letters[(o + key) % 26];

                            }
                            else {

                                dec_message[i] = str_n_letters[(o + key)];

                            }

                        }



                    }
                }

                
            }
           
            cout << "Key: " << key << " " << dec_message << endl;
        }


        delete[] dec_message;
    }

    return 0;
}


