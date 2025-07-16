// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dingo_msgs:msg/JointSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/joint_space.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__TRAITS_HPP_
#define DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dingo_msgs/msg/detail/joint_space__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'fl_foot'
// Member 'fr_foot'
// Member 'rl_foot'
// Member 'rr_foot'
#include "dingo_msgs/msg/detail/angle__traits.hpp"

namespace dingo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointSpace & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: fl_foot
  {
    out << "fl_foot: ";
    to_flow_style_yaml(msg.fl_foot, out);
    out << ", ";
  }

  // member: fr_foot
  {
    out << "fr_foot: ";
    to_flow_style_yaml(msg.fr_foot, out);
    out << ", ";
  }

  // member: rl_foot
  {
    out << "rl_foot: ";
    to_flow_style_yaml(msg.rl_foot, out);
    out << ", ";
  }

  // member: rr_foot
  {
    out << "rr_foot: ";
    to_flow_style_yaml(msg.rr_foot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointSpace & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: fl_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fl_foot:\n";
    to_block_style_yaml(msg.fl_foot, out, indentation + 2);
  }

  // member: fr_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fr_foot:\n";
    to_block_style_yaml(msg.fr_foot, out, indentation + 2);
  }

  // member: rl_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rl_foot:\n";
    to_block_style_yaml(msg.rl_foot, out, indentation + 2);
  }

  // member: rr_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rr_foot:\n";
    to_block_style_yaml(msg.rr_foot, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointSpace & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dingo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dingo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dingo_msgs::msg::JointSpace & msg,
  std::ostream & out, size_t indentation = 0)
{
  dingo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dingo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dingo_msgs::msg::JointSpace & msg)
{
  return dingo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dingo_msgs::msg::JointSpace>()
{
  return "dingo_msgs::msg::JointSpace";
}

template<>
inline const char * name<dingo_msgs::msg::JointSpace>()
{
  return "dingo_msgs/msg/JointSpace";
}

template<>
struct has_fixed_size<dingo_msgs::msg::JointSpace>
  : std::integral_constant<bool, has_fixed_size<dingo_msgs::msg::Angle>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dingo_msgs::msg::JointSpace>
  : std::integral_constant<bool, has_bounded_size<dingo_msgs::msg::Angle>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dingo_msgs::msg::JointSpace>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__TRAITS_HPP_
