// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol_Leds.proto

#ifndef PROTOBUF_Protocol_5fLeds_2eproto__INCLUDED
#define PROTOBUF_Protocol_5fLeds_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

class LedsConfig;
class LedBlink;
class LedRgb;
class LedsValues;
class LedStatusRequest;
class GetLedsStatus;

enum LedNumber {
  LED_RGB_1 = 0,
  LED_RGB_2 = 1,
  LED_RGB_3 = 2,
  LED_RGB_4 = 3,
  LED_RGB_5 = 4,
  LED_RGB_6 = 5,
  LED_RGB_7 = 6,
  LED_RGB_8 = 7,
  LED_RGB_9 = 8,
  LED_RGB_10 = 9,
  LED_RGB_11 = 10,
  LED_RGB_12 = 11,
  LED_RGB_13 = 12,
  LED_RGB_14 = 13,
  LED_RGB_15 = 14,
  LED_RGB_16 = 15,
  LED_RGB_17 = 16,
  LED_RGB_18 = 17,
  LED_RGB_19 = 18,
  LED_RGB_20 = 19
};
bool LedNumber_IsValid(int value);
const LedNumber LedNumber_MIN = LED_RGB_1;
const LedNumber LedNumber_MAX = LED_RGB_20;
const int LedNumber_ARRAYSIZE = LedNumber_MAX + 1;

const ::google::protobuf::EnumDescriptor* LedNumber_descriptor();
inline const ::std::string& LedNumber_Name(LedNumber value) {
  return ::google::protobuf::internal::NameOfEnum(
    LedNumber_descriptor(), value);
}
inline bool LedNumber_Parse(
    const ::std::string& name, LedNumber* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LedNumber>(
    LedNumber_descriptor(), name, value);
}
enum LedState {
  LED_OFF = 0,
  LED_ON = 1
};
bool LedState_IsValid(int value);
const LedState LedState_MIN = LED_OFF;
const LedState LedState_MAX = LED_ON;
const int LedState_ARRAYSIZE = LedState_MAX + 1;

const ::google::protobuf::EnumDescriptor* LedState_descriptor();
inline const ::std::string& LedState_Name(LedState value) {
  return ::google::protobuf::internal::NameOfEnum(
    LedState_descriptor(), value);
}
inline bool LedState_Parse(
    const ::std::string& name, LedState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LedState>(
    LedState_descriptor(), name, value);
}
enum LedStrength {
  STRENGTH_0 = 0,
  STRENGTH_25 = 1,
  STRENGTH_50 = 2,
  STRENGTH_100 = 3
};
bool LedStrength_IsValid(int value);
const LedStrength LedStrength_MIN = STRENGTH_0;
const LedStrength LedStrength_MAX = STRENGTH_100;
const int LedStrength_ARRAYSIZE = LedStrength_MAX + 1;

const ::google::protobuf::EnumDescriptor* LedStrength_descriptor();
inline const ::std::string& LedStrength_Name(LedStrength value) {
  return ::google::protobuf::internal::NameOfEnum(
    LedStrength_descriptor(), value);
}
inline bool LedStrength_Parse(
    const ::std::string& name, LedStrength* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LedStrength>(
    LedStrength_descriptor(), name, value);
}
// ===================================================================

class LedsConfig : public ::google::protobuf::Message {
 public:
  LedsConfig();
  virtual ~LedsConfig();

  LedsConfig(const LedsConfig& from);

