#define BUILDIN_LED 2
#define ledPIN1 23
#define ledPIN2 22

// ----------------------------------------------------------------------------------
void first_task(void *pvParameter){
  /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
     muxed to GPIO on reset already, but some default to other
     functions and need to be switched to GPIO. Consult the
     Technical Reference for a list of pads and their default
     functions.)
  */
  pinMode(ledPIN1,OUTPUT);

  while(true) {
    digitalWrite(ledPIN1, HIGH);
    vTaskDelay(50 / portTICK_RATE_MS);
    digitalWrite(ledPIN1, LOW);
    vTaskDelay(50 / portTICK_RATE_MS);
  }
}

// ----------------------------------------------------------------------------------
void second_task(void *pvParameter){
  /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
     muxed to GPIO on reset already, but some default to other
     functions and need to be switched to GPIO. Consult the
     Technical Reference for a list of pads and their default
     functions.)
  */
  pinMode(ledPIN2,OUTPUT);

  while(true) {
    digitalWrite(ledPIN2, HIGH);
    vTaskDelay(500 / portTICK_RATE_MS);
    digitalWrite(ledPIN2, LOW);
    vTaskDelay(500 / portTICK_RATE_MS);
  }
}

void setup() {
  
  pinMode(BUILDIN_LED,OUTPUT);

  // xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask)
  //first thread blinky in 50ms
  xTaskCreate(&first_task, "first_task", 1024, NULL, 5, NULL);
  //second thread blinky in 500ms
  xTaskCreate(&second_task,"second_task",1024, NULL, 5, NULL);
  
}


// the loop function runs over and over again forever
void loop() {
  digitalWrite(BUILDIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);              // wait for a second
  digitalWrite(BUILDIN_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(250);              // wait for a second
}