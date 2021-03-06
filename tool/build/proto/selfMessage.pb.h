// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: selfMessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_selfMessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_selfMessage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/any.pb.h>
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_selfMessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_selfMessage_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_selfMessage_2eproto;
namespace test {
class SelfDescribingMessage;
class SelfDescribingMessageDefaultTypeInternal;
extern SelfDescribingMessageDefaultTypeInternal _SelfDescribingMessage_default_instance_;
}  // namespace test
PROTOBUF_NAMESPACE_OPEN
template<> ::test::SelfDescribingMessage* Arena::CreateMaybeMessage<::test::SelfDescribingMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace test {

// ===================================================================

class SelfDescribingMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test.SelfDescribingMessage) */ {
 public:
  SelfDescribingMessage();
  virtual ~SelfDescribingMessage();

  SelfDescribingMessage(const SelfDescribingMessage& from);
  SelfDescribingMessage(SelfDescribingMessage&& from) noexcept
    : SelfDescribingMessage() {
    *this = ::std::move(from);
  }

  inline SelfDescribingMessage& operator=(const SelfDescribingMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline SelfDescribingMessage& operator=(SelfDescribingMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SelfDescribingMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SelfDescribingMessage* internal_default_instance() {
    return reinterpret_cast<const SelfDescribingMessage*>(
               &_SelfDescribingMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SelfDescribingMessage& a, SelfDescribingMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(SelfDescribingMessage* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SelfDescribingMessage* New() const final {
    return CreateMaybeMessage<SelfDescribingMessage>(nullptr);
  }

  SelfDescribingMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SelfDescribingMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SelfDescribingMessage& from);
  void MergeFrom(const SelfDescribingMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SelfDescribingMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test.SelfDescribingMessage";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_selfMessage_2eproto);
    return ::descriptor_table_selfMessage_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDescriptorSetFieldNumber = 1,
    kMessageFieldNumber = 2,
  };
  // optional .google.protobuf.FileDescriptorSet descriptor_set = 1;
  bool has_descriptor_set() const;
  private:
  bool _internal_has_descriptor_set() const;
  public:
  void clear_descriptor_set();
  const PROTOBUF_NAMESPACE_ID::FileDescriptorSet& descriptor_set() const;
  PROTOBUF_NAMESPACE_ID::FileDescriptorSet* release_descriptor_set();
  PROTOBUF_NAMESPACE_ID::FileDescriptorSet* mutable_descriptor_set();
  void set_allocated_descriptor_set(PROTOBUF_NAMESPACE_ID::FileDescriptorSet* descriptor_set);
  private:
  const PROTOBUF_NAMESPACE_ID::FileDescriptorSet& _internal_descriptor_set() const;
  PROTOBUF_NAMESPACE_ID::FileDescriptorSet* _internal_mutable_descriptor_set();
  public:

  // optional .google.protobuf.Any message = 2;
  bool has_message() const;
  private:
  bool _internal_has_message() const;
  public:
  void clear_message();
  const PROTOBUF_NAMESPACE_ID::Any& message() const;
  PROTOBUF_NAMESPACE_ID::Any* release_message();
  PROTOBUF_NAMESPACE_ID::Any* mutable_message();
  void set_allocated_message(PROTOBUF_NAMESPACE_ID::Any* message);
  private:
  const PROTOBUF_NAMESPACE_ID::Any& _internal_message() const;
  PROTOBUF_NAMESPACE_ID::Any* _internal_mutable_message();
  public:

  // @@protoc_insertion_point(class_scope:test.SelfDescribingMessage)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  PROTOBUF_NAMESPACE_ID::FileDescriptorSet* descriptor_set_;
  PROTOBUF_NAMESPACE_ID::Any* message_;
  friend struct ::TableStruct_selfMessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SelfDescribingMessage

// optional .google.protobuf.FileDescriptorSet descriptor_set = 1;
inline bool SelfDescribingMessage::_internal_has_descriptor_set() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || descriptor_set_ != nullptr);
  return value;
}
inline bool SelfDescribingMessage::has_descriptor_set() const {
  return _internal_has_descriptor_set();
}
inline const PROTOBUF_NAMESPACE_ID::FileDescriptorSet& SelfDescribingMessage::_internal_descriptor_set() const {
  const PROTOBUF_NAMESPACE_ID::FileDescriptorSet* p = descriptor_set_;
  return p != nullptr ? *p : *reinterpret_cast<const PROTOBUF_NAMESPACE_ID::FileDescriptorSet*>(
      &PROTOBUF_NAMESPACE_ID::_FileDescriptorSet_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::FileDescriptorSet& SelfDescribingMessage::descriptor_set() const {
  // @@protoc_insertion_point(field_get:test.SelfDescribingMessage.descriptor_set)
  return _internal_descriptor_set();
}
inline PROTOBUF_NAMESPACE_ID::FileDescriptorSet* SelfDescribingMessage::release_descriptor_set() {
  // @@protoc_insertion_point(field_release:test.SelfDescribingMessage.descriptor_set)
  _has_bits_[0] &= ~0x00000001u;
  PROTOBUF_NAMESPACE_ID::FileDescriptorSet* temp = descriptor_set_;
  descriptor_set_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::FileDescriptorSet* SelfDescribingMessage::_internal_mutable_descriptor_set() {
  _has_bits_[0] |= 0x00000001u;
  if (descriptor_set_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::FileDescriptorSet>(GetArenaNoVirtual());
    descriptor_set_ = p;
  }
  return descriptor_set_;
}
inline PROTOBUF_NAMESPACE_ID::FileDescriptorSet* SelfDescribingMessage::mutable_descriptor_set() {
  // @@protoc_insertion_point(field_mutable:test.SelfDescribingMessage.descriptor_set)
  return _internal_mutable_descriptor_set();
}
inline void SelfDescribingMessage::set_allocated_descriptor_set(PROTOBUF_NAMESPACE_ID::FileDescriptorSet* descriptor_set) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(descriptor_set_);
  }
  if (descriptor_set) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(descriptor_set)->GetArena();
    if (message_arena != submessage_arena) {
      descriptor_set = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, descriptor_set, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  descriptor_set_ = descriptor_set;
  // @@protoc_insertion_point(field_set_allocated:test.SelfDescribingMessage.descriptor_set)
}

// optional .google.protobuf.Any message = 2;
inline bool SelfDescribingMessage::_internal_has_message() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || message_ != nullptr);
  return value;
}
inline bool SelfDescribingMessage::has_message() const {
  return _internal_has_message();
}
inline const PROTOBUF_NAMESPACE_ID::Any& SelfDescribingMessage::_internal_message() const {
  const PROTOBUF_NAMESPACE_ID::Any* p = message_;
  return p != nullptr ? *p : *reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Any*>(
      &PROTOBUF_NAMESPACE_ID::_Any_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Any& SelfDescribingMessage::message() const {
  // @@protoc_insertion_point(field_get:test.SelfDescribingMessage.message)
  return _internal_message();
}
inline PROTOBUF_NAMESPACE_ID::Any* SelfDescribingMessage::release_message() {
  // @@protoc_insertion_point(field_release:test.SelfDescribingMessage.message)
  _has_bits_[0] &= ~0x00000002u;
  PROTOBUF_NAMESPACE_ID::Any* temp = message_;
  message_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Any* SelfDescribingMessage::_internal_mutable_message() {
  _has_bits_[0] |= 0x00000002u;
  if (message_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Any>(GetArenaNoVirtual());
    message_ = p;
  }
  return message_;
}
inline PROTOBUF_NAMESPACE_ID::Any* SelfDescribingMessage::mutable_message() {
  // @@protoc_insertion_point(field_mutable:test.SelfDescribingMessage.message)
  return _internal_mutable_message();
}
inline void SelfDescribingMessage::set_allocated_message(PROTOBUF_NAMESPACE_ID::Any* message) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(message_);
  }
  if (message) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      message = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, message, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  message_ = message;
  // @@protoc_insertion_point(field_set_allocated:test.SelfDescribingMessage.message)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_selfMessage_2eproto
