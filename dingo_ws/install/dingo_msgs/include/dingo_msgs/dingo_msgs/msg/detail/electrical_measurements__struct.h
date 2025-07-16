// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/electrical_measurements.h"


#ifndef DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_H_
#define DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ElectricalMeasurements in the package dingo_msgs.
typedef struct dingo_msgs__msg__ElectricalMeasurements
{
  float battery_voltage_level;
  float servo_buck_voltage_level;
} dingo_msgs__msg__ElectricalMeasurements;

// Struct for a sequence of dingo_msgs__msg__ElectricalMeasurements.
typedef struct dingo_msgs__msg__ElectricalMeasurements__Sequence
{
  dingo_msgs__msg__ElectricalMeasurements * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dingo_msgs__msg__ElectricalMeasurements__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_H_
