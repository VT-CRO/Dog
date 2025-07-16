// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/electrical_measurements.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_HPP_
#define DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dingo_msgs__msg__ElectricalMeasurements __attribute__((deprecated))
#else
# define DEPRECATED__dingo_msgs__msg__ElectricalMeasurements __declspec(deprecated)
#endif

namespace dingo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ElectricalMeasurements_
{
  using Type = ElectricalMeasurements_<ContainerAllocator>;

  explicit ElectricalMeasurements_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_voltage_level = 0.0f;
      this->servo_buck_voltage_level = 0.0f;
    }
  }

  explicit ElectricalMeasurements_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_voltage_level = 0.0f;
      this->servo_buck_voltage_level = 0.0f;
    }
  }

  // field types and members
  using _battery_voltage_level_type =
    float;
  _battery_voltage_level_type battery_voltage_level;
  using _servo_buck_voltage_level_type =
    float;
  _servo_buck_voltage_level_type servo_buck_voltage_level;

  // setters for named parameter idiom
  Type & set__battery_voltage_level(
    const float & _arg)
  {
    this->battery_voltage_level = _arg;
    return *this;
  }
  Type & set__servo_buck_voltage_level(
    const float & _arg)
  {
    this->servo_buck_voltage_level = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> *;
  using ConstRawPtr =
    const dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dingo_msgs__msg__ElectricalMeasurements
    std::shared_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dingo_msgs__msg__ElectricalMeasurements
    std::shared_ptr<dingo_msgs::msg::ElectricalMeasurements_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ElectricalMeasurements_ & other) const
  {
    if (this->battery_voltage_level != other.battery_voltage_level) {
      return false;
    }
    if (this->servo_buck_voltage_level != other.servo_buck_voltage_level) {
      return false;
    }
    return true;
  }
  bool operator!=(const ElectricalMeasurements_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ElectricalMeasurements_

// alias to use template instance with default allocator
using ElectricalMeasurements =
  dingo_msgs::msg::ElectricalMeasurements_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dingo_msgs

#endif  // DINGO_MSGS__MSG__DETAIL__ELECTRICAL_MEASUREMENTS__STRUCT_HPP_
