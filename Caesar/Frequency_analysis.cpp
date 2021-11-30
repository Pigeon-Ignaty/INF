#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <cstring> 
#include <ctype.h>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int encryption();

int decryption() {
    return 0;
};
void Caesar() {
    string text;
    string textn;
    string textbi;

    ifstream in;
    in.open("txt.txt");
    if (in.is_open()) {
        while (getline(in, text)) {
            textn = textn + text;
        }
    }
    char* message = new char[textn.length()];
    in.close();
    for (int i = 0; i < textn.length(); i++) {
        message[i] = textn[i];
    }

    cout << "Enter key (1-25)" << endl;
    int key;
    cin >> key;

    char* enc_message = new char[strlen(message)];

    char s_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char b_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char n_letters[] = "0123456789,.:;!')(-+=*&^%$";


    int buffer1, buffer2, buffer3;
    for (int i = 0; i < strlen(message); i++) {
        if ('a' <= message[i] && message[i] <= 'z') {

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

        
        else {
            enc_message[i] = message[i];

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

}
void monograms(string enc_message_str, string new_al, string alphabet_pop_of_let) {

    int size = enc_message_str.length();
    vector<string> dec_message_str;
    dec_message_str.resize(size);
    string buff;
    string buff2;
    vector<int> v(enc_message_str.begin(), enc_message_str.end());
    for (int i = 0; i < size; i++) {
        dec_message_str[i] = enc_message_str[i];
        //cout << dec_message_str[i];
        for (int j = 0; j < 27; j++) {
            if (enc_message_str[i] == new_al[j]) {
                dec_message_str[i] = alphabet_pop_of_let[j];
                
            }

        }
    }
    cout << "Текст после монограм: ";
    for(int i =0;i<size;i++){
        cout << dec_message_str[i];
    }
    fstream ofs("monograms.txt");
    for(int i =0;i<size;i++){
    ofs << dec_message_str[i];
    }
  
}
void bigrams(string enc_message_str) {
    ifstream in("txt.txt");
    vector <char> m;
    char s;
    while (in.get(s)) {
        m.push_back(s);
     }
    in.close();
    vector <string> monograms_orig;
    vector <int> num_big_orig;
    cout << endl << endl << endl;
    
    char buff, buff1;
     for (int i = 0; i < m.size()-1; i++) {//находим монограмы исходного текста
        if (m[i] != ' ' && m[i] != '0-9' && m[i] != '.' && m[i] != ',' && m[i+1] != ' ' && m[i + 1] != '0-9' && m[i + 1] != '.' && m[i + 1] != ',') {
            buff = m[i];
            buff1 = m[i + 1];
            string buff2;
            buff2 += buff;
            buff2 += buff1;
            monograms_orig.insert(monograms_orig.end(), { buff2 });//push_back(buff,buff1);
           // big.push_back(buff1);
        }
        
    }
     cout << "Оригинальные биграммы текста ";
     for (int i = 0; i < monograms_orig.size(); i++) {
         cout << monograms_orig[i] << " ";
     }
  
     //vector <string> NumKOLLMonog;
     
     vector <double> num;
     for (int i = 0; i < monograms_orig.size(); i++) {
         num.push_back(1);
     }
     sort(monograms_orig.begin(), monograms_orig.end());
     string str = "0";
     cout << endl << endl;
     cout << "сортировка биграммы текста " << endl;
     for (int i = 0; i < monograms_orig.size(); i++) {
         cout << monograms_orig[i] << " ";
     }
     cout << endl << endl;
     bool flag =0;
     for (int i = 0; i < monograms_orig.size(); i++) { //считаем колличество всех монограм оригинального текста
         if (str != monograms_orig[i]) {
             str = monograms_orig[i];
             num[i] = 1;
             flag = 0;
        }
         else if (flag == 0 && str == monograms_orig[i]) {
             num[i] = num[i]+ num[i-1];
             num[i - 1] = 0;
         }
         else if (flag == 1 && str == monograms_orig[i]) {
             num.push_back(1);
             //num[i] = num[i] + 1;
             flag = 0;
         }
         
     }
     
     for (int i = 1; i < num.size(); ++i) {
         for (int j = 0; j < num.size() - 1; j++) {
             if (num[j] < num[j + 1]) {
                     int temp = num[j];
                     num[j]= num[j+1];
                     num[j + 1] = temp;
                     string temp_string = monograms_orig[j];
                     monograms_orig[j] = monograms_orig[j+1];
                     monograms_orig[j+1] = temp_string;

             }
         }
     }
     
     for (int i = 0; i < monograms_orig.size(); i++) {
         cout << num[i] << " " << monograms_orig[i] << " " << i << endl;
     }
     vector <int> intmonogram = {0,0,0,0,0,0,0,0,0,0}; // топ 10 монограм оригинального текста
     vector <string> monogram = { "0","0","0","0","0","0","0","0","0","0"};
     for (int i = 0; i < 10; i++) {
         intmonogram[i] = num[i];
         monogram[i] = monograms_orig[i];

     }
     cout << endl << endl;
     for (int i = 0; i < monogram.size(); i++) {
         cout << intmonogram[i] << " " << monogram[i] << " " << i << endl;
     }
     



     cout << endl;
     //берём монограмму, если она уже есть в другом массиве, увеличиваем количество, если нет записываем его
     ///////////////////////////////
     ifstream in1("crypted.txt");
     vector <char> n;
     char s1;
     while(in1.get(s1)) {
         n.push_back(s1);
     }
     in1.close();
     vector <string> monograms_crypt;
     vector <int> num_big_crypt;
     char buff3, buff4;
     for (int i = 0; i < n.size() - 1; i++) {//находим монограмы шифрованного текста
         if (n[i] != ' ' && n[i] != '0-9' && n[i] != '.' && n[i] != ',' && n[i + 1] != ' ' && n[i + 1] != '0-9' && n[i + 1] != '.' && n[i + 1] != ',') {
             buff3 = n[i];
             buff4 = n[i + 1];
             string buff5;
             buff5 += buff3;
             buff5 += buff4;
             monograms_crypt.insert(monograms_crypt.end(), { buff5 });//push_back(buff,buff1);

         }

     }
     cout << "Шифрованные биграммы текста ";
     for (int i = 0; i < monograms_crypt.size(); i++) {
         cout << monograms_crypt[i] << " ";
     }
     
}

int main()
{
    setlocale(LC_ALL, "RU");
    ///////////////////////////////////////////////////// Шифр Цезаря
    Caesar();

    ifstream in;
    string enc_message_str,buff1;
    in.open("crypted.txt");
    if (in.is_open()) {
        while (getline(in, buff1)) {
            enc_message_str = enc_message_str + buff1;
        }
    }
    //char* enc_message_str = new char[buff.length()];
    in.close();
   
    
    //for (int i = 0; i < strlen(enc_message_str); i++) {
    //    enc_message_str[i] = buff[i];
     //   cout << enc_message_str[i];

    //}
    //out.close();
    
    ////////////////////////////////////////////////////////////////////////
    
    int number_of_letters = 0;
    int the_number_of_all_letters = 0;
    float frequency_let[27] = { 0 }; // frequency_al[i] = number_of_letters
    float frequency[27] = {0};
    float arr[27] = { 8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074 };
    string B_al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string S_al = "abcdefghijklmnopqrstuvwxyz";
    string alphabet_pop_of_let = "etaoinshrdlcumwfgypbvkxjq";
    string new_al = "abcdefghijklmnopqrstuvwxyz";
    

   // for (int i = 0; i < enc_message_str.length()-100; i++) {
   //     dec_message_str[i] = enc_message_str[i];
   // }

    for (int i = 0; i < enc_message_str.length(); i++) {//подсчёт всех букв.
        if (enc_message_str[i] != ' ' && enc_message_str[i] != '0-9' && enc_message_str[i] != '.' && enc_message_str[i] != ',' && enc_message_str[i] != ':' && enc_message_str[i] != '!' && enc_message_str[i] != '?' && enc_message_str[i] != '-')
            the_number_of_all_letters++;
      
    }
    //подсчёт появления каждой буквы
    for (int i = 0; i < enc_message_str.length(); i++) {
        for (int j = 0; j < S_al.length(); j++) {
            if (enc_message_str[i] == B_al[j] || enc_message_str[i] == S_al[j]) {
                frequency_let[j]++;
            }

        }
    }

    //вычисление частоты появления каждой буквы в тексте
    for (int i = 0; i < 27; i++) {
        frequency[i] = frequency_let[i] / the_number_of_all_letters;
    }
    for (int i = 0; i < S_al.length(); i++) {
        cout << S_al[i] << " = " << frequency[i] << " = " << frequency_let[i] << "  / " << the_number_of_all_letters << endl;
   }
    cout << endl << endl;
    for (int i = 26; i >=1; --i) {//сортировка по уменьшению частоты появления букв в зашированном тексте
        for (int j = 0; j < i; ++j) {
            if (frequency[j] < frequency[j + 1]) {
                float buff = frequency[j];
                char buff1 = new_al[j];
                frequency[j] = frequency[j + 1];
                new_al[j] = new_al[j + 1];
                frequency[j + 1] = buff;
                new_al[j + 1] = buff1;
            }
        }
    }
  
    monograms(enc_message_str, new_al, alphabet_pop_of_let);
    bigrams(enc_message_str);
    ////////////////////////замена 
    char a = 'a';
    char b = 'b';
    char c = 'c';
    string s;
    s += a;
    s += b;
    s += c;
    //cout << s <<  endl;
    
    return 0;
}

