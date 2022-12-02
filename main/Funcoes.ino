int Placar(int tempo, int pontos) {
  int unidade = tempo % 10;
  int dezena = (tempo / 10) % 10; 
  int centena = (tempo / 100) % 10;
  int milhar = (tempo / 1000) % 10; 
  int unidadeP = pontos % 10;
  int dezenaP = (pontos / 10) % 10; 
  int centenaP = (pontos / 100) % 10;
  int milharP = (pontos / 1000) % 10; 
  for(int i = 0; i < 15; i++) {
  delay(T);
  P5();
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
  }}}
int VerificarPontos(char serial){
  if(serial == 'A'){ //Verifica qual comando recebido para decidir qual time ganha ou perde pontos.
    return 1;}
  if(serial == 'B'){
    return 100;}
  if(serial == 'C'){
    return -1;}
  if(serial == 'D'){
    return -100;}
  else
    return 0;
  }
int AtualizarPontos(int pontos, int NovosPontos){
  if (pontos + NovosPontos >= 9999){//Verifica se algum time ultrapassa o limite de 99 pontos ou chega a um valor negativo, se sim reseta o placar do time ou não altera.
    return pontos - 9900;
  }
  if ((pontos / 10) % 10 == 9 and pontos % 10 == 9){
    return pontos - 99;
  }
  if (pontos + NovosPontos < 0 or ((pontos / 10) % 10 == 0 and pontos % 10 == 0) and NovosPontos == -1){
    return pontos;
  }
  else
    return pontos + NovosPontos;
}
