// Motor A = Esquerdo (IN1, IN2, PWM_A)
// Motor B = Direito  (IN3, IN4, PWM_B)

void Motor(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void PararMotor(){  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void MotorRe() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// MOVIMENTO DOS MOTORES CURVA DE 90 DIREITA
void MotorDir90(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// MOVIMENTO DOS MOTORES CURVA DE 90 ESQUERDA
void MotorEsq90(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//=========================================================//
void MoverFrente() {//LINHA RETA
  Motor();  
  analogWrite(PWM_A, vel_A  );//LINHA RETA
  analogWrite(PWM_B, vel_B  );//LINHA RETA
  analogWrite(PWM_A, vel_A + 20 );//LINHA RETA
  analogWrite(PWM_B, vel_B + 20 );//LINHA RETA
}

void MoverAcenDir(){//CURVA ACENTUADA A DIREITA
//=========================================================//
//--- CURVA ACENTUADA A DIREITA ---
void MoverAcenDir(){
  MotorDir90();  
  analogWrite(PWM_A, vel_A + 120);//CURVA ACENTUADA A DIREITA
  analogWrite(PWM_B, vel_B + 120);//CURVA ACENTUADA A DIREITA
}

void MoverAcenEsq(){//CURVA ACENTUADA A ESQUERDA
//--- CURVA ACENTUADA A ESQUERDA ---
void MoverAcenEsq(){
  MotorEsq90(); 
  analogWrite(PWM_A, vel_A + 120);//CURVA ACENTUADA A ESQUERDA
  analogWrite(PWM_B, vel_B + 120);//CURVA ACENTUADA A ESQUERDA
}

//=========================================================//
// --- Curva Direita 90 ---
void CurvaDir90(){
  MotorDir90();
  analogWrite(PWM_A, vel_A + 150);
  analogWrite(PWM_B, vel_B + 150);
  analogWrite(PWM_A, vel_A + 120);
  analogWrite(PWM_B, vel_B + 120);
}

// --- Curvs Esquerda 90 ---
void CurvaEsq90(){
  MotorEsq90();
  analogWrite(PWM_A, vel_A + 150);
  analogWrite(PWM_B, vel_B + 150);
  analogWrite(PWM_A, vel_A + 120);
  analogWrite(PWM_B, vel_B + 120);
}

// void Voltar(){
//   MotorRe();
//   analogWrite(PWM_A, vel_A  );//LINHA RETA
//   analogWrite(PWM_B, vel_B  );//LINHA RETA
// }
//=========================================================//
// --- VERDE Direita ---
void CurvaDir90Ved(){
  MotorDir90();
  analogWrite(PWM_A, vel_A + 120);
  analogWrite(PWM_B, vel_B + 140);

    executandoManobra = true;
  tempoFinalManobra = millis() + 700;
}
// --- VERDE Esquerda ---
void CurvaEsq90Ved(){
  MotorEsq90();
  analogWrite(PWM_A, vel_A + 140);
  analogWrite(PWM_B, vel_B + 120);

    executandoManobra = true;
  tempoFinalManobra = millis() + 1200; // duração real da curva
}
//=========================================================//
void Voltar(){
  MotorRe();
  analogWrite(PWM_A, vel_A  );//LINHA RETA
  analogWrite(PWM_B, vel_B  );//LINHA RETA
}
//=========================================================//

// --- Curva Direita 90 ---
void CurvaDir90Sharp(){
  MotorDir90();
  analogWrite(PWM_A, vel_A + 140);
  analogWrite(PWM_B, vel_B + 160);
}

// --- Curvs Esquerda 90 ---
void CurvaEsq90Sharp(){
  MotorEsq90();
  analogWrite(PWM_A, vel_A + 140);
  analogWrite(PWM_B, vel_B + 160);
}
//=========================================================//
