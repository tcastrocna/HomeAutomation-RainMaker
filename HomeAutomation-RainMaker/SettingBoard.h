const uint32_t BAUD_RATE = 115200;          //Frequência do monitor serial

// Definir o nome do dispositivo e senha de acesso, é necessário para configuração inicial do Esp
const char *service_name = "HOME_AUTOMATION";
const char *pop = "12345678";

const char *NAME_DEVICE = "Home Automation"; //Nome do dispositivo, ele aparecerá no app.

// Definir os nomes dos dispositivos criados
char DEVICE_NAME_1[] = "Iluminação 1";
char DEVICE_NAME_2[] = "Iluminação 2";
char DEVICE_NAME_3[] = "Ventilador";
char DEVICE_NAME_4[] = "Tomada";

bool POWER_STATE_1 = LOW;                   // Estado de energia dos relé 1, deve iniciar LOW (desligado NO)
bool POWER_STATE_2 = LOW;                   // Estado de energia dos relé 2, deve iniciar LOW (desligado NO)
bool POWER_STATE_3 = LOW;                   // Estado de energia dos relé 3, deve iniciar LOW (desligado NO) 
bool POWER_STATE_4 = LOW;                   // Estado de energia dos relé 4, deve iniciar LOW (desligado NO)

static uint8_t WIFI_LED_PIN = 16;           // Definir pino do LED - Estado de rede.
static uint8_t RESET_BUTTON_PIN = 17;       // Definir o pino do botão de resetar a rede.

static uint8_t RELAY_PIN_1 = 18;            //Relé da iluminação 1
static uint8_t RELAY_PIN_2 = 19;            //Relé da iluminação 2
static uint8_t RELAY_PIN_3 = 23;            //Relé do ventilador
static uint8_t RELAY_PIN_4 = 05;            //Tomada Extra

static uint8_t BUTTON_PIN_1 = 13;           //Botão da iluminação 1
static uint8_t BUTTON_PIN_2 = 12;           //Botão da iluminação 2
static uint8_t BUTTON_PIN_3 = 14;           //Botão do ventilador
static uint8_t BUTTON_PIN_4 = 27;           //Null

static uint8_t IR_RECEIVER = 25;            //Receptor Infravermelho.
static uint8_t DHT_SENSOR = 26;             //Sensor de Temperatura e Umidade
static uint8_t LDR_SENSOR = 35;             //Sensor de luminosidade na porta analógica.

//Descomente o modelo de sensor a ser usando do sensor de temperatura DHT!
const uint32_t DHTTYPE = DHT11;             // DHT 11
//const uint32_t DHTTYPE = DHT21;            // DHT 21, AM2301
//const uint32_t DHTTYPE = DHT22;            // DHT 22, AM2302, AM2321

const uint32_t IR_BUTTON_1 = 0xEF106E01;    //Botão 1 controle IR, Relé Iluminação 1. (mudar após 0x)
const uint32_t IR_BUTTON_2 = 0xEE116E01;    //Botão 2 controle IR, Relé Iluminação 2. (mudar após 0x)
const uint32_t IR_BUTTON_3 = 0xED126E01;    //Botão 3 controle IR, Relé Ventilador. (mudar após 0x)
const uint32_t IR_BUTTON_4 = 0xEC136E01;    //Botão 4 controle IR, Relé Tomada Extra. (mudar após 0x)
const uint32_t IR_BUTTON_5 = 0xFE016E01;    //Botão OFF controle IR, Desliga todos. (mudar após 0x)
