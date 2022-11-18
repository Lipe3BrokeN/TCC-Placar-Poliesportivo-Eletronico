#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
// Inicia o sistema de bluetooth

// Declaramos as saídas do timer, uma variável de tempo T e o pause despause.
  char Pause, Despause;
  int A = 19;
  int B = 18;
  int C = 5;
  int D = 17;
  int E = 16;
  int F = 4;
  int G = 0;
  int D10 = 22;
  int D20 = 21;
  int D30 = 2;
  int D40 = 15;
  int A2 = 32;
  int B2 = 33;
  int C2 = 25;
  int D2 = 26;
  int E2 = 27;
  int F2 = 14;
  int G2 = 12;
  int D12 = 1;
  int D22 = 3;
  int D32 = 23; 
  int D42 = 13; // A,B,D10,... Timer
  int T = 1;  // A2,B2,D12,... Placar
  int Pontos = 0;
// Criamos as funções dos números de 0 a 9 para o timer.
// Criamos a escolha do digito a ser escrito no timer.
// Essa é a principal função, serve para escrever o valor no timer de acordo com o número recebido.
void setup() {
  Serial.begin(921600); // Velocidade de upload.
  SerialBT.begin("Placar Eletronico"); // Nome do Placar.
  //Define os pinos como saída.
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D20, OUTPUT);
  pinMode(D30, OUTPUT);
  pinMode(D40, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(D12, OUTPUT);
  pinMode(D22, OUTPUT);
  pinMode(D32, OUTPUT);
  pinMode(D42, OUTPUT);
}
void loop() {
 if (SerialBT.available()) { // So inicia o timer com o Bluetooth funcionando
  char Ordem =(char)SerialBT.read(); // Lê o que foi digitado para determinar a ordem, 0 para decrescente e 1 para crescente.
  if (Ordem == '1'){  // Aqui temos a função que conta.
    SerialBT.println("Para pausar digite 1"); // Mensagem no celular.
    SerialBT.println("Para despausar digite 0");
    for (int i = 0; i < 6000; i++) { //Loop que conta de 0 até 6000, e retorna a 0. O delay é definido por 4 * T em ms
      Pause =(char)SerialBT.read();
      while (Pause == '1'){
        Timer(i, Pontos);
        Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      Timer(i, Pontos);
      Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {
        i = i + 41;
        Timer(i, Pontos);
        Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      }}}
  if (Ordem == '0');{
    SerialBT.println("Para pausar digite 1");
    SerialBT.println("Para despausar digite 0");
    for (int i = 6000; i > 0; i--) { //Mesmo loop so que decrescente
      Pause =(char)SerialBT.read();
      while (Pause == '1'){
        Timer(i, Pontos);
        Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      Timer(i, Pontos);
      Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      if ( (i / 10) % 10 == 0 and i % 10 == 0) {
        i = i - 41;
        Timer(i, Pontos);
        Pontos = Pontos + AdicionarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      }}}}}
