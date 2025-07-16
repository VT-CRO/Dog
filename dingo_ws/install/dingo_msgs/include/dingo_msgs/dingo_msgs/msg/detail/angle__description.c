// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice

#include "dingo_msgs/msg/detail/angle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_type_hash_t *
dingo_msgs__msg__Angle__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcf, 0x0f, 0xd8, 0x92, 0xf5, 0xbe, 0x31, 0xdc,
      0xf4, 0x8e, 0x0b, 0x1f, 0x7c, 0xa5, 0x8f, 0xd1,
      0x01, 0x48, 0x2d, 0x90, 0xe2, 0x26, 0xcf, 0x64,
      0x4f, 0x69, 0xbb, 0xa6, 0xb8, 0x80, 0x34, 0x84,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dingo_msgs__msg__Angle__TYPE_NAME[] = "dingo_msgs/msg/Angle";

// Define type names, field names, and default values
static char dingo_msgs__msg__Angle__FIELD_NAME__theta1[] = "theta1";
static char dingo_msgs__msg__Angle__FIELD_NAME__theta2[] = "theta2";
static char dingo_msgs__msg__Angle__FIELD_NAME__theta3[] = "theta3";

static rosidl_runtime_c__type_description__Field dingo_msgs__msg__Angle__FIELDS[] = {
  {
    {dingo_msgs__msg__Angle__FIELD_NAME__theta1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_msgs__msg__Angle__FIELD_NAME__theta2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dingo_msgs__msg__Angle__FIELD_NAME__theta3, 6, 6},
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
dingo_msgs__msg__Angle__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dingo_msgs__msg__Angle__TYPE_NAME, 20, 20},
      {dingo_msgs__msg__Angle__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 theta1\n"
  "float32 theta2\n"
  "float32 theta3";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dingo_msgs__msg__Angle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dingo_msgs__msg__Angle__TYPE_NAME, 20, 20},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 44, 44},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_msgs__msg__Angle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dingo_msgs__msg__Angle__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
