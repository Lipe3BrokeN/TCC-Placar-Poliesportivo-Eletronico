int Timer(int valor, int Pontos) {
  int unidade = valor % 10;
  int dezena = (valor / 10) % 10; 
  int centena = (valor / 100) % 10;
  int milhar = valor / 1000;
  for(int i = 0; i < 15; i++) {
  Placar(Pontos);
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
  Placar(Pontos);
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
  Placar(Pontos);
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
  Placar(Pontos);
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
int Placar(int valor) {
  int unidade = valor % 10;
  int dezena = (valor / 10) % 10; 
  int centena = (valor / 100) % 10;
  int milhar = valor / 1000;
  delay(T);
  P42();
  switch (unidade) {
    case 0:
      Zero2();
      break;
    case 1:
      Um2();
      break;
    case 2:
      Dois2();
      break;
    case 3:
      Tres2();
      break;
    case 4:
      Quatro2();
      break;
    case 5:
      Cinco2();
      break;
    case 6:
      Seis2();
      break;
    case 7:
      Sete2();
      break;
    case 8:
      Oito2();
      break;
    case 9:
      Nove2();
      break;
  }
  delay(T);
  P32();
  switch (dezena) {
    case 0:
      Zero2();
      break;
    case 1:
      Um2();
      break;
    case 2:
      Dois2();
      break;
    case 3:
      Tres2();
      break;
    case 4:
      Quatro2();
      break;
    case 5:
      Cinco2();
      break;
    case 6:
      Seis2();
      break;
    case 7:
      Sete2();
      break;
    case 8:
      Oito2();
      break;
    case 9:
      Nove2();
      break;
  }
  delay(T);
  P22();
  switch (centena) {
    case 0:
      Zero2();
      break;
    case 1:
      Um2();
      break;
    case 2:
      Dois2();
      break;
    case 3:
      Tres2();
      break;
    case 4:
      Quatro2();
      break;
    case 5:
      Cinco2();
      break;
    case 6:
      Seis2();
      break;
    case 7:
      Sete2();
      break;
    case 8:
      Oito2();
      break;
    case 9:
      Nove2();
      break;
  }
  delay(T);
  P12();
  switch (milhar) {
    case 0:
      Zero2();
      break;
    case 1:
      Um2();
      break;
    case 2:
      Dois2();
      break;
    case 3:
      Tres2();
      break;
    case 4:
      Quatro2();
      break;
    case 5:
      Cinco2();
      break;
    case 6:
      Seis2();
      break;
    case 7:
      Sete2();
      break;
    case 8:
      Oito2();
      break;
    case 9:
      Nove2();
      break;
  }}
int AdicionarPontos(){ //Vou remover essa função é so pra testes!!!!
  int ran = random(2);
  int ponto = 0;
  int ran2 = random(10);
  if (ran2 == 1){
    switch (ran){
      case 1:
        ponto = ponto + 100;
      case 2:
        ponto = ponto +1;
  return ponto;
  }}
}
