// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/electrical_measurements.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__TRAITS_HPP_
#define DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dingo_msgs/msg/detail/electrical_measurements__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dingo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ElectricalMeasurements & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery_voltage_level
  {
    out << "battery_voltage_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage_level, out);
    out << ", ";
  }

  // member: servo_buck_voltage_level
  {
    out << "servo_buck_voltage_level: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_buck_voltage_level, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ElectricalMeasurements & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_voltage_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage_level, out);
    out << "\n";
  }

  // member: servo_buck_voltage_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_buck_voltage_level: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_buck_voltage_level, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ElectricalMeasurements & msg, bool use_flow_style = false)
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
  const dingo_msgs::msg::ElectricalMeasurements & msg,
  std::ostream & out, size_t indentation = 0)
{
  dingo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dingo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dingo_msgs::msg::ElectricalMeasurements & msg)
{
  return dingo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dingo_msgs::msg::ElectricalMeasurements>()
{
  return "dingo_msgs::msg::ElectricalMeasurements";
}

template<>
inline const char * name<dingo_msgs::msg::ElectricalMeasurements>()
{
  return "dingo_msgs/msg/ElectricalMeasurements";
}

template<>
struct has_fixed_size<dingo_msgs::msg::ElectricalMeasurements>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dingo_msgs::msg::ElectricalMeasurements>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dingo_msgs::msg::ElectricalMeasurements>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__TRAITS_HPP_
