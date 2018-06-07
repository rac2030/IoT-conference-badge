
// Identifier of the badge, used for communication
uint64_t chipid;

void setup()
{
    Serial.begin(115200);
    // Get this devices ID
    chipid=ESP.getEfuseMac();


}

void loop()
{
	
}
