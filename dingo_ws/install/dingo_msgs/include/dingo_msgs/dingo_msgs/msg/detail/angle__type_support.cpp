// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dingo_msgs/msg/detail/angle__functions.h"
#include "dingo_msgs/msg/detail/angle__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dingo_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Angle_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dingo_msgs::msg::Angle(_init);
}

void Angle_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dingo_msgs::msg::Angle *>(message_memory);
  typed_message->~Angle();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Angle_message_member_array[3] = {
  {
    "theta1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_msgs::msg::Angle, theta1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "theta2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_msgs::msg::Angle, theta2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "theta3",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dingo_msgs::msg::Angle, theta3),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Angle_message_members = {
  "dingo_msgs::msg",  // message namespace
  "Angle",  // message name
  3,  // number of fields
  sizeof(dingo_msgs::msg::Angle),
  false,  // has_any_key_member_
  Angle_message_member_array,  // message members
  Angle_init_function,  // function to initialize message memory (memory has to be allocated)
  Angle_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Angle_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Angle_message_members,
  get_message_typesupport_handle_function,
  &dingo_msgs__msg__Angle__get_type_hash,
  &dingo_msgs__msg__Angle__get_type_description,
  &dingo_msgs__msg__Angle__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dingo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dingo_msgs::msg::Angle>()
{
  return &::dingo_msgs::msg::rosidl_typesupport_introspection_cpp::Angle_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dingo_msgs, msg, Angle)() {
  return &::dingo_msgs::msg::rosidl_typesupport_introspection_cpp::Angle_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
