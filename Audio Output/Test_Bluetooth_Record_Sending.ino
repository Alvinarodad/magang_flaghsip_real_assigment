#include "BluetoothA2DPSource.h"
#include "StarWars30.h"

BluetoothA2DPSource a2dp_source;
SoundData *data = new OneChannelSoundData((int16_t*)StarWars30_raw, StarWars30_raw_len/2);

void setup() {
  a2dp_source.start("RadioPlayer");  
  a2dp_source.writeData(data);
}

void loop() {
}
