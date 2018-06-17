String UniqueID()
{
  uint64_t id = ESP.getEfuseMac();
  char id_h[9];
  char id_l[9];

  sprintf(id_h, "%08X", (uint32_t)(id>>32));
  sprintf(id_l, "%08X", (uint32_t)(id));

  return String(id_h) + String(id_l);
}

void setup()
{
}

void loop()
{
}
