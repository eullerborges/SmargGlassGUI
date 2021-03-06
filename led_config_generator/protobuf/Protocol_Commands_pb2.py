# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: Protocol_Commands.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='Protocol_Commands.proto',
  package='',
  serialized_pb=_b('\n\x17Protocol_Commands.proto\";\n\x04Nack\x12\x11\n\tcommandID\x18\x01 \x02(\r\x12 \n\nnackReason\x18\x02 \x02(\x0e\x32\x0c.NackReasons\"\x18\n\x03\x41\x63k\x12\x11\n\tcommandID\x18\x01 \x02(\r\"!\n\x0c\x42\x61sicCommand\x12\x11\n\tcommandID\x18\x01 \x02(\r*G\n\x0bNackReasons\x12\x14\n\x10INVALID_MSG_TYPE\x10\x00\x12\x10\n\x0cINVALID_DATA\x10\x01\x12\x10\n\x0c\x44\x45\x43ODE_ERROR\x10\x02')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

_NACKREASONS = _descriptor.EnumDescriptor(
  name='NackReasons',
  full_name='NackReasons',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='INVALID_MSG_TYPE', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INVALID_DATA', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DECODE_ERROR', index=2, number=2,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=149,
  serialized_end=220,
)
_sym_db.RegisterEnumDescriptor(_NACKREASONS)

NackReasons = enum_type_wrapper.EnumTypeWrapper(_NACKREASONS)
INVALID_MSG_TYPE = 0
INVALID_DATA = 1
DECODE_ERROR = 2



_NACK = _descriptor.Descriptor(
  name='Nack',
  full_name='Nack',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='commandID', full_name='Nack.commandID', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='nackReason', full_name='Nack.nackReason', index=1,
      number=2, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=27,
  serialized_end=86,
)


_ACK = _descriptor.Descriptor(
  name='Ack',
  full_name='Ack',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='commandID', full_name='Ack.commandID', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=88,
  serialized_end=112,
)


_BASICCOMMAND = _descriptor.Descriptor(
  name='BasicCommand',
  full_name='BasicCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='commandID', full_name='BasicCommand.commandID', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=114,
  serialized_end=147,
)

_NACK.fields_by_name['nackReason'].enum_type = _NACKREASONS
DESCRIPTOR.message_types_by_name['Nack'] = _NACK
DESCRIPTOR.message_types_by_name['Ack'] = _ACK
DESCRIPTOR.message_types_by_name['BasicCommand'] = _BASICCOMMAND
DESCRIPTOR.enum_types_by_name['NackReasons'] = _NACKREASONS

Nack = _reflection.GeneratedProtocolMessageType('Nack', (_message.Message,), dict(
  DESCRIPTOR = _NACK,
  __module__ = 'Protocol_Commands_pb2'
  # @@protoc_insertion_point(class_scope:Nack)
  ))
_sym_db.RegisterMessage(Nack)

Ack = _reflection.GeneratedProtocolMessageType('Ack', (_message.Message,), dict(
  DESCRIPTOR = _ACK,
  __module__ = 'Protocol_Commands_pb2'
  # @@protoc_insertion_point(class_scope:Ack)
  ))
_sym_db.RegisterMessage(Ack)

BasicCommand = _reflection.GeneratedProtocolMessageType('BasicCommand', (_message.Message,), dict(
  DESCRIPTOR = _BASICCOMMAND,
  __module__ = 'Protocol_Commands_pb2'
  # @@protoc_insertion_point(class_scope:BasicCommand)
  ))
_sym_db.RegisterMessage(BasicCommand)


# @@protoc_insertion_point(module_scope)
