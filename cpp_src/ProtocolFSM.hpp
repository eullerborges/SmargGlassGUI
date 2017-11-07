//
// Created by Euller Borges on 15/06/17.
//

#ifndef NICE2METER_SERVER_PROTOCOLFSM_H
#define NICE2METER_SERVER_PROTOCOLFSM_H

#include "Protocol_Packet.hpp"
#include <functional>
#include <iostream>
#include <string>

using namespace std;

enum FSM_State {GET_START_FRAME, GET_MESSAGE_TYPE,
  GET_SEQ_NUMBER, GET_DATA_SIZE, GET_CRC, GET_DATA};


/**
 * Máquina de estados do protocolo
 */
class ProtocolFSM {
public:
  ProtocolFSM(std::function<void(int, std::string)>);
  /**
   * Função de tratamento de um byte da comunicação
   */
  void parseByte(uint8_t byte);
  /**
   * Função que reinicia a máquina de estados.
   */

private:
  FSM_State _state;
  Protocol_Packet _packet;
  int _curr_byte_count;
  void _change_state(FSM_State next_state);
  void _reset();
  std::function<void(int, std::string)> _callback;

};


#endif //NICE2METER_SERVER_PROTOCOLFSM_H
