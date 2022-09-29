/* #ifndef _BL
#define BLUETOOTH_SERIAL_H



#if defined(CONFIG_BT_ENABLED) && defined(CONFIG_BLUEZDROID_ENABLED)

#include "Arduino.h"
#include "Stream.h"
#include <esp_gap_bt_api.h>
#include <esp_spp_api.h>
#include <functional>
#include <map>
#include "BTScan.h"

typedef std::function<void(const uint8_t *buffer, size_t size)> BluetoothSerialDataCb;
typedef std::function<void(uint32_t num_val)> ConfirmRequestCb;
typedef std::function<void(boolean success)> AuthCompleteCb;
typedef std::function<void(BTAdvertisedDevice* pAdvertisedDevice)> BTAdvertisedDeviceCb;

class BluetoothSerial: public Stream
{
  public:

    BluetoothSerial(void);
    ~BluetoothSerial(void);

    bool begin(String localName = String(), bool isMaster = false);
    bool begin(unsigned long baud) { //compatibility
      return begin();
    }
    int available(void);
    int peek(void);
    bool hasClient(void);
    int read(void);
    size_t write(uint8_t c);
    size_t write(const uint8_t *buffer, size_t size);
    void flush();
    void end(void);
    void setTimeout(int timeoutMS);
    void onData(BluetoothSerialDataCb cb);
    esp_err_t register_callback(esp_spp_cb_t * callback);

    void onConfirmRequest(ConfirmRequestCb cb);
    void onAuthComplete(AuthCompleteCb cb);
    void confirmReply(boolean confirm);

    void enableSSP();
    bool setPin(const char *pin);
    bool connect(String remoteName);
    bool connect(uint8_t remoteAddress[], int channel = 0, esp_spp_sec_t sec_mask = (ESP_SPP_SEC_ENCRYPT | ESP_SPP_SEC_AUTHENTICATE), esp_spp_role_t role = ESP_SPP_ROLE_MASTER);
    bool connect(const BTAddress &remoteAddress, int channel = 0, esp_spp_sec_t sec_mask = (ESP_SPP_SEC_ENCRYPT | ESP_SPP_SEC_AUTHENTICATE), esp_spp_role_t role = ESP_SPP_ROLE_MASTER) {
      return connect(*remoteAddress.getNative(), channel, sec_mask);
    };
    bool connect();
    bool connected(int timeout = 0);
    bool isClosed();
    bool isReady(bool checkMaster = false, int timeout = 0);
    bool disconnect();
    bool unpairDevice(uint8_t remoteAddress[]);

    BTScanResults* discover(int timeout = 0x30 * 1280);
    bool discoverAsync(BTAdvertisedDeviceCb cb, int timeout = 0x30 * 1280);
    void discoverAsyncStop();
    void discoverClear();
    BTScanResults* getScanResults();

    std::map<int, std::string> getChannels(const BTAddress &remoteAddress);

    const int INQ_TIME = 1280;   // Inquire Time unit 1280 ms
    const int MIN_INQ_TIME = (ESP_BT_GAP_MIN_INQ_LEN * INQ_TIME);
    const int MAX_INQ_TIME = (ESP_BT_GAP_MAX_INQ_LEN * INQ_TIME);

    operator bool() const;
  private:
    String local_name;
    int timeoutTicks = 0;
};

#endif

#endif
*/
//Cria uma instância de BluetoothSerial chamado SerialBT
//Fim da parte do Davi

//Declaramos as saídas do timer e uma variável de tempo T.
int A = 19;
int B = 18;
int C = 5;
int D = 17;
int E = 16;
int F = 4;
int G = 0;
int D1 = 22;
int D2 = 21;
int D3 = 2;
int D4 = 15;
int T = 1;
//Criamos as funções dos números de 0 a 9 para o timer.
void Zero() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 1);
}
void Um() {
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}
void Dois() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
}
void Tres() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
}
void Quatro() {
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void Cinco() {
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void Seis() {
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void Sete() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}
void Oito() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void Nove() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
// Criamos a escolha do digito a ser escrito no timer.
void P1() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
void P2() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
void P3() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}
void P4() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}
//Essa é a principal função, serve para escrever o valor no timer de acordo com o número recebido.
int escrever(int valor) { 
  int unidade = valor % 10;
  int dezena = (valor / 10) % 10;
  int centena = (valor / 100) % 10;
  int milhar = valor / 1000;
  for (int i = 0; i < 15; i++) {
    delay(T);
    P4();
    switch (unidade) {
      case 0:
        Zero();
        break;
      case 1:
        Um();
        break;
      case 2:
        Dois();
        break;
      case 3:
        Tres();
        break;
      case 4:
        Quatro();
        break;
      case 5:
        Cinco();
        break;
      case 6:
        Seis();
        break;
      case 7:
        Sete();
        break;
      case 8:
        Oito();
        break;
      case 9:
        Nove();
        break;
    }
    delay(T);
    P3();
    switch (dezena) {
      case 0:
        Zero();
        break;
      case 1:
        Um();
        break;
      case 2:
        Dois();
        break;
      case 3:
        Tres();
        break;
      case 4:
        Quatro();
        break;
      case 5:
        Cinco();
        break;
      case 6:
        Seis();
        break;
      case 7:
        Sete();
        break;
      case 8:
        Oito();
        break;
      case 9:
        Nove();
        break;
    }
    delay(T);
    P2();
    switch (centena) {
      case 0:
        Zero();
        break;
      case 1:
Um();
        break;
      case 2:
        Dois();
        break;
      case 3:
        Tres();
        break;
      case 4:
        Quatro();
        break;
      case 5:
        Cinco();
        break;
      case 6:
        Seis();
        break;
      case 7:
        Sete();
        break;
      case 8:
        Oito();
        break;
      case 9:
        Nove();
        break;
    }
    delay(T);
    P1();
    switch (milhar) {
      case 0:
        Zero();
        break;
      case 1:
        Um();
        break;
      case 2:
        Dois();
        break;
      case 3:
        Tres();
        break;
      case 4:
        Quatro();
        break;
      case 5:
        Cinco();
        break;
      case 6:
        Seis();
        break;
      case 7:
        Sete();
        break;
      case 8:
        Oito();
        break;
      case 9:
        Nove();
        break;
    }
  }
}
void setup() {
 /* //Coisa do Davi
  //Inicia uma comunicação SERIAL com uma taxa de transmissão de 115200
  Serial.begin(115200);
  //Iniacia o dispositivo SERIAL Bluetooth com o argumento o nome do dispositivo
  */
  //Define os pinos como saída.
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

}
void loop() {
/*  //Coisa do Davi
  //Verifica se algo foi recebido pela porta SERIAL
  //Se sim envie os dados recebidos via Bluetooth ao dispositivo conectado
  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  //Verifica se há algo na porta SERIAL Bluetooth
  //Se sim envia os dados para o monitor SERIAL
  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
    delay(20);
  }
*/
  //Aqui temos a função que conta 
  int R = digitalRead(23); //Lê o pino 23 para descidir se a contagem é crescente ou decrescente, é so para testes.
  if (R == 0) {
    for (int i = 0; i < 6000; i++) {
      escrever(i); //Loop que conta de 0 até 6000, e retorna a 0. O delay é definido por 4 * T em ms
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {
        i = i + 41;
        escrever(i);
      }
    }
  }
  else if (R == 1) {
    for (int i = 6000; i > 0; i--) {
      escrever(i); //Mesmo loop so que decrescente
      if ( (i / 10) % 10 == 0 and i % 10 == 0) {
        i = i - 41;
        escrever(i);
      }
 }
}
}
