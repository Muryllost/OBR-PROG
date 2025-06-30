// === VARIÁVEIS DE CONTROLE DE MOVIMENTO ===
const unsigned long tempoCurvaF1 = 700;
const unsigned long tempoCurvaF2 = 1000;
const unsigned long tempoCurvaD1 = 500;
const unsigned long tempoCurvaD2 = 500;
const unsigned long tempoCurvaE1 = 500;
const unsigned long tempoCurvaE2 = 500;

// === Função genérica de movimento com temporização ===
void executarMovimento(void (*acao)(), unsigned long duracao) {
  unsigned long t0 = millis();  
  while (millis() - t0 < duracao) {
    acao();
  }
  PararMotor();
}

// === Função para medir distância média com sensor Sharp ===
float medirDistanciaSharp() {
  const int NUM_LEITURAS = 5;
  float somaDist = 0.0;

  for (int i = 0; i < NUM_LEITURAS; i++) {
    int leitura = analogRead(PINO_SHARP);
    float tensao = leitura * (5.0 / 1023.0);
    float distancia = 27.86 * pow(tensao, -1.15);
    somaDist += distancia;
    delay(10);
  }

  return somaDist / NUM_LEITURAS;
}

// === Verifica obstáculo e executa desvio com segurança ===
bool VerificaObstaculo() {
  float distanciaMedia = medirDistanciaSharp();

  if (distanciaMedia > 14 && distanciaMedia < 16) {
    PararMotor();

    // Desvio com movimentos temporizados
    executarMovimento(CurvaDir90Sharp, tempoCurvaD1);
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF1);
    delay(500);
    executarMovimento(CurvaEsq90Sharp, tempoCurvaE1);
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF2);
    delay(500);
    executarMovimento(CurvaEsq90Sharp, tempoCurvaE2);
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF1);
    delay(500);
    executarMovimento(CurvaDir90Sharp, tempoCurvaD2);
    delay(100);
    PararMotor();

    return true;
  }

  return false;
}