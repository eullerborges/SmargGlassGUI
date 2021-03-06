// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol_Commands.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Protocol_Commands.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Nack_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Nack_reflection_ = NULL;
const ::google::protobuf::Descriptor* Ack_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Ack_reflection_ = NULL;
const ::google::protobuf::Descriptor* BasicCommand_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BasicCommand_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* NackReasons_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Protocol_5fCommands_2eproto() {
  protobuf_AddDesc_Protocol_5fCommands_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Protocol_Commands.proto");
  GOOGLE_CHECK(file != NULL);
  Nack_descriptor_ = file->message_type(0);
  static const int Nack_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Nack, commandid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Nack, nackreason_),
  };
  Nack_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Nack_descriptor_,
      Nack::default_instance_,
      Nack_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Nack, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Nack, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Nack));
  Ack_descriptor_ = file->message_type(1);
  static const int Ack_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Ack, commandid_),
  };
  Ack_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Ack_descriptor_,
      Ack::default_instance_,
      Ack_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Ack, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Ack, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Ack));
  BasicCommand_descriptor_ = file->message_type(2);
  static const int BasicCommand_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicCommand, commandid_),
  };
  BasicCommand_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BasicCommand_descriptor_,
      BasicCommand::default_instance_,
      BasicCommand_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicCommand, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicCommand, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BasicCommand));
  NackReasons_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Protocol_5fCommands_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Nack_descriptor_, &Nack::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Ack_descriptor_, &Ack::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BasicCommand_descriptor_, &BasicCommand::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Protocol_5fCommands_2eproto() {
  delete Nack::default_instance_;
  delete Nack_reflection_;
  delete Ack::default_instance_;
  delete Ack_reflection_;
  delete BasicCommand::default_instance_;
  delete BasicCommand_reflection_;
}

void protobuf_AddDesc_Protocol_5fCommands_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027Protocol_Commands.proto\";\n\004Nack\022\021\n\tcom"
    "mandID\030\001 \002(\r\022 \n\nnackReason\030\002 \002(\0162\014.NackR"
    "easons\"\030\n\003Ack\022\021\n\tcommandID\030\001 \002(\r\"!\n\014Basi"
    "cCommand\022\021\n\tcommandID\030\001 \002(\r*G\n\013NackReaso"
    "ns\022\024\n\020INVALID_MSG_TYPE\020\000\022\020\n\014INVALID_DATA"
    "\020\001\022\020\n\014DECODE_ERROR\020\002", 220);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protocol_Commands.proto", &protobuf_RegisterTypes);
  Nack::default_instance_ = new Nack();
  Ack::default_instance_ = new Ack();
  BasicCommand::default_instance_ = new BasicCommand();
  Nack::default_instance_->InitAsDefaultInstance();
  Ack::default_instance_->InitAsDefaultInstance();
  BasicCommand::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Protocol_5fCommands_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Protocol_5fCommands_2eproto {
  StaticDescriptorInitializer_Protocol_5fCommands_2eproto() {
    protobuf_AddDesc_Protocol_5fCommands_2eproto();
  }
} static_descriptor_initializer_Protocol_5fCommands_2eproto_;
const ::google::protobuf::EnumDescriptor* NackReasons_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NackReasons_descriptor_;
}
bool NackReasons_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int Nack::kCommandIDFieldNumber;
const int Nack::kNackReasonFieldNumber;
#endif  // !_MSC_VER

Nack::Nack()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Nack)
}

void Nack::InitAsDefaultInstance() {
}

Nack::Nack(const Nack& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Nack)
}

void Nack::SharedCtor() {
  _cached_size_ = 0;
  commandid_ = 0u;
  nackreason_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Nack::~Nack() {
  // @@protoc_insertion_point(destructor:Nack)
  SharedDtor();
}

void Nack::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Nack::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Nack::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Nack_descriptor_;
}

const Nack& Nack::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_5fCommands_2eproto();
  return *default_instance_;
}

Nack* Nack::default_instance_ = NULL;

Nack* Nack::New() const {
  return new Nack;
}

void Nack::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Nack*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(commandid_, nackreason_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Nack::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Nack)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 commandID = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &commandid_)));
          set_has_commandid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_nackReason;
        break;
      }

      // required .NackReasons nackReason = 2;
      case 2: {
        if (tag == 16) {
         parse_nackReason:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::NackReasons_IsValid(value)) {
            set_nackreason(static_cast< ::NackReasons >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Nack)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Nack)
  return false;
#undef DO_
}

