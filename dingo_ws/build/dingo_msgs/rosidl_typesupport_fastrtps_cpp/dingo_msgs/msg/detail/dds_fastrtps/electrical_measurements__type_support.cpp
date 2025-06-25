// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice
#include "dingo_msgs/msg/detail/electrical_measurements__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dingo_msgs/msg/detail/electrical_measurements__functions.h"
#include "dingo_msgs/msg/detail/electrical_measurements__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace dingo_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
cdr_serialize(
  const dingo_msgs::msg::ElectricalMeasurements & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery_voltage_level
  cdr << ros_message.battery_voltage_level;

  // Member: servo_buck_voltage_level
  cdr << ros_message.servo_buck_voltage_level;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dingo_msgs::msg::ElectricalMeasurements & ros_message)
{
  // Member: battery_voltage_level
  cdr >> ros_message.battery_voltage_level;

  // Member: servo_buck_voltage_level
  cdr >> ros_message.servo_buck_voltage_level;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
get_serialized_size(
  const dingo_msgs::msg::ElectricalMeasurements & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery_voltage_level
  {
    size_t item_size = sizeof(ros_message.battery_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: servo_buck_voltage_level
  {
    size_t item_size = sizeof(ros_message.servo_buck_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
max_serialized_size_ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: battery_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: servo_buck_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_msgs::msg::ElectricalMeasurements;
    is_plain =
      (
      offsetof(DataType, servo_buck_voltage_level) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
cdr_serialize_key(
  const dingo_msgs::msg::ElectricalMeasurements & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery_voltage_level
  cdr << ros_message.battery_voltage_level;

  // Member: servo_buck_voltage_level
  cdr << ros_message.servo_buck_voltage_level;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
get_serialized_size_key(
  const dingo_msgs::msg::ElectricalMeasurements & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery_voltage_level
  {
    size_t item_size = sizeof(ros_message.battery_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: servo_buck_voltage_level
  {
    size_t item_size = sizeof(ros_message.servo_buck_voltage_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dingo_msgs
max_serialized_size_key_ElectricalMeasurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: battery_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: servo_buck_voltage_level
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dingo_msgs::msg::ElectricalMeasurements;
    is_plain =
      (
      offsetof(DataType, servo_buck_voltage_level) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _ElectricalMeasurements__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dingo_msgs::msg::ElectricalMeasurements *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ElectricalMeasurements__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dingo_msgs::msg::ElectricalMeasurements *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ElectricalMeasurements__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dingo_msgs::msg::ElectricalMeasurements *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ElectricalMeasurements__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ElectricalMeasurements(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ElectricalMeasurements__callbacks = {
  "dingo_msgs::msg",
  "ElectricalMeasurements",
  _ElectricalMeasurements__cdr_serialize,
  _ElectricalMeasurements__cdr_deserialize,
  _ElectricalMeasurements__get_serialized_size,
  _ElectricalMeasurements__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ElectricalMeasurements__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ElectricalMeasurements__callbacks,
  get_message_typesupport_handle_function,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_hash,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_description,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dingo_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dingo_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<dingo_msgs::msg::ElectricalMeasurements>()
{
  return &dingo_msgs::msg::typesupport_fastrtps_cpp::_ElectricalMeasurements__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dingo_msgs, msg, ElectricalMeasurements)() {
  return &dingo_msgs::msg::typesupport_fastrtps_cpp::_ElectricalMeasurements__handle;
}

#ifdef __cplusplus
}
#endif
