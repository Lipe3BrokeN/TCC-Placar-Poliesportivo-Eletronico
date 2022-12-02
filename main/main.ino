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
  int D1 = 22;
  int D2 = 21;
  int D3 = 2;
  int D4 = 15;
  int D5 = 25;
  int D6 = 26;
  int D7 = 27;
  int D8 = 14;
  int T = 1;  
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
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
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
        Placar(i, Pontos);
        Pontos = Pontos + VerificarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      Placar(i, Pontos);
      Pontos = Pontos + VerificarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {
        i = i + 41;
        Placar(i, Pontos);
        Pontos = Pontos + VerificarPontos();} // REMOVER DEPOIS, SOMENTE TESTES
        Pause =(char)SerialBT.read();
      }}
  if (Ordem == '0'){
    SerialBT.println("Para pausar digite 1");
    SerialBT.println("Para despausar digite 0");
    for (int i = 6000; i > 0; i--) { //Mesmo loop so que decrescente
      while (Pause == '1'){
        Placar(i, Pontos);
        Pontos = Pontos + VerificarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      Placar(i, Pontos);
      Pontos = Pontos + VerificarPontos(); // REMOVER DEPOIS, SOMENTE TESTES
      if ( (i / 10) % 10 == 0 and i % 10 == 0) {
        i = i - 41;
        Placar(i, Pontos);
        Pontos = Pontos + VerificarPontos();} // REMOVER DEPOIS, SOMENTE TESTES
      Pause =(char)SerialBT.read();
      }}}}