void Nack::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Nack)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->commandid(), output);
  }

  // required .NackReasons nackReason = 2;
  if (has_nackreason()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->nackreason(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Nack)
}

::google::protobuf::uint8* Nack::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Nack)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->commandid(), target);
  }

  // required .NackReasons nackReason = 2;
  if (has_nackreason()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->nackreason(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Nack)
  return target;
}

int Nack::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 commandID = 1;
    if (has_commandid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->commandid());
    }

    // required .NackReasons nackReason = 2;
    if (has_nackreason()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->nackreason());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Nack::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Nack* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Nack*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Nack::MergeFrom(const Nack& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_commandid()) {
      set_commandid(from.commandid());
    }
    if (from.has_nackreason()) {
      set_nackreason(from.nackreason());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Nack::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Nack::CopyFrom(const Nack& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Nack::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Nack::Swap(Nack* other) {
  if (other != this) {
    std::swap(commandid_, other->commandid_);
    std::swap(nackreason_, other->nackreason_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Nack::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Nack_descriptor_;
  metadata.reflection = Nack_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Ack::kCommandIDFieldNumber;
#endif  // !_MSC_VER

Ack::Ack()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Ack)
}

void Ack::InitAsDefaultInstance() {
}

Ack::Ack(const Ack& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Ack)
}

void Ack::SharedCtor() {
  _cached_size_ = 0;
  commandid_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Ack::~Ack() {
  // @@protoc_insertion_point(destructor:Ack)
  SharedDtor();
}

void Ack::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Ack::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Ack::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Ack_descriptor_;
}

const Ack& Ack::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_5fCommands_2eproto();
  return *default_instance_;
}

Ack* Ack::default_instance_ = NULL;

Ack* Ack::New() const {
  return new Ack;
}

void Ack::Clear() {
  commandid_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Ack::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Ack)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 commandID = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &commandid_)));
          set_has_commandid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Ack)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Ack)
  return false;
#undef DO_
}

void Ack::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Ack)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->commandid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Ack)
}

::google::protobuf::uint8* Ack::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Ack)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->commandid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Ack)
  return target;
}

int Ack::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 commandID = 1;
    if (has_commandid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->commandid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Ack::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Ack* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Ack*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Ack::MergeFrom(const Ack& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_commandid()) {
      set_commandid(from.commandid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Ack::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Ack::CopyFrom(const Ack& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ack::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Ack::Swap(Ack* other) {
  if (other != this) {
    std::swap(commandid_, other->commandid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Ack::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Ack_descriptor_;
  metadata.reflection = Ack_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int BasicCommand::kCommandIDFieldNumber;
#endif  // !_MSC_VER

BasicCommand::BasicCommand()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:BasicCommand)
}

void BasicCommand::InitAsDefaultInstance() {
}

BasicCommand::BasicCommand(const BasicCommand& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:BasicCommand)
}

void BasicCommand::SharedCtor() {
  _cached_size_ = 0;
  commandid_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BasicCommand::~BasicCommand() {
  // @@protoc_insertion_point(destructor:BasicCommand)
  SharedDtor();
}

void BasicCommand::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BasicCommand::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BasicCommand::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BasicCommand_descriptor_;
}

const BasicCommand& BasicCommand::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_5fCommands_2eproto();
  return *default_instance_;
}

BasicCommand* BasicCommand::default_instance_ = NULL;

BasicCommand* BasicCommand::New() const {
  return new BasicCommand;
}

void BasicCommand::Clear() {
  commandid_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BasicCommand::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:BasicCommand)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 commandID = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &commandid_)));
          set_has_commandid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:BasicCommand)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:BasicCommand)
  return false;
#undef DO_
}

void BasicCommand::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:BasicCommand)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->commandid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:BasicCommand)
}

::google::protobuf::uint8* BasicCommand::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:BasicCommand)
  // required uint32 commandID = 1;
  if (has_commandid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->commandid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BasicCommand)
  return target;
}

int BasicCommand::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 commandID = 1;
    if (has_commandid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->commandid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BasicCommand::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BasicCommand* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BasicCommand*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BasicCommand::MergeFrom(const BasicCommand& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_commandid()) {
      set_commandid(from.commandid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BasicCommand::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BasicCommand::CopyFrom(const BasicCommand& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BasicCommand::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void BasicCommand::Swap(BasicCommand* other) {
  if (other != this) {
    std::swap(commandid_, other->commandid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BasicCommand::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BasicCommand_descriptor_;
  metadata.reflection = BasicCommand_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
