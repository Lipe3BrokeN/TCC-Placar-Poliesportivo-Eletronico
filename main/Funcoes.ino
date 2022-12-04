int Placar(int tempo, int pontos) { //Nesse arquivos temos as funções principais
  int unidade = tempo % 10; //Esta função recebe o tempo e a quantidade de pontos e imprime nos displays
  int dezena = (tempo / 10) % 10; //Calcula cada digito
  int centena = (tempo / 100) % 10;
  int milhar = (tempo / 1000) % 10; 
  int unidadeP = pontos % 10;
  int dezenaP = (pontos / 10) % 10; 
  int centenaP = (pontos / 100) % 10;
  int milharP = (pontos / 1000) % 10; 
  for(int i = 0; i < 125; i++) {//125 Vezes pois há 8 delays T de 1ms, totalizando 1000ms ou 1 segundo.
  delay(T);
  P5();//Chama todos os displays com seus valores
  switch (unidadeP) {
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
  P6();
  switch (dezenaP) {
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
  P7();
  switch (centenaP) {
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
  P8();
  switch (milharP) {
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
  P2();
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
  P3();
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
  P4();
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
  }}
  P0();}
int VerificarPontos(char serial){//Verifica qual comando recebido para decidir qual time ganha ou perde pontos.
  if(serial == 'A'){ 
    return 1;}
  if(serial == 'B'){
    return 100;}
  if(serial == 'C'){
    return -1;}
  if(serial == 'D'){
    return -100;}
  if(serial == 'F'){
    return 2407;}//Valor aleatorio para falar que é o usario deseja resetar a pontuação
  else
    return 0;//Caso não tenha nenhuma mudança, retorna 0
  }
int AtualizarPontos(int pontos, int NovosPontos){//Verefica se há necessidade de atualizar a pontuação.
  if (NovosPontos == 2407){
    return 0;
  }
  if ((pontos / 10) % 10 == 9 and pontos % 10 == 9 and NovosPontos == 1){//Verifica se algum time ultrapassa o limite de 99 pontos ou chega a um valor negativo, se sim reseta o placar do time ou não altera.
    return pontos - 99;
  }
  if (pontos + NovosPontos >= 10000){
    return pontos - 9900;
  }
  if (pontos + NovosPontos < 0 or ((pontos / 10) % 10 == 0 and pontos % 10 == 0) and NovosPontos == -1){
    return pontos;
  }
  else
    return pontos + NovosPontos;
}
int CalculaTempo(String Jogo){//Recebe a String lida no Bluetooth, e retorna o valor do tempo.
  int milhar = (Jogo[0] - '0') * 1000;
  int centena = (Jogo[1] - '0') * 100;
  int dezena = (Jogo[2] - '0') * 10;
  int unidade = (Jogo[3] - '0');
  return (milhar + centena + dezena + unidade);
}
