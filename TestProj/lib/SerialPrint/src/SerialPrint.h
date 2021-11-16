#include "Arduino.h"

class SerialPrint {
  private:
  public:
    SerialPrint(){
      Serial.begin(115200);
    }

    void println(const String &s){
      Serial.println(s);
    }

    void print(const String &s){
      Serial.print(s);
    }

    void print(int n) {
      Serial.print(n);
    }
};