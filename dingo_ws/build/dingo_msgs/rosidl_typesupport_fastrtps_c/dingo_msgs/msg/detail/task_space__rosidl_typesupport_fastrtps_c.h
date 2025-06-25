// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from dingo_msgs:msg/TaskSpace.idl
// generated code does not contain a copyright notice
#ifndef DINGO_MSGS__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define DINGO_MSGS__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dingo_msgs/msg/detail/task_space__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_serialize_dingo_msgs__msg__TaskSpace(
  const dingo_msgs__msg__TaskSpace * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_deserialize_dingo_msgs__msg__TaskSpace(
  eprosima::fastcdr::Cdr &,
  dingo_msgs__msg__TaskSpace * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t get_serialized_size_dingo_msgs__msg__TaskSpace(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t max_serialized_size_dingo_msgs__msg__TaskSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
bool cdr_serialize_key_dingo_msgs__msg__TaskSpace(
  const dingo_msgs__msg__TaskSpace * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t get_serialized_size_key_dingo_msgs__msg__TaskSpace(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
size_t max_serialized_size_key_dingo_msgs__msg__TaskSpace(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dingo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dingo_msgs, msg, TaskSpace)();

#ifdef __cplusplus
}
#endif

#endif  // DINGO_MSGS__MSG__DETAIL__TASK_SPACE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
