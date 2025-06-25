// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice
#include "dingo_msgs/msg/detail/angle__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dingo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_msgs/msg/detail/angle__struct.h"
#include "dingo_msgs/msg/detail/angle__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Angle__ros_msg_type = dingo_msgs__msg__Angle;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_serialize_dingo_msgs__msg__Angle(
  const dingo_msgs__msg__Angle * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: theta1
  {
    cdr << ros_message->theta1;
  }

  // Field name: theta2
  {
    cdr << ros_message->theta2;
  }

  // Field name: theta3
  {
    cdr << ros_message->theta3;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_deserialize_dingo_msgs__msg__Angle(
  eprosima::fastcdr::Cdr & cdr,
  dingo_msgs__msg__Angle * ros_message)
{
  // Field name: theta1
  {
    cdr >> ros_message->theta1;
  }

  // Field name: theta2
  {
    cdr >> ros_message->theta2;
  }

  // Field name: theta3
  {
    cdr >> ros_message->theta3;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t get_serialized_size_dingo_msgs__msg__Angle(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Angle__ros_msg_type * ros_message = static_cast<const _Angle__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: theta1
  {
    size_t item_size = sizeof(ros_message->theta1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta2
  {
    size_t item_size = sizeof(ros_message->theta2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta3
  {
    size_t item_size = sizeof(ros_message->theta3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t max_serialized_size_dingo_msgs__msg__Angle(
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

  // Field name: theta1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: theta2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: theta3
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
    using DataType = dingo_msgs__msg__Angle;
    is_plain =
      (
      offsetof(DataType, theta3) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_serialize_key_dingo_msgs__msg__Angle(
  const dingo_msgs__msg__Angle * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: theta1
  {
    cdr << ros_message->theta1;
  }

  // Field name: theta2
  {
    cdr << ros_message->theta2;
  }

  // Field name: theta3
  {
    cdr << ros_message->theta3;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t get_serialized_size_key_dingo_msgs__msg__Angle(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Angle__ros_msg_type * ros_message = static_cast<const _Angle__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: theta1
  {
    size_t item_size = sizeof(ros_message->theta1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta2
  {
    size_t item_size = sizeof(ros_message->theta2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta3
  {
    size_t item_size = sizeof(ros_message->theta3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t max_serialized_size_key_dingo_msgs__msg__Angle(
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
  // Field name: theta1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: theta2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: theta3
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
    using DataType = dingo_msgs__msg__Angle;
    is_plain =
      (
      offsetof(DataType, theta3) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Angle__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dingo_msgs__msg__Angle * ros_message = static_cast<const dingo_msgs__msg__Angle *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dingo_msgs__msg__Angle(ros_message, cdr);
}

static bool _Angle__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dingo_msgs__msg__Angle * ros_message = static_cast<dingo_msgs__msg__Angle *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dingo_msgs__msg__Angle(cdr, ros_message);
}

static uint32_t _Angle__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dingo_msgs__msg__Angle(
      untyped_ros_message, 0));
}

static size_t _Angle__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dingo_msgs__msg__Angle(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Angle = {
  "dingo_msgs::msg",
  "Angle",
  _Angle__cdr_serialize,
  _Angle__cdr_deserialize,
  _Angle__get_serialized_size,
  _Angle__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Angle__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Angle,
  get_message_typesupport_handle_function,
  &dingo_msgs__msg__Angle__get_type_hash,
  &dingo_msgs__msg__Angle__get_type_description,
  &dingo_msgs__msg__Angle__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_msgs, msg, Angle)() {
  return &_Angle__type_support;
}

#if defined(__cplusplus)
}
#endif
