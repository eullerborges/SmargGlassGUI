/** @file Arquivo de definição do pacote do protocolo de comunicação.
 *   Esse arquivo define o pacote do protocolo e suas funções auxiliares para
 *  encapsular e serializar dados.
*/

#ifndef NICE2METER_SERVER_PROTOCOL_PACKET_H
#define NICE2METER_SERVER_PROTOCOL_PACKET_H

#include <string>
#include <stdint.h>

const uint8_t START_FRAME[] = {0x55, 0x69, 0x55, 0x69};

// Defines dos message types
#define MT_MEAS_DATA  0x01

/**
 * Classe com o pacote do protocolo
 */
class Protocol_Packet {
public:
  uint32_t start_frame;
  uint32_t uid;
  uint8_t message_type;
  uint8_t seq_number;
  uint16_t data_size;
  uint32_t crc;
  std::string data;
  /**
   * Função de reset do pacote. Zera todos os campos.
   */
  void reset();
  /**
   * Função que encapsula o campo de dados em um pacote do protocolo,
   * gravando o tipo de mensagem para detecção pela aplicação receptora.
   * @param message_type tipo da mensagem a ser enviado.
   * @param data dados a serem encapsulados.
   * @param res_buffer ponteiro para a string onde o resultado será
   * armazenado.
   */
  void encode_data(int msg_type, std::string &bytes, std::string *res_buffer);
  /**
   * Retorna o conteúdo do pacote serializado
   * @return string com o conteúdo.
   */
  void serialize(std::string *buffer);
};


#endif //NICE2METER_SERVER_PROTOCOL_PACKET_H
