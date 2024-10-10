#include <iostream>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int> &nums, int target) {
    //PLAN PARA HACER EL ALGORITMO
    // 1. Sería tomar el primero con todos los demás hasta que me de el resultado?
    // Ideas: Qué pasa si el primero número nunca se alínea con el 2do?
    // Debería ir recorriendo todos los arreglos, el 1 ero con todos, 2do con todos y así...
    // Pero el problema de esto es resolverlo en O(n) por ende no puedo tener anidados.
    // target = n + m
    // La suma de dos números pares siempre me va a dar un par, y la de dos impares un par
    // 2 + 2 = 4 || 3 + 1 = 4

    //POR FUERZA BRUTA Y LUEGO MEJORO:
    int n;
    int m;
    vector<int> res;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 1 ; j < nums.size() ; j++) {
            n = nums[i];
            m = nums[j];
            if (n + m == target && i!=j) {
                return res = {i,j};
            }
        }
    }
    return res;
}

int main() { 
    vector <int> nums = {2,5,5,11};
    vector <int> res;
    res = twoSum(nums, 10);

    for(int c:res){
        cout<<c<<endl;
    }


    // nums = [2,7,11,15], target = 9
    // RES = [0,1] -> 2 + 7 = 9

    return 0; };