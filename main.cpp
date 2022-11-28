#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

#define FIELD_MODULE 65521
#define PRIMITIVE_NUMBER 17

//return g ^ n mod P
long long int power(long long int g, long long int n, long long int P)
{
    long long int res = 1;
    for(int i = 0; i < n; i++) res = (res * g) % P;

    return res;
}
 
int main()
{ 
    string alice = "Alice";
    string bob = "Bob";

    srand(time(0));


    long long int alice_private_key;
    long long int alice_public_key;
    long long int bob_private_key;
    long long int bob_public_key;
    long long int bob_session_key;
    long long int alice_session_key;

    cout << "Нажмите: \n1 --- чтобы ввести свой приватные ключи\n2 --- чтобы сгенерировать случайные ключи" << endl;
    int flag;
    cin >> flag;

    switch (flag)
    {
    case 1:
        cout << "Ключ Алисы ---> ";
        cin >> alice_private_key;
        cout << "Ключ Боба --->";
        cin >> bob_private_key;
        break;
    case 2:
        alice_private_key = rand() % FIELD_MODULE;
        bob_private_key = rand() % FIELD_MODULE;
        break;
    default:
        break;
    }

    
    alice_public_key = power(PRIMITIVE_NUMBER, alice_private_key, FIELD_MODULE);
    bob_public_key = power(PRIMITIVE_NUMBER, bob_private_key, FIELD_MODULE);
    
    cout << "Alice sent her public key(" << alice_public_key << ") to Bob" << endl;
    cout << "Bob sent her public key(" << bob_public_key << ") to Alice" << endl;
    
    cout << "\n--------------------------------------------\n" << endl;

    bob_session_key = power(alice_public_key, bob_private_key, FIELD_MODULE);
    cout << "Bob session key = " << bob_session_key << endl;

    alice_session_key = power(bob_public_key, alice_private_key, FIELD_MODULE);
    cout << "Alice session key = " << bob_session_key << endl;

    return 0;
}