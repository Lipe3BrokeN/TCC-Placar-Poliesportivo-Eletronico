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
  int T = 1;
// Criamos as funções dos números de 0 a 9 para o timer.
void Zero() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 1);}
void Um() {
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);}
void Dois() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 1);
  digitalWrite(G, 0);}
void Tres() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 0);}
void Quatro() {
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);}
void Cinco() {
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);}
void Seis() {
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);}
void Sete() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);}
void Oito() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);}
void Nove() {
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);}
// Criamos a escolha do digito a ser escrito no timer.
void P1() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);}
void P2() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);}
void P3() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);}
void P4() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);}
// Essa é a principal função, serve para escrever o valor no timer de acordo com o número recebido.
int escrever(int valor) {
  int unidade = valor % 10;
  int dezena = (valor / 10) % 10; 
  int centena = (valor / 100) % 10;
  int milhar = valor / 1000;
  for(int i = 0; i < 15; i++) {
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
  }}}
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
        escrever(i); // Função de pause.
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      escrever(i);
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {
        i = i + 41;
        escrever(i);
      }}}
  if (Ordem == '0');{
    SerialBT.println("Para pausar digite 1");
    SerialBT.println("Para despausar digite 0");
    for (int i = 6000; i > 0; i--) { //Mesmo loop so que decrescente
      Pause =(char)SerialBT.read();
      while (Pause == '1'){
        escrever(i);
        Despause =(char)SerialBT.read();
        if (Despause == '0'){
          break;}}
      escrever(i);
      if ( (i / 10) % 10 == 0 and i % 10 == 0) {
        i = i - 41;
        escrever(i);
      }}}}}
