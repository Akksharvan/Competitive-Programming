#include <iostream>
#include <fstream>
using namespace std;
 
bool cow_ends_infected[101];
int N, cowx[251], cowy[251];
 
bool consistent_with_data(int patient_zero, int K)
{
  bool infected[101] = {false};
  int num_handshakes[101] = {0};
  infected[patient_zero] = true;
  for (int t=0; t<=250; t++) {
    int x = cowx[t], y = cowy[t];
    if (x>0) {
      if (infected[x]) num_handshakes[x]++;
      if (infected[y]) num_handshakes[y]++;
      if (num_handshakes[x] <= K && infected[x]) infected[y] = true;
      if (num_handshakes[y] <= K && infected[y]) infected[x] = true;
    }
  }
  for (int i=1; i<=N; i++)
    if (infected[i] != cow_ends_infected[i]) return false;
  return true;
}
 
int main(void)
{
  int T, t, x, y;
  string s;
 
  ifstream fin ("tracing.in");
  fin >> N >> T >> s;
  for (int i=1; i<=N; i++)
    cow_ends_infected[i] = s[i-1]=='1';
  for (int i=0; i<T; i++) {
    fin >> t >> x >> y;
    cowx[t] = x;
    cowy[t] = y;
  }
 
  bool possible_i[101] = {false};
  bool possible_K[252] = {false};
  for (int i=1; i<=N; i++)
    for (int K=0; K<=251; K++)
      if (consistent_with_data(i, K)) 
	possible_i[i] = true; possible_K[K] = true;
 
  int lower_K=251, upper_K=0, num_patient_zero=0;
  for (int K=0; K<=251; K++) if (possible_K[K]) upper_K = K;
  for (int K=251; K>=0; K--) if (possible_K[K]) lower_K = K;
  for (int i=1; i<=N; i++) if (possible_i[i]) num_patient_zero++;
 
  ofstream fout ("tracing.out");
  fout << num_patient_zero << " " << lower_K << " ";
  if (upper_K==251) fout << "Infinity\n";
  else fout << upper_K << "\n";
 
  return 0;
}