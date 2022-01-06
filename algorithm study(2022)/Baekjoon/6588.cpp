#include <bits/stdc++.h>
#define NUM 1000000
using namespace std;

bool primes[NUM];
vector<int> primeNumbers;

void init(int sz) {
   for (int i = 0; i < sz; i++) {
      primes[i] = true;
   }
}

void getPrimes(int sz) {
   for (int i = 2; i < sz; i++) {
      int cnt = 2;
      if (primes[i]) {
         while (i * cnt < sz) {
            primes[i * cnt] = false;
            cnt++;
         }
      }
   }
}

int solve(int n) {
   for (int i = 0; i < primeNumbers.size(); i++) {
      int num = primeNumbers[i];
      if (primes[n - num]) {
         return num;
      }
   }
   return -1;
}

int main(void) {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   init(NUM);
   getPrimes(NUM);

   for (int i = 3; i < NUM; i++) {
      if (primes[i]) {
         primeNumbers.push_back(i);
      }
   }

   while (true) {
      int input;
      cin >> input;
      if (input != 0) {
         int ans = solve(input);
         if (ans != -1) {
            cout << input << " = " << ans << " + " << input - ans << "\n";
         } else {
            cout << "Goldbach's conjecture is wrong."
                 << "\n";
         }
      } else {
         break;
      }
   }
   return 0;
}
