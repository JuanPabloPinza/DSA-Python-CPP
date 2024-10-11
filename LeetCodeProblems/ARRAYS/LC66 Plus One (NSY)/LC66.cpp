#include <iostream>
#include <string>
#include <vector>

using namespace std;

//NOTA: En este ejercicio no se puede trabajar con tipos de datos int y long long
// Ya que en los constrains nos da hasta 100 dígitos y eso no se puede.



vector<int> plusOne(vector<int> &digits) {
  // 1. Convertir cada dígito y agregarlo a solo un número.
  // 2. Sumarle 1
  // 3. Convertir cada dígito de nuevo a un array.
  vector<int> res;
  string numero = "";
  string temp;

  for (int n : digits) {
    temp = to_string(n);
    numero += temp;
  }
  cout << numero<<endl;
  numero = to_string(stol(numero) + 1);
//   cout << numero<<endl;
  int digit;
  for (int i = 0; i < numero.size(); i++) {
    digit = numero[i];
    res.push_back(digit - '0');
  }

  return res;
}

int main() {
  vector<int> digits = {1, 3, 4, 5};
  vector<int> res = plusOne(digits);
    for(int c:res){
        cout<<c;
    }
  

  return 0;
}
