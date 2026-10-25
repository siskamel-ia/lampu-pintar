
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6Tcag9bqb"
#define BLYNK_TEMPLATE_NAME "smart lamp"
#define BLYNK_AUTH_TOKEN "jj8vT0ByAoMdLbJdGV7Hh4vreUW8FY3A"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int lampu = D2;  // GPIO4

char ssid[] = "Caca";
char pass[] = "Takon Caca";

void setup()
{
  Serial.begin(9600);

  pinMode(lampu, OUTPUT);
  digitalWrite(lampu, LOW);  // Mulai dengan lampu mati

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Fungsi ini akan dijalankan saat tombol di aplikasi Blynk pada Virtual Pin V1 ditekan
BLYNK_WRITE(V1)
{
  int statusLampu = param.asInt();
  digitalWrite(lampu, statusLampu == 1 ? LOW : HIGH); // aktif LOW
}

void loop()
{
  Blynk.run();
}