  inline LedsConfig& operator=(const LedsConfig& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LedsConfig& default_instance();

  void Swap(LedsConfig* other);

  // implements Message ----------------------------------------------

  LedsConfig* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LedsConfig& from);
  void MergeFrom(const LedsConfig& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 commandID = 1;
  inline bool has_commandid() const;
  inline void clear_commandid();
  static const int kCommandIDFieldNumber = 1;
  inline ::google::protobuf::uint32 commandid() const;
  inline void set_commandid(::google::protobuf::uint32 value);

  // required float pwm1DutyCicle = 2;
  inline bool has_pwm1dutycicle() const;
  inline void clear_pwm1dutycicle();
  static const int kPwm1DutyCicleFieldNumber = 2;
  inline float pwm1dutycicle() const;
  inline void set_pwm1dutycicle(float value);

  // required float pwm2DutyCicle = 3;
  inline bool has_pwm2dutycicle() const;
  inline void clear_pwm2dutycicle();
  static const int kPwm2DutyCicleFieldNumber = 3;
  inline float pwm2dutycicle() const;
  inline void set_pwm2dutycicle(float value);

  // @@protoc_insertion_point(class_scope:LedsConfig)
 private:
  inline void set_has_commandid();
  inline void clear_has_commandid();
  inline void set_has_pwm1dutycicle();
  inline void clear_has_pwm1dutycicle();
  inline void set_has_pwm2dutycicle();
  inline void clear_has_pwm2dutycicle();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 commandid_;
  float pwm1dutycicle_;
  float pwm2dutycicle_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static LedsConfig* default_instance_;
};
// -------------------------------------------------------------------

class LedBlink : public ::google::protobuf::Message {
 public:
  LedBlink();
  virtual ~LedBlink();

  LedBlink(const LedBlink& from);

  inline LedBlink& operator=(const LedBlink& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LedBlink& default_instance();

  void Swap(LedBlink* other);

  // implements Message ----------------------------------------------

  LedBlink* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LedBlink& from);
  void MergeFrom(const LedBlink& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bool enable = 1;
  inline bool has_enable() const;
  inline void clear_enable();
  static const int kEnableFieldNumber = 1;
  inline bool enable() const;
  inline void set_enable(bool value);

  // optional .LedState state = 2;
  inline bool has_state() const;
  inline void clear_state();
  static const int kStateFieldNumber = 2;
  inline ::LedState state() const;
  inline void set_state(::LedState value);

  // optional uint32 timeOn = 3;
  inline bool has_timeon() const;
  inline void clear_timeon();
  static const int kTimeOnFieldNumber = 3;
  inline ::google::protobuf::uint32 timeon() const;
  inline void set_timeon(::google::protobuf::uint32 value);

  // optional uint32 timeOff = 4;
  inline bool has_timeoff() const;
  inline void clear_timeoff();
  static const int kTimeOffFieldNumber = 4;
  inline ::google::protobuf::uint32 timeoff() const;
  inline void set_timeoff(::google::protobuf::uint32 value);

  // optional uint32 numBlinks = 5;
  inline bool has_numblinks() const;
  inline void clear_numblinks();
  static const int kNumBlinksFieldNumber = 5;
  inline ::google::protobuf::uint32 numblinks() const;
  inline void set_numblinks(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:LedBlink)
 private:
  inline void set_has_enable();
  inline void clear_has_enable();
  inline void set_has_state();
  inline void clear_has_state();
  inline void set_has_timeon();
  inline void clear_has_timeon();
  inline void set_has_timeoff();
  inline void clear_has_timeoff();
  inline void set_has_numblinks();
  inline void clear_has_numblinks();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  bool enable_;
  int state_;
  ::google::protobuf::uint32 timeon_;
  ::google::protobuf::uint32 timeoff_;
  ::google::protobuf::uint32 numblinks_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static LedBlink* default_instance_;
};
// -------------------------------------------------------------------

class LedRgb : public ::google::protobuf::Message {
 public:
  LedRgb();
  virtual ~LedRgb();

  LedRgb(const LedRgb& from);

