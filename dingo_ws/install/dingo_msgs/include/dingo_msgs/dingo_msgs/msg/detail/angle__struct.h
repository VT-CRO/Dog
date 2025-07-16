// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/angle.h"


#ifndef DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_H_
#define DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Angle in the package dingo_msgs.
typedef struct dingo_msgs__msg__Angle
{
  float theta1;
  float theta2;
  float theta3;
} dingo_msgs__msg__Angle;

// Struct for a sequence of dingo_msgs__msg__Angle.
typedef struct dingo_msgs__msg__Angle__Sequence
{
  dingo_msgs__msg__Angle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_msgs__msg__Angle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_H_
