// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_msgs:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/task_space.h"


#ifndef DINGO_MSGS__MSG__DETAIL__TASK_SPACE__STRUCT_H_
#define DINGO_MSGS__MSG__DETAIL__TASK_SPACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'fl_foot'
// Member 'fr_foot'
// Member 'rl_foot'
// Member 'rr_foot'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/TaskSpace in the package dingo_msgs.
/**
  * TaskSpace.msg
 */
typedef struct dingo_msgs__msg__TaskSpace
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point fl_foot;
  geometry_msgs__msg__Point fr_foot;
  geometry_msgs__msg__Point rl_foot;
  geometry_msgs__msg__Point rr_foot;
} dingo_msgs__msg__TaskSpace;

// Struct for a sequence of dingo_msgs__msg__TaskSpace.
typedef struct dingo_msgs__msg__TaskSpace__Sequence
{
  dingo_msgs__msg__TaskSpace * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_msgs__msg__TaskSpace__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_MSGS__MSG__DETAIL__TASK_SPACE__STRUCT_H_
