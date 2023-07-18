/*** Funções para controles através de botões touch capacitivos e controle remoto infravermelho IR ***/

void onOffDevices(int opc) {
  switch (opc) {
    //case 1,2,3,4 controle de iluminação, ventilador e desligar todos.
    //Iluminação 1
    case 1:
      if (POWER_STATE_1 == LOW) {
        digitalWrite(RELAY_PIN_1, LOW);
        POWER_STATE_1 = !POWER_STATE_1;
        my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_1);
        Serial.println("Iluinação 1 Ligado");
      } else {
        digitalWrite(RELAY_PIN_1, HIGH);
        POWER_STATE_1 = !POWER_STATE_1;
        my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_1);
        Serial.println("Iluminação 1 Desligado");
      }
      delay(100);
      break;

    //Iluminação 2
    case 2:
      if (POWER_STATE_2 == LOW) {
        digitalWrite(RELAY_PIN_2, LOW);
        POWER_STATE_2 = !POWER_STATE_2;
        my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_2);
        Serial.println("Iluinação 2 Ligado");
      } else {
        digitalWrite(RELAY_PIN_2, HIGH);
        POWER_STATE_2 = !POWER_STATE_2;
        my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_2);
        Serial.println("Iluminação 2 Desligado");
      }
      delay(100);
      break;

    //Ventilador
    case 3:
      if (POWER_STATE_3 == LOW) {
        digitalWrite(RELAY_PIN_3, LOW);
        POWER_STATE_3 = !POWER_STATE_3;
        my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_3);
        Serial.println("Ventilador Ligado");
      } else {
        digitalWrite(RELAY_PIN_3, HIGH);
        POWER_STATE_3 = !POWER_STATE_3;
        my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_3);
        Serial.println("Ventilador Desligado");
      }
      delay(100);
      break;

    //Tomada
    case 4:
      if (POWER_STATE_4 == LOW) {
        digitalWrite(RELAY_PIN_4, LOW);
        POWER_STATE_4 = !POWER_STATE_4;
        my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_4);
        Serial.println("Tomada Ligada");
      } else {
        digitalWrite(RELAY_PIN_4, HIGH);
        POWER_STATE_4 = !POWER_STATE_4;
        my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_4);
        Serial.println("Tomada Desligada");
      }
      delay(100);
      break;

    //Desligar Todos
    case 5:
      digitalWrite(RELAY_PIN_1, HIGH);
      POWER_STATE_1 = LOW;
      my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_1);
      delay(100);
      digitalWrite(RELAY_PIN_2, HIGH);
      POWER_STATE_2 = LOW;
      my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_2);
      delay(100);
      digitalWrite(RELAY_PIN_3, HIGH);
      POWER_STATE_3 = LOW;
      my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_3);
      delay(100);
      digitalWrite(RELAY_PIN_4, HIGH);
      POWER_STATE_4 = LOW;
      my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, POWER_STATE_4);
      delay(100);
      Serial.println("Todos os dispositivos Desligado");
      break;
    default: break;
  }
}

/* Função para controle manual da iluminação através de botões touch */
void manualControl() {
  int capacitanciaMaxima = 20;  //valor que nos da a certeza de toque
  int mediaTouch1 = 0, mediaTouch2 = 0, mediaTouch3 = 0;

  //Serial.print("Valor Botão 1"); Serial.println(touchRead(BUTTON_PIN_1));
  //Serial.print("Valor Botão 2"); Serial.println(touchRead(BUTTON_PIN_2));
  //Serial.print("Valor Botão 3"); Serial.println(touchRead(BUTTON_PIN_3));

  //Faz 100 leituras de cada sensor touch e calcula a média do valor lido
  for (int i = 0; i < 100; i++) {
    mediaTouch1 += touchRead(BUTTON_PIN_1);
    mediaTouch2 += touchRead(BUTTON_PIN_2);
    mediaTouch3 += touchRead(BUTTON_PIN_3);
  }

  mediaTouch1 = mediaTouch1 / 100;
  mediaTouch2 = mediaTouch2 / 100;
  mediaTouch3 = mediaTouch3 / 100;

  //Iluminação 1
  if (mediaTouch1 < capacitanciaMaxima) {
    onOffDevices(1);
  }
  //Iluminação 2
  else if (mediaTouch2 < capacitanciaMaxima) {
    onOffDevices(2);
  }
  //Ventilador
  else if (mediaTouch3 < capacitanciaMaxima) {
    onOffDevices(3);
  }
  delay(100);
}

/* Função para controle através do controle remoto infravermelho. */
void remoteControl() {
  if (IrReceiver.decode()) {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case IR_BUTTON_1: onOffDevices(1); break;  //Iluminação 1
      case IR_BUTTON_2: onOffDevices(2); break;  //Iluminação 2
      case IR_BUTTON_3: onOffDevices(3); break;  //Ventilador
      case IR_BUTTON_4: onOffDevices(4); break;  //Tomada Extra
      case IR_BUTTON_5: onOffDevices(5); break;  //Desligar Todos
      default: break;
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();
  }
}