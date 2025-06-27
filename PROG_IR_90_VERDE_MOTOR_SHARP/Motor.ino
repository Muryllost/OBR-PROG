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

void MoverFrente() {//LINHA RETA
  Motor();  
  analogWrite(PWM_A, vel_A  );//LINHA RETA
  analogWrite(PWM_B, vel_B  );//LINHA RETA
}

void MoverAcenDir(){//CURVA ACENTUADA A DIREITA
  MotorDir90();  
  analogWrite(PWM_A, vel_A + 120);//CURVA ACENTUADA A DIREITA
  analogWrite(PWM_B, vel_B + 120);//CURVA ACENTUADA A DIREITA
}

void MoverAcenEsq(){//CURVA ACENTUADA A ESQUERDA
  MotorEsq90(); 
  analogWrite(PWM_A, vel_A + 120);//CURVA ACENTUADA A ESQUERDA
  analogWrite(PWM_B, vel_B + 120);//CURVA ACENTUADA A ESQUERDA
}

void CurvaDir90(){
  MotorDir90();
  analogWrite(PWM_A, vel_A + 150);
  analogWrite(PWM_B, vel_B + 150);
}

void CurvaEsq90(){
  MotorEsq90();
  analogWrite(PWM_A, vel_A + 150);
  analogWrite(PWM_B, vel_B + 150);
}

// void Voltar(){
//   MotorRe();
//   analogWrite(PWM_A, vel_A  );//LINHA RETA
//   analogWrite(PWM_B, vel_B  );//LINHA RETA
// }



