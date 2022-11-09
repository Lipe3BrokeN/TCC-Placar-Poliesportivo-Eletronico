  int pontos = 0;
  int A = 32;
  int B = 33;
  int C = 25;
  int D = 26;
  int E = 27;
  int F = 14;
  int G = 12;
  int D1 = 1;
  int D2 = 3;
  int D3 = 23;
  int D4 = 13;
  int T = 1;
//Criamos as funções dos números de 0 a 9 para o timer.
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
//Essa é a principal função, serve para escrever o valor no timer de acordo com o número recebido.
int escrever(int valor) {
  int unidade = valor % 10;
  int dezena = (valor / 10) % 10; 
  int centena = (valor / 100) % 10;
  int milhar = valor / 1000;
  for(int i = 0; i < 150; i++) {
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
  escrever(pontos);
  int ponto = random(2);
  if (ponto == 1){
    pontos = pontos + 100;}
  else{
    pontos = pontos + 1;}
  }
