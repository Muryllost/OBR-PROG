// #include <SharpIR.h>
#define PINO_SHARP A0         // Pino analógico onde está ligado o Sharp


const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
// === Variáveis de controle de estado de manobra ===
bool executandoManobra = false;
unsigned long tempoFinalManobra = 0;

// Motores
int IN1 = 21, IN2 = 20, IN3 = 19, IN4 = 18;
int PWM_A = 2; //Velocidade do motor A
int PWM_B = 3; //Velocidade do motor B

int vel_A = 100;
int vel_B = 100;
int vel_A = 110;
int vel_B = 90;

// Sensores IR (ordem da esquerda para a direita)
int IR[] = {22, 24, 26, 28, 30};
@@ -26,67 +25,70 @@
int outD = 52;  

void setup() {
  // Configura os pinos como saída
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Acende os LEDs (nível alto = ligado)
  analogWrite(led2, HIGH);
  analogWrite(led3, HIGH);
  analogWrite(led4, HIGH);

  pinMode(PINO_SHARP, INPUT); 

  // === Pinos dos Sensores IR ===
  for (int i = 0; i <= 5; i++) {
    pinMode(IR[i], INPUT);
  } 
  // === Pinos do Sensor de Cor ===
  for (int j = 0; j < 4; j++) {
    pinMode(VD[j], OUTPUT);
    pinMode(VE[j], OUTPUT);
  } 
  pinMode(outD, INPUT);
  pinMode(outE, INPUT);

  // Configuração da escala de frequência de leitura
  digitalWrite(VD[0], HIGH);
  digitalWrite(VD[1], LOW);

  digitalWrite(VD[2], HIGH);
  digitalWrite(VD[3], LOW);

  digitalWrite(VE[0], HIGH);
  digitalWrite(VE[1], LOW);

  digitalWrite(VE[2], HIGH);
  digitalWrite(VE[3], LOW);

  // === Pinos do Motor ===
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  // Verifica se está executando manobra
  if (executandoManobra) {
    if (millis() >= tempoFinalManobra) {
      executandoManobra = false;
      PararMotor(); // finaliza manobra com parada
    }
    return; // enquanto executa manobra, não faz mais nada
  }

  // if (VerificaObstaculo()){
  // // } 
  if (Verde()){
  // PRIORIDADE MÁXIMA: Obstáculo
  if (VerificaObstaculo()) {
    return;
  } 
  if (Curva90()) {
    return;
  } 
  else {
    SegueLinha();
  }

// Verde();
  // // PRIORIDADE ALTA: Verde
  // if (Verde()) {
  //   return;
  // }

  // // PRIORIDADE MÉDIA: Curva de 90°
  // if (Curva90()) {
  //   return;
  // }

  // // AÇÃO PADRÃO: Segue linha
  // SegueLinha();
}
