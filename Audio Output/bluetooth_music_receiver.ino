#include "BluetoothA2DPSink.h"


BluetoothA2DPSink a2dp_sink;
bool is_active = true;

void avrc_metadata_callback(uint8_t id, const uint8_t *text) {
  Serial.printf("==> AVRC metadata rsp: attribute id 0x%x, %s\n", id, text);
}

void setup() {
  Serial.begin(115200);
  a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
  a2dp_sink.start("MyMusic");  
}


void loop() {
  // pause / play ever 10 seconds 
  if (a2dp_sink.get_audio_state()==ESP_A2D_AUDIO_STATE_STARTED){
    delay(10000);
    Serial.println("changing state...");
    is_active = !is_active;
    if (is_active){
      Serial.println("play");
      a2dp_sink.play();
    } else {
      Serial.println("pause");
      a2dp_sink.pause();
    }
  } 
}
