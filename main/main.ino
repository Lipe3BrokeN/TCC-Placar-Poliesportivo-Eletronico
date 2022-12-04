#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;// Inicia o sistema de bluetooth
void BemVindo(){ // Função de boas vindas
  SerialBT.println("Bem-vindo ao placar!");
  SerialBT.println("Este placar faz parte do Trabalho de Conclusão de Curso do curso de Tecnico em Eletronica da Etec Getulio Vargas");
  SerialBT.println("Todo codigo usado na programacao desse placar esta disponivel em https://github.com/Lipe3BrokeN/TCC-Placar-Poliesportivo-Eletronico");
  SerialBT.println("Caso queira um tempo personalizado, digite no terminal os quatro numeros que deseja e no final coloque 1 para crescente ou 0 para decrescente.");
}
  char Pause, Despause, serial; //Pause e Despause para pausar e despausar respectivamente, serial é a leitura do Bluetooth
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
  const int T = 1;  //T é uma variavel para decidir o tempo, ela não é alterada em nenhum momento.
  int Pontos = 2407; // Inicializa os pontos. Esse valor é aleatorio e usado para verificar se não há nenhum problema antes da partida.
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
 Placar(2407, Pontos); //Mostra 2407 na pontuação e no timer a quantidade de pontos, para informar que o placar está ligado
 if (SerialBT.available()) { // So inicia o timer com o Bluetooth funcionando
  BemVindo();
  Pontos = 0; //Zera os pontos
  String Jogo = SerialBT.readString(); // Lê o que foi digitado (Sempre será uma string com 5 digitos, caso digite outra coisa pode apresentar uma falha logica), Os 4 primeiros digitos determinam o Tempo e o ultimo a ordem.
  int Tempo = CalculaTempo(Jogo); //Transforma o que foi digitado em uma int para usar como tempo.
  if (Jogo[4] == '1'){ // Lê a ordem
    for (int i = 0; i < Tempo; i++) { //Loop que conta de 0 até o tempo determinado. O delay é definido por 8 * 125 * T em ms
      serial = (char)SerialBT.read(); //Lê o que foi digitado
      if (serial == 'E'){ i = 0;} //Se digitado E, reseta o tempo
      if (serial == 'G'){ESP.restart();} //Se digitado G, reseta o ESP
      Pause = serial; //Se digtado 1, Pausa o tempo
      while (Pause == '1'){ //Função de Pause
        Placar(i, Pontos);
        serial = (char)SerialBT.read();
        if (serial == 'E'){ i = 0;}
        if (serial == 'G'){ESP.restart();}
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));
        Despause = serial;
        if (Despause == '1'){ //Se digitado 1 novamente, despausa o tempo
          break;}}
      Placar(i, Pontos); //Atualiza os pontos e o tempo.
      Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));  //Verefica se houve alguma mudança nos pontos.
      if ( (i / 10) % 10 == 5 and i % 10 == 9) {//Vê se os segundos passam para 60.
        i = i + 41;
        Placar(i, Pontos);
        Pontos = AtualizarPontos(Pontos,VerificarPontos(serial));}
      }
    for (int i = 0; i < 10; i++){ //Pisca quando acaba por 15 segundos
      Placar(Tempo, Pontos);
      delay(500);}} //
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
      }
    for (int i = 0; i < 10; i++){
      Placar(0, Pontos);
      delay(500);}}}}
