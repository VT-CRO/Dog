// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

#include "dingo_msgs/msg/detail/electrical_measurements__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_type_hash_t *
dingo_msgs__msg__ElectricalMeasurements__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf3, 0x75, 0x90, 0xc3, 0x2b, 0x4d, 0x96, 0xc3,
      0x44, 0xf6, 0xc9, 0xa7, 0xb4, 0x33, 0x71, 0x91,
      0x17, 0x84, 0x7f, 0x24, 0x80, 0x77, 0xa2, 0x23,
      0x7f, 0xe8, 0xcf, 0xe0, 0x43, 0x8c, 0x87, 0xe6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dingo_msgs__msg__ElectricalMeasurements__TYPE_NAME[] = "dingo_msgs/msg/ElectricalMeasurements";

// Define type names, field names, and default values
static char dingo_msgs__msg__ElectricalMeasurements__FIELD_NAME__battery_voltage_level[] = "battery_voltage_level";
static char dingo_msgs__msg__ElectricalMeasurements__FIELD_NAME__servo_buck_voltage_level[] = "servo_buck_voltage_level";

static rosidl_runtime_c__type_description__Field dingo_msgs__msg__ElectricalMeasurements__FIELDS[] = {
  {
    {dingo_msgs__msg__ElectricalMeasurements__FIELD_NAME__battery_voltage_level, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_msgs__msg__ElectricalMeasurements__FIELD_NAME__servo_buck_voltage_level, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dingo_msgs__msg__ElectricalMeasurements__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_msgs__msg__ElectricalMeasurements__TYPE_NAME, 37, 37},
      {dingo_msgs__msg__ElectricalMeasurements__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 battery_voltage_level\n"
  "float32 servo_buck_voltage_level";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_msgs__msg__ElectricalMeasurements__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_msgs__msg__ElectricalMeasurements__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_msgs__msg__ElectricalMeasurements__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_msgs__msg__ElectricalMeasurements__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
