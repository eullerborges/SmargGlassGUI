/** @file Arquivo de definição do pacote do protocolo de comunicação.
 *   Esse arquivo define o pacote do protocolo e suas funções auxiliares para
 *  encapsular e serializar dados.
 */

#include "Protocol_Packet.hpp"
#include "cpp_src/crc.h"

/**
 * Extrai um byte específico de um inteiro
 */
#define GETBYTE(x, d) (x >> 8*d) & 0xFF
#define GETNUMBYTES(value) sizeof(value)/sizeof(uint8_t)

/**
 * Adiciona um inteiro a uma string, byte a byte, little endian
 * @param buffer buffer onde será escrito o inteiro
 * @param integer inteiro a ser escrito
 * @param size tamanho em bytes do inteiro
 */
static inline void addIntegerToString(std::string *buffer, int integer,
                                      int size) {
  for (int i = 0; i < size; i++){
    *buffer += GETBYTE(integer, i);
  }
}

/**
 *  \brief Reseta o pacote para o seu estado padrão
 *  \return void
 */
void Protocol_Packet::reset() {
  start_frame = 0;
  message_type = 0;
}

/**
 *  \brief Codifica bytes em um pacote do protocolo do nice2meter
 *  \param msg_type tipo da mensagem
 *  \param bytes bytes a serem encapsulados no pacote
 *  \param res_buffer ponteiro para o buffer onde o resultado será escrito
 *  \return void
 */
void Protocol_Packet::encode_data(int msg_type, std::string &bytes, std::string
                                         *res_buffer) {
  start_frame = *(uint16_t*)START_FRAME;
  message_type = (uint8_t) msg_type;
  seq_number = 0x22;
  data_size = (uint16_t) bytes.length();
  crc = Crc_crc16Calc((uint8_t*)(bytes.c_str()), (uint16_t)(bytes.size()));
  data = bytes;
  serialize(res_buffer);
}

/**
 *  \brief Serializa os dados de um pacote para envio em uma interface serial
 *  de comunicação  
 *  \param buffer buffer onde será escrito o resultado
 *  \return void
 */
void Protocol_Packet::serialize(std::string *buffer) {
  addIntegerToString(buffer, start_frame, GETNUMBYTES(start_frame));
  addIntegerToString(buffer, message_type, GETNUMBYTES(message_type));
  addIntegerToString(buffer, seq_number, GETNUMBYTES(seq_number));
  addIntegerToString(buffer, data_size, GETNUMBYTES(data_size));
  addIntegerToString(buffer, crc, GETNUMBYTES(crc));
  buffer->append(data);
}
