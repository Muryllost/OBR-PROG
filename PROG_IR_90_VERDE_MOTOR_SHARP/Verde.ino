 // Variáveis de leitura da cor
  int greenD1 = 0, greenD2 = 0 ,mediaD = 0;
int greenD1 = 0;
int greenE1 = 0;

  int greenE1 = 0, greenE2 = 0 ,mediaE = 0;
  // == LEITURAS DA MEDIA DO VERDE
  bool Verde() {
bool Verde() {
  greenD1 = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
  greenE1 = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);

    greenD1 = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
    greenD2 = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
  Serial.println(greenD1);
  Serial.println(greenE1);

    greenE1 = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);
    greenE2 = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);


    mediaD = (greenD1+greenD2)/2;
    mediaE = (greenE1+greenE2)/2;

    Serial.print("Verde Média Direita: ");
    Serial.println(mediaD);
    Serial.print("Verde Média Esquerda: ");
    Serial.println(mediaE);
    delay(500);

  //=========================================================//

    // --- VERDE Direita Detectado ---
      if ((mediaD <= 36) && (mediaD >= 32)) {
      Serial.println("Verde Direita detectado");
      CurvaDir90();
      return true;
    }

    // --- VERDE Esquerda Detectado ---
    if ((mediaE <= 38) && (mediaE >= 32)) {
      Serial.println("Verde Esquerda detectado");
      CurvaEsq90();
      return true;
    }

  //=========================================================//

    return false;
  if ((greenD1 >= 30) && (greenD1 <= 40)) {
    Serial.println("Verde Direita detectado");
    CurvaDir90Ved();
    return true;
  }

  if ((greenE1 >= 30) && (greenE1 <= 40)) {
    Serial.println("Verde Esquerda detectado");
    CurvaEsq90Ved();
    return true;
  }


  return false;
}
