// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dingo_msgs/msg/detail/electrical_measurements__rosidl_typesupport_introspection_c.h"
#include "dingo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dingo_msgs/msg/detail/electrical_measurements__functions.h"
#include "dingo_msgs/msg/detail/electrical_measurements__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dingo_msgs__msg__ElectricalMeasurements__init(message_memory);
}

void dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_fini_function(void * message_memory)
{
  dingo_msgs__msg__ElectricalMeasurements__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_member_array[2] = {
  {
    "battery_voltage_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_msgs__msg__ElectricalMeasurements, battery_voltage_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_buck_voltage_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_msgs__msg__ElectricalMeasurements, servo_buck_voltage_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_members = {
  "dingo_msgs__msg",  // message namespace
  "ElectricalMeasurements",  // message name
  2,  // number of fields
  sizeof(dingo_msgs__msg__ElectricalMeasurements),
  false,  // has_any_key_member_
  dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_member_array,  // message members
  dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_init_function,  // function to initialize message memory (memory has to be allocated)
  dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_type_support_handle = {
  0,
  &dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_members,
  get_message_typesupport_handle_function,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_hash,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_description,
  &dingo_msgs__msg__ElectricalMeasurements__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dingo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dingo_msgs, msg, ElectricalMeasurements)() {
  if (!dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_type_support_handle.typesupport_identifier) {
    dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dingo_msgs__msg__ElectricalMeasurements__rosidl_typesupport_introspection_c__ElectricalMeasurements_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
