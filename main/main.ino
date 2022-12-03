#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
// Inicia o sistema de bluetooth
void BemVindo(){
  SerialBT.println("Bem-vindo ao placar!");
  SerialBT.println("Este placar faz parte do Trabalho de Conclusão de Curso do curso de Tecnico em Eletronica da Etec Getulio Vargas");
  SerialBT.println("Todo codigo usado na programacao desse placar esta disponivel em https://github.com/Lipe3BrokeN/TCC-Placar-Poliesportivo-Eletronico");
  SerialBT.println("Caso queira um tempo personalizado, digite no terminal os quatro numeros que deseja e no final coloque 1 para crescente ou 0 para decrescente.");
}
// Declaramos as saídas do timer, uma variável de tempo T e o pause despause.
  char Pause, Despause, serial; //Serial é o valor recebido pelo Bluetooth
  int A = 19; //Segmentos e Displays
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
 Placar(2407, 2407);
 if (SerialBT.available()) { // So inicia o timer com o Bluetooth funcionando
  BemVindo();
  String Jogo = SerialBT.readString(); // Lê o que foi digitado para determinar a ordem, 0 para decrescente e 1 para crescente.
  int Tempo = CalculaTempo(Jogo);
  if (Jogo[4] == '1'){
    for (int i = 0; i < Tempo; i++) { //Loop que conta de 0 até 6000, e retorna a 0. O delay é definido por 8 * T em ms
      serial = (char)SerialBT.read();
      if (serial == 'E'){ i = 0;}
      if (serial == 'G'){ESP.restart();}
      Pause = serial;
      while (Pause == '1'){
        Placar(i, Pontos);
        serial = (char)SerialBT.read();
        if (serial == 'E'){ i = 0;}
        if (serial == 'G'){ESP.restart();}
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));
        Despause = serial;
        if (Despause == '1'){
          break;}}
      Placar(i, Pontos); //Atualiza os pontos e o tempo.
      Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));  //Verefica se houve alguma mudança nos pontos.
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {
        i = i + 41;
        Placar(i, Pontos);
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));}
      }}
  if (Jogo[4] == '0'){
    for (int i = Tempo; i > 0; i--) { //Mesmo loop so que decrescente
      serial = (char)SerialBT.read();
      if (serial == 'E'){ i = Tempo;}
      if (serial == 'G'){ESP.restart();}
      Pause = serial;
      while (Pause == '1'){
        Placar(i, Pontos);
        serial = (char)SerialBT.read();
        if (serial == 'E'){ i = Tempo;}
        if (serial == 'G'){ESP.restart();}
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));
        Despause = serial;
        if (Despause == '1'){
          break;}}
      Placar(i, Pontos);
      Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));
      if ( (i / 10) % 10 == 0 and i % 10 == 0) {
        i = i - 41;
        Placar(i, Pontos);
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));}
      }}}}
