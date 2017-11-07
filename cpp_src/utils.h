#include <string>
#include "Protocol_Leds.pb.h"

std::string string_to_hex(const std::string& input);
double convertRGB(LedStrength color);
LedStrength colorComponentToLedStrength(int colorComponent);
