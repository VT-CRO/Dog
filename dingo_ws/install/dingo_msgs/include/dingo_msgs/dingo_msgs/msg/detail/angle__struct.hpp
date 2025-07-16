// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/angle.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_HPP_
#define DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dingo_msgs__msg__Angle __attribute__((deprecated))
#else
# define DEPRECATED__dingo_msgs__msg__Angle __declspec(deprecated)
#endif

namespace dingo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Angle_
{
  using Type = Angle_<ContainerAllocator>;

  explicit Angle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0f;
      this->theta2 = 0.0f;
      this->theta3 = 0.0f;
    }
  }

  explicit Angle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0f;
      this->theta2 = 0.0f;
      this->theta3 = 0.0f;
    }
  }

  // field types and members
  using _theta1_type =
    float;
  _theta1_type theta1;
  using _theta2_type =
    float;
  _theta2_type theta2;
  using _theta3_type =
    float;
  _theta3_type theta3;

  // setters for named parameter idiom
  Type & set__theta1(
    const float & _arg)
  {
    this->theta1 = _arg;
    return *this;
  }
  Type & set__theta2(
    const float & _arg)
  {
    this->theta2 = _arg;
    return *this;
  }
  Type & set__theta3(
    const float & _arg)
  {
    this->theta3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dingo_msgs::msg::Angle_<ContainerAllocator> *;
  using ConstRawPtr =
    const dingo_msgs::msg::Angle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dingo_msgs::msg::Angle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dingo_msgs::msg::Angle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::Angle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::Angle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::Angle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::Angle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dingo_msgs::msg::Angle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dingo_msgs::msg::Angle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dingo_msgs__msg__Angle
    std::shared_ptr<dingo_msgs::msg::Angle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dingo_msgs__msg__Angle
    std::shared_ptr<dingo_msgs::msg::Angle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Angle_ & other) const
  {
    if (this->theta1 != other.theta1) {
      return false;
    }
    if (this->theta2 != other.theta2) {
      return false;
    }
    if (this->theta3 != other.theta3) {
      return false;
    }
    return true;
  }
  bool operator!=(const Angle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Angle_

// alias to use template instance with default allocator
using Angle =
  dingo_msgs::msg::Angle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dingo_msgs

#endif  // DINGO_MSGS__MSG__DETAIL__ANGLE__STRUCT_HPP_
