#include <assert.h>

// If anything is okay return 0 else, return non-zero

int bpm_ok(float bpm){
  return !(bpm < 70 || bpm > 150);
}

int spo2_ok(float spo2){
  return !(spo2 < 90);
}

int respRate_ok(float respRate){
  return !(respRate < 30 || respRate > 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  int val = bpm_ok(bpm) | spo2_ok(spo2) | respRate_ok(respRate);
  if(val == 0){
    return true;
  }
  return false;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