  inline LedRgb& operator=(const LedRgb& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LedRgb& default_instance();

  void Swap(LedRgb* other);

  // implements Message ----------------------------------------------

  LedRgb* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LedRgb& from);
  void MergeFrom(const LedRgb& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .LedNumber number = 1;
  inline bool has_number() const;
  inline void clear_number();
  static const int kNumberFieldNumber = 1;
  inline ::LedNumber number() const;
  inline void set_number(::LedNumber value);

  // required .LedStrength red = 2;
  inline bool has_red() const;
  inline void clear_red();
  static const int kRedFieldNumber = 2;
  inline ::LedStrength red() const;
  inline void set_red(::LedStrength value);

  // required .LedStrength green = 3;
  inline bool has_green() const;
  inline void clear_green();
  static const int kGreenFieldNumber = 3;
  inline ::LedStrength green() const;
  inline void set_green(::LedStrength value);

  // required .LedStrength blue = 4;
  inline bool has_blue() const;
  inline void clear_blue();
  static const int kBlueFieldNumber = 4;
  inline ::LedStrength blue() const;
  inline void set_blue(::LedStrength value);

  // optional .LedBlink blink = 5;
  inline bool has_blink() const;
  inline void clear_blink();
  static const int kBlinkFieldNumber = 5;
  inline const ::LedBlink& blink() const;
  inline ::LedBlink* mutable_blink();
  inline ::LedBlink* release_blink();
  inline void set_allocated_blink(::LedBlink* blink);

  // @@protoc_insertion_point(class_scope:LedRgb)
 private:
  inline void set_has_number();
  inline void clear_has_number();
  inline void set_has_red();
  inline void clear_has_red();
  inline void set_has_green();
  inline void clear_has_green();
  inline void set_has_blue();
  inline void clear_has_blue();
  inline void set_has_blink();
  inline void clear_has_blink();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  int number_;
  int red_;
  int green_;
  int blue_;
  ::LedBlink* blink_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static LedRgb* default_instance_;
};
// -------------------------------------------------------------------

class LedsValues : public ::google::protobuf::Message {
 public:
  LedsValues();
  virtual ~LedsValues();

  LedsValues(const LedsValues& from);

  inline LedsValues& operator=(const LedsValues& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LedsValues& default_instance();

  void Swap(LedsValues* other);

  // implements Message ----------------------------------------------

  LedsValues* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LedsValues& from);
  void MergeFrom(const LedsValues& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 commandID = 1;
  inline bool has_commandid() const;
  inline void clear_commandid();
  static const int kCommandIDFieldNumber = 1;
  inline ::google::protobuf::uint32 commandid() const;
  inline void set_commandid(::google::protobuf::uint32 value);

  // repeated .LedRgb leds = 2;
  inline int leds_size() const;
  inline void clear_leds();
  static const int kLedsFieldNumber = 2;
  inline const ::LedRgb& leds(int index) const;
  inline ::LedRgb* mutable_leds(int index);
  inline ::LedRgb* add_leds();
  inline const ::google::protobuf::RepeatedPtrField< ::LedRgb >&
      leds() const;
  inline ::google::protobuf::RepeatedPtrField< ::LedRgb >*
      mutable_leds();

  // @@protoc_insertion_point(class_scope:LedsValues)
 private:
  inline void set_has_commandid();
  inline void clear_has_commandid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::LedRgb > leds_;
  ::google::protobuf::uint32 commandid_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static LedsValues* default_instance_;
};
// -------------------------------------------------------------------

class LedStatusRequest : public ::google::protobuf::Message {
 public:
  LedStatusRequest();
  virtual ~LedStatusRequest();

  LedStatusRequest(const LedStatusRequest& from);

  inline LedStatusRequest& operator=(const LedStatusRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LedStatusRequest& default_instance();

  void Swap(LedStatusRequest* other);

  // implements Message ----------------------------------------------

  LedStatusRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LedStatusRequest& from);
  void MergeFrom(const LedStatusRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .LedNumber number = 1;
  inline bool has_number() const;
  inline void clear_number();
  static const int kNumberFieldNumber = 1;
  inline ::LedNumber number() const;
  inline void set_number(::LedNumber value);

  // optional bool sendBlink = 2;
  inline bool has_sendblink() const;
  inline void clear_sendblink();
  static const int kSendBlinkFieldNumber = 2;
  inline bool sendblink() const;
  inline void set_sendblink(bool value);

  // @@protoc_insertion_point(class_scope:LedStatusRequest)
 private:
  inline void set_has_number();
  inline void clear_has_number();
  inline void set_has_sendblink();
  inline void clear_has_sendblink();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  int number_;
  bool sendblink_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static LedStatusRequest* default_instance_;
};
// -------------------------------------------------------------------

class GetLedsStatus : public ::google::protobuf::Message {
 public:
  GetLedsStatus();
  virtual ~GetLedsStatus();

  GetLedsStatus(const GetLedsStatus& from);

