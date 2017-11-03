#include <iostream>
#include "ProtocolFSM.hpp"

//#define DEBUG

#ifdef DEBUG
#define PRINT_DEBUG(msg) std::cout << msg << std::endl
#else
#define PRINT_DEBUG(msg)
#endif

/**
 * Construtor da classe
 * @param callback Callback para uma função de tratamento de pacotes quando
 * um pacote for recebido
 */
ProtocolFSM::ProtocolFSM(std::function<void(int, std::string)> callback) {
  _state = FSM_State::GET_START_FRAME;
  _packet = new Protocol_Packet();
  _curr_byte_count = 0;
  _callback = callback;
}

/**
 * Executa a máquina de estados, tratando byte a byte.
 * @param byte byte a ser tratado.
 */
void ProtocolFSM::parseByte(uint8_t byte) {
  switch (_state){
    // Estado GET_FRAME_START
    case FSM_State::GET_START_FRAME:
      PRINT_DEBUG("Start frame");
      if (byte == START_FRAME[_curr_byte_count]){
        _packet->start_frame += byte << 8 * _curr_byte_count;
        _curr_byte_count++;
      }
      else{
        _reset();
      }
      // Se lemos o header completo
      if (_curr_byte_count == sizeof(START_FRAME)){
        _change_state(FSM_State::GET_UID);
      }
      break;

    // Estado GET_UID
    case FSM_State::GET_UID:
      PRINT_DEBUG("GET UID");
      _packet->uid += byte << 8 * _curr_byte_count;
      _curr_byte_count++;
      if (_curr_byte_count == sizeof(_packet->uid)){
        _change_state(FSM_State::GET_MESSAGE_TYPE);
      }
      break;

    // Estado GET_MESSAGE_TYPE
    case FSM_State::GET_MESSAGE_TYPE:
      PRINT_DEBUG("GET MESSAGE TYPE");
      _packet->message_type = byte;
      _change_state(FSM_State::GET_SEQ_NUMBER);
      break;

    // Estado GET_SEQ_NUMBER
    case FSM_State::GET_SEQ_NUMBER:
      PRINT_DEBUG("GET SEQ NUMBER");
      _packet->seq_number += byte << 8 * _curr_byte_count;
      _curr_byte_count++;
      if (_curr_byte_count == sizeof(_packet->seq_number)){
        _change_state(FSM_State::GET_DATA_SIZE);
      }
      break;

    // Estado GET_DATA_SIZE
    case FSM_State::GET_DATA_SIZE:
      PRINT_DEBUG("GET DATA SIZE");
      _packet->data_size += byte << 8 * _curr_byte_count;
      _curr_byte_count++;
      if (_curr_byte_count == sizeof(_packet->data_size)){
        _change_state(FSM_State::GET_CRC);
      }
      break;

    // Estado GET_CRC
    case FSM_State::GET_CRC:
      PRINT_DEBUG("GET CRC");
      _packet->crc += (byte << 8*(_curr_byte_count));
      _curr_byte_count++;
      if (_curr_byte_count == sizeof(_packet->crc)/sizeof(byte)){
        _curr_byte_count = 0;
        _state = FSM_State::GET_DATA;
      }
      break;

    // Estado GET_DATA
    case FSM_State::GET_DATA:
      PRINT_DEBUG("GET DATA");
      _packet->data.append((char*)&byte, 1);
      _curr_byte_count++;
      if (_curr_byte_count == _packet->data_size){
        //std::cout << "Recebi um pacote completo!" << std::endl;
        _callback(_packet->message_type, _packet->data);
        _reset();
      }
      break;

    default:
      break;
  }
  return;
}

/**
 *  \brief Método de mudança de estado da máquina de estados
 *
 *  \param next_state próximo estado da máquina
 *  \return void
 */
void ProtocolFSM::_change_state(FSM_State next_state) {
  _state = next_state;
  _curr_byte_count = 0;
}

/**
 *  \brief Método de reinício da máquina de estados
 *  \return void
 */
void ProtocolFSM::_reset() {
  _state = FSM_State::GET_START_FRAME;
  delete _packet;
  _packet = new Protocol_Packet();
  _curr_byte_count = 0;
}
