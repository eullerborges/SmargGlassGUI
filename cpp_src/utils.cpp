#include "utils.h"
/**
 * @brief comverte todos os bytes de uma string para sua representação hexadecimal
 * @param string a ser convertida
 * @return  string convertida
 */
std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

/**
 * @brief Converte uma cor do padrão LedStrength para RGB
 * @param color Cor a ser convertifda
 * @return cor convertida
 */
double convertRGB(LedStrength color){
    double resultingColor = 0;
    if (color == LedStrength::STRENGTH_25) resultingColor = 0.25 * 255;
    else if (color == LedStrength::STRENGTH_50) resultingColor = 0.5 * 255;
    else if (color == LedStrength::STRENGTH_100) resultingColor = 255;
    return resultingColor;
}

/**
 * @brief Converte uma componente RGB para o padrão LedStrength
 * @param colorComponent componente de cor a ser convertida
 * @return cor convertida
 */
LedStrength colorComponentToLedStrength(int colorComponent){
    if(colorComponent == 0) return LedStrength::STRENGTH_0;
    else if(colorComponent == int(0.25*255)) return LedStrength::STRENGTH_25;
    else if(colorComponent == int(0.5*255)) return LedStrength::STRENGTH_50;
    else return LedStrength::STRENGTH_100;
}