  inline GetLedsStatus& operator=(const GetLedsStatus& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetLedsStatus& default_instance();

  void Swap(GetLedsStatus* other);

  // implements Message ----------------------------------------------

  GetLedsStatus* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetLedsStatus& from);
  void MergeFrom(const GetLedsStatus& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 commandID = 1;
  inline bool has_commandid() const;
  inline void clear_commandid();
  static const int kCommandIDFieldNumber = 1;
  inline ::google::protobuf::uint32 commandid() const;
  inline void set_commandid(::google::protobuf::uint32 value);

  // repeated .LedStatusRequest leds = 2;
  inline int leds_size() const;
  inline void clear_leds();
  static const int kLedsFieldNumber = 2;
  inline const ::LedStatusRequest& leds(int index) const;
  inline ::LedStatusRequest* mutable_leds(int index);
  inline ::LedStatusRequest* add_leds();
  inline const ::google::protobuf::RepeatedPtrField< ::LedStatusRequest >&
      leds() const;
  inline ::google::protobuf::RepeatedPtrField< ::LedStatusRequest >*
      mutable_leds();

  // @@protoc_insertion_point(class_scope:GetLedsStatus)
 private:
  inline void set_has_commandid();
  inline void clear_has_commandid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::LedStatusRequest > leds_;
  ::google::protobuf::uint32 commandid_;
  friend void  protobuf_AddDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_AssignDesc_Protocol_5fLeds_2eproto();
  friend void protobuf_ShutdownFile_Protocol_5fLeds_2eproto();

  void InitAsDefaultInstance();
  static GetLedsStatus* default_instance_;
};
// ===================================================================


// ===================================================================

// LedsConfig

// required uint32 commandID = 1;
inline bool LedsConfig::has_commandid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LedsConfig::set_has_commandid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LedsConfig::clear_has_commandid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LedsConfig::clear_commandid() {
  commandid_ = 0u;
  clear_has_commandid();
}
inline ::google::protobuf::uint32 LedsConfig::commandid() const {
  // @@protoc_insertion_point(field_get:LedsConfig.commandID)
  return commandid_;
}
inline void LedsConfig::set_commandid(::google::protobuf::uint32 value) {
  set_has_commandid();
  commandid_ = value;
  // @@protoc_insertion_point(field_set:LedsConfig.commandID)
}

// required float pwm1DutyCicle = 2;
inline bool LedsConfig::has_pwm1dutycicle() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LedsConfig::set_has_pwm1dutycicle() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LedsConfig::clear_has_pwm1dutycicle() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LedsConfig::clear_pwm1dutycicle() {
  pwm1dutycicle_ = 0;
  clear_has_pwm1dutycicle();
}
inline float LedsConfig::pwm1dutycicle() const {
  // @@protoc_insertion_point(field_get:LedsConfig.pwm1DutyCicle)
  return pwm1dutycicle_;
}
inline void LedsConfig::set_pwm1dutycicle(float value) {
  set_has_pwm1dutycicle();
  pwm1dutycicle_ = value;
  // @@protoc_insertion_point(field_set:LedsConfig.pwm1DutyCicle)
}

// required float pwm2DutyCicle = 3;
inline bool LedsConfig::has_pwm2dutycicle() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LedsConfig::set_has_pwm2dutycicle() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LedsConfig::clear_has_pwm2dutycicle() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LedsConfig::clear_pwm2dutycicle() {
  pwm2dutycicle_ = 0;
  clear_has_pwm2dutycicle();
}
inline float LedsConfig::pwm2dutycicle() const {
  // @@protoc_insertion_point(field_get:LedsConfig.pwm2DutyCicle)
  return pwm2dutycicle_;
}
inline void LedsConfig::set_pwm2dutycicle(float value) {
  set_has_pwm2dutycicle();
  pwm2dutycicle_ = value;
  // @@protoc_insertion_point(field_set:LedsConfig.pwm2DutyCicle)
}

// -------------------------------------------------------------------

// LedBlink

// required bool enable = 1;
inline bool LedBlink::has_enable() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LedBlink::set_has_enable() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LedBlink::clear_has_enable() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LedBlink::clear_enable() {
  enable_ = false;
  clear_has_enable();
}
inline bool LedBlink::enable() const {
  // @@protoc_insertion_point(field_get:LedBlink.enable)
  return enable_;
}
inline void LedBlink::set_enable(bool value) {
  set_has_enable();
  enable_ = value;
  // @@protoc_insertion_point(field_set:LedBlink.enable)
}

// optional .LedState state = 2;
inline bool LedBlink::has_state() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LedBlink::set_has_state() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LedBlink::clear_has_state() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LedBlink::clear_state() {
  state_ = 0;
  clear_has_state();
}
inline ::LedState LedBlink::state() const {
  // @@protoc_insertion_point(field_get:LedBlink.state)
  return static_cast< ::LedState >(state_);
}
inline void LedBlink::set_state(::LedState value) {
  assert(::LedState_IsValid(value));
  set_has_state();
  state_ = value;
  // @@protoc_insertion_point(field_set:LedBlink.state)
}

// optional uint32 timeOn = 3;
inline bool LedBlink::has_timeon() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LedBlink::set_has_timeon() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LedBlink::clear_has_timeon() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LedBlink::clear_timeon() {
  timeon_ = 0u;
  clear_has_timeon();
}
inline ::google::protobuf::uint32 LedBlink::timeon() const {
  // @@protoc_insertion_point(field_get:LedBlink.timeOn)
  return timeon_;
}
inline void LedBlink::set_timeon(::google::protobuf::uint32 value) {
  set_has_timeon();
  timeon_ = value;
  // @@protoc_insertion_point(field_set:LedBlink.timeOn)
}

// optional uint32 timeOff = 4;
inline bool LedBlink::has_timeoff() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void LedBlink::set_has_timeoff() {
  _has_bits_[0] |= 0x00000008u;
}
inline void LedBlink::clear_has_timeoff() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void LedBlink::clear_timeoff() {
  timeoff_ = 0u;
  clear_has_timeoff();
}
inline ::google::protobuf::uint32 LedBlink::timeoff() const {
  // @@protoc_insertion_point(field_get:LedBlink.timeOff)
  return timeoff_;
}
inline void LedBlink::set_timeoff(::google::protobuf::uint32 value) {
  set_has_timeoff();
  timeoff_ = value;
  // @@protoc_insertion_point(field_set:LedBlink.timeOff)
}

// optional uint32 numBlinks = 5;
inline bool LedBlink::has_numblinks() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void LedBlink::set_has_numblinks() {
  _has_bits_[0] |= 0x00000010u;
}
inline void LedBlink::clear_has_numblinks() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void LedBlink::clear_numblinks() {
  numblinks_ = 0u;
  clear_has_numblinks();
}
inline ::google::protobuf::uint32 LedBlink::numblinks() const {
  // @@protoc_insertion_point(field_get:LedBlink.numBlinks)
  return numblinks_;
}
inline void LedBlink::set_numblinks(::google::protobuf::uint32 value) {
  set_has_numblinks();
  numblinks_ = value;
  // @@protoc_insertion_point(field_set:LedBlink.numBlinks)
}

// -------------------------------------------------------------------

// LedRgb

// required .LedNumber number = 1;
inline bool LedRgb::has_number() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LedRgb::set_has_number() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LedRgb::clear_has_number() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LedRgb::clear_number() {
  number_ = 0;
  clear_has_number();
}
inline ::LedNumber LedRgb::number() const {
  // @@protoc_insertion_point(field_get:LedRgb.number)
  return static_cast< ::LedNumber >(number_);
}
inline void LedRgb::set_number(::LedNumber value) {
  assert(::LedNumber_IsValid(value));
  set_has_number();
  number_ = value;
  // @@protoc_insertion_point(field_set:LedRgb.number)
}

// required .LedStrength red = 2;
inline bool LedRgb::has_red() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LedRgb::set_has_red() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LedRgb::clear_has_red() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LedRgb::clear_red() {
  red_ = 0;
  clear_has_red();
}
inline ::LedStrength LedRgb::red() const {
  // @@protoc_insertion_point(field_get:LedRgb.red)
  return static_cast< ::LedStrength >(red_);
}
inline void LedRgb::set_red(::LedStrength value) {
  assert(::LedStrength_IsValid(value));
  set_has_red();
  red_ = value;
  // @@protoc_insertion_point(field_set:LedRgb.red)
}

// required .LedStrength green = 3;
inline bool LedRgb::has_green() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LedRgb::set_has_green() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LedRgb::clear_has_green() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LedRgb::clear_green() {
  green_ = 0;
  clear_has_green();
}
inline ::LedStrength LedRgb::green() const {
  // @@protoc_insertion_point(field_get:LedRgb.green)
  return static_cast< ::LedStrength >(green_);
}
inline void LedRgb::set_green(::LedStrength value) {
  assert(::LedStrength_IsValid(value));
  set_has_green();
  green_ = value;
  // @@protoc_insertion_point(field_set:LedRgb.green)
}

// required .LedStrength blue = 4;
inline bool LedRgb::has_blue() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void LedRgb::set_has_blue() {
  _has_bits_[0] |= 0x00000008u;
}
inline void LedRgb::clear_has_blue() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void LedRgb::clear_blue() {
  blue_ = 0;
  clear_has_blue();
}
inline ::LedStrength LedRgb::blue() const {
  // @@protoc_insertion_point(field_get:LedRgb.blue)
  return static_cast< ::LedStrength >(blue_);
}
inline void LedRgb::set_blue(::LedStrength value) {
  assert(::LedStrength_IsValid(value));
  set_has_blue();
  blue_ = value;
  // @@protoc_insertion_point(field_set:LedRgb.blue)
}

// optional .LedBlink blink = 5;
inline bool LedRgb::has_blink() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void LedRgb::set_has_blink() {
  _has_bits_[0] |= 0x00000010u;
}
inline void LedRgb::clear_has_blink() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void LedRgb::clear_blink() {
  if (blink_ != NULL) blink_->::LedBlink::Clear();
  clear_has_blink();
}
inline const ::LedBlink& LedRgb::blink() const {
  // @@protoc_insertion_point(field_get:LedRgb.blink)
  return blink_ != NULL ? *blink_ : *default_instance_->blink_;
}
inline ::LedBlink* LedRgb::mutable_blink() {
  set_has_blink();
  if (blink_ == NULL) blink_ = new ::LedBlink;
  // @@protoc_insertion_point(field_mutable:LedRgb.blink)
  return blink_;
}
inline ::LedBlink* LedRgb::release_blink() {
  clear_has_blink();
  ::LedBlink* temp = blink_;
  blink_ = NULL;
  return temp;
}
inline void LedRgb::set_allocated_blink(::LedBlink* blink) {
  delete blink_;
  blink_ = blink;
  if (blink) {
    set_has_blink();
  } else {
    clear_has_blink();
  }
  // @@protoc_insertion_point(field_set_allocated:LedRgb.blink)
}

// -------------------------------------------------------------------

// LedsValues

// required uint32 commandID = 1;
inline bool LedsValues::has_commandid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LedsValues::set_has_commandid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LedsValues::clear_has_commandid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LedsValues::clear_commandid() {
  commandid_ = 0u;
  clear_has_commandid();
}
inline ::google::protobuf::uint32 LedsValues::commandid() const {
  // @@protoc_insertion_point(field_get:LedsValues.commandID)
  return commandid_;
}
inline void LedsValues::set_commandid(::google::protobuf::uint32 value) {
  set_has_commandid();
  commandid_ = value;
  // @@protoc_insertion_point(field_set:LedsValues.commandID)
}

// repeated .LedRgb leds = 2;
inline int LedsValues::leds_size() const {
  return leds_.size();
}
inline void LedsValues::clear_leds() {
  leds_.Clear();
}
inline const ::LedRgb& LedsValues::leds(int index) const {
  // @@protoc_insertion_point(field_get:LedsValues.leds)
  return leds_.Get(index);
}
inline ::LedRgb* LedsValues::mutable_leds(int index) {
  // @@protoc_insertion_point(field_mutable:LedsValues.leds)
  return leds_.Mutable(index);
}
inline ::LedRgb* LedsValues::add_leds() {
  // @@protoc_insertion_point(field_add:LedsValues.leds)
  return leds_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::LedRgb >&
LedsValues::leds() const {
  // @@protoc_insertion_point(field_list:LedsValues.leds)
  return leds_;
}
inline ::google::protobuf::RepeatedPtrField< ::LedRgb >*
LedsValues::mutable_leds() {
  // @@protoc_insertion_point(field_mutable_list:LedsValues.leds)
  return &leds_;
}

// -------------------------------------------------------------------

// LedStatusRequest

// required .LedNumber number = 1;
inline bool LedStatusRequest::has_number() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LedStatusRequest::set_has_number() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LedStatusRequest::clear_has_number() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LedStatusRequest::clear_number() {
  number_ = 0;
  clear_has_number();
}
inline ::LedNumber LedStatusRequest::number() const {
  // @@protoc_insertion_point(field_get:LedStatusRequest.number)
  return static_cast< ::LedNumber >(number_);
}
inline void LedStatusRequest::set_number(::LedNumber value) {
  assert(::LedNumber_IsValid(value));
  set_has_number();
  number_ = value;
  // @@protoc_insertion_point(field_set:LedStatusRequest.number)
}

// optional bool sendBlink = 2;
inline bool LedStatusRequest::has_sendblink() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LedStatusRequest::set_has_sendblink() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LedStatusRequest::clear_has_sendblink() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LedStatusRequest::clear_sendblink() {
  sendblink_ = false;
  clear_has_sendblink();
}
inline bool LedStatusRequest::sendblink() const {
  // @@protoc_insertion_point(field_get:LedStatusRequest.sendBlink)
  return sendblink_;
}
inline void LedStatusRequest::set_sendblink(bool value) {
  set_has_sendblink();
  sendblink_ = value;
  // @@protoc_insertion_point(field_set:LedStatusRequest.sendBlink)
}

// -------------------------------------------------------------------

// GetLedsStatus

// required uint32 commandID = 1;
inline bool GetLedsStatus::has_commandid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetLedsStatus::set_has_commandid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetLedsStatus::clear_has_commandid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetLedsStatus::clear_commandid() {
  commandid_ = 0u;
  clear_has_commandid();
}
inline ::google::protobuf::uint32 GetLedsStatus::commandid() const {
  // @@protoc_insertion_point(field_get:GetLedsStatus.commandID)
  return commandid_;
}
inline void GetLedsStatus::set_commandid(::google::protobuf::uint32 value) {
  set_has_commandid();
  commandid_ = value;
  // @@protoc_insertion_point(field_set:GetLedsStatus.commandID)
}

// repeated .LedStatusRequest leds = 2;
inline int GetLedsStatus::leds_size() const {
  return leds_.size();
}
inline void GetLedsStatus::clear_leds() {
  leds_.Clear();
}
inline const ::LedStatusRequest& GetLedsStatus::leds(int index) const {
  // @@protoc_insertion_point(field_get:GetLedsStatus.leds)
  return leds_.Get(index);
}
inline ::LedStatusRequest* GetLedsStatus::mutable_leds(int index) {
  // @@protoc_insertion_point(field_mutable:GetLedsStatus.leds)
  return leds_.Mutable(index);
}
inline ::LedStatusRequest* GetLedsStatus::add_leds() {
  // @@protoc_insertion_point(field_add:GetLedsStatus.leds)
  return leds_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::LedStatusRequest >&
GetLedsStatus::leds() const {
  // @@protoc_insertion_point(field_list:GetLedsStatus.leds)
  return leds_;
}
inline ::google::protobuf::RepeatedPtrField< ::LedStatusRequest >*
GetLedsStatus::mutable_leds() {
  // @@protoc_insertion_point(field_mutable_list:GetLedsStatus.leds)
  return &leds_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::LedNumber> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::LedNumber>() {
  return ::LedNumber_descriptor();
}
template <> struct is_proto_enum< ::LedState> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::LedState>() {
  return ::LedState_descriptor();
}
template <> struct is_proto_enum< ::LedStrength> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::LedStrength>() {
  return ::LedStrength_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Protocol_5fLeds_2eproto__INCLUDED
